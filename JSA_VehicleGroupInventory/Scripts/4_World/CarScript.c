modded class CarScript
{
    // Synced copy of HM Vehicle Claim's owner Steam ID
    protected string JSA_OwnerUID;
    protected float JSA_SyncTimer;

    void CarScript()
    {
        RegisterNetSyncVariableString("JSA_OwnerUID", 0, 30);
    }

    // Server-side: mirror HM's owner ID into our synced variable every 3 seconds
    override void EOnFrame(IEntity other, float timeSlice)
    {
        super.EOnFrame(other, timeSlice);

        #ifdef SERVER
        JSA_SyncTimer += timeSlice;
        if (JSA_SyncTimer >= 3.0)
        {
            JSA_SyncTimer = 0;

            // --- FIX: Access HM Vehicle Claim's owner variable safely ---
            // HM Vehicle Claim adds OwnerSteamID to CarScript.
            // If the variable name is different in your HM version, update it here.
            string current = OwnerSteamID;
            if (current != JSA_OwnerUID)
            {
                JSA_OwnerUID = current;
                SetSynchDirty();
            }
        }
        #endif
    }

    bool JSA_IsVehicleClaimed()
    {
        return JSA_OwnerUID != "" && JSA_OwnerUID != "0";
    }

    bool JSA_CanAccessVehicle(PlayerBase player)
    {
        // Unclaimed vehicles are accessible to everyone
        if (!JSA_IsVehicleClaimed())
            return true;

        if (!player)
            return false;

        PlayerIdentity identity = player.GetIdentity();
        if (!identity)
            return false;

        string playerUID = identity.GetId();

        // Owner always has access
        if (playerUID == JSA_OwnerUID)
            return true;

        // --- FIX: Use correct LBMaster API ---
        // Old (broken): LBMasterModule.GetInstance() -> does not exist
        // Correct API:  LBGroupManager.Get() for group lookups
        //               LBAdmins.HasPermission() for permission checks
        //               player.GetLBGroup() for online player's group

        // Admin bypass - check if player has admin override permission
        if (LBAdmins.HasPermission("groups.build.enemy", identity))
            return true;

        // Check if the player and the vehicle owner are in the same LBMaster group
        // GetPlayersGroup works for both online and offline players by Steam ID
        LBGroup ownerGroup = LBGroupManager.Get().GetPlayersGroup(JSA_OwnerUID);
        if (ownerGroup)
        {
            // For the current player, use GetLBGroup() which works on client side
            LBGroup playerGroup = player.GetLBGroup();
            if (playerGroup && playerGroup == ownerGroup)
                return true;
        }

        return false;
    }

    // --- Client-side: Hide cargo from non-group players ---
    override bool CanDisplayCargo()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanDisplayCargo();
    }

    // --- Client-side: Hide attachment slots from non-group players ---
    override bool CanDisplayAttachmentSlot(int slot_id)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanDisplayAttachmentSlot(slot_id);
    }

    // --- Prevent non-group players from removing attachments ---
    override bool CanReleaseAttachment(EntityAI attachment)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReleaseAttachment(attachment);
    }

    // --- Server-side: Prevent non-group players from putting items in ---
    override bool CanReceiveItemIntoCargo(EntityAI item)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReceiveItemIntoCargo(item);
    }

    // --- Server-side: Prevent non-group players from attaching items ---
    override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReceiveAttachment(attachment, slotId);
    }
};
