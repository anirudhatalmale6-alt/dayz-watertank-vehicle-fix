modded class CarScript
{
    // HM Vehicle Claim already adds 'string OwnerSteamID' to CarScript
    // and syncs it to all clients. We just read it directly.

    bool JSA_IsVehicleClaimed()
    {
        return OwnerSteamID != "" && OwnerSteamID != "0";
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
        if (playerUID == OwnerSteamID)
            return true;

        // Admin bypass - LBAdmins.Get().HasPermission()
        if (LBAdmins.Get().HasPermission("groups.build.enemy", identity))
            return true;

        // Check if the player and the vehicle owner are in the same LBMaster group
        LBGroup ownerGroup = LBGroupManager.Get().GetPlayersGroup(OwnerSteamID);
        if (ownerGroup)
        {
            LBGroup playerGroup = player.GetLBGroup();
            if (playerGroup && playerGroup == ownerGroup)
                return true;
        }

        return false;
    }

    // Client-side: Hide cargo from non-group players
    override bool CanDisplayCargo()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanDisplayCargo();
    }

    // Client-side: Hide attachment slots from non-group players
    override bool CanDisplayAttachmentSlot(int slot_id)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanDisplayAttachmentSlot(slot_id);
    }

    // Prevent non-group players from removing attachments
    override bool CanReleaseAttachment(EntityAI attachment)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReleaseAttachment(attachment);
    }

    // Prevent non-group players from putting items in
    override bool CanReceiveItemIntoCargo(EntityAI item)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReceiveItemIntoCargo(item);
    }

    // Prevent non-group players from attaching items
    override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReceiveAttachment(attachment, slotId);
    }
};
