modded class CarScript
{
    // Hash of owner's steam ID, synced to clients via network variable.
    // We use a hash (int) because RegisterNetSyncVariableString is not
    // available on CarScript, and m_OwnerSteamID from HM may not be
    // synced to clients.
    protected int JSA_OwnerHash;

    void CarScript()
    {
        RegisterNetSyncVariableInt("JSA_OwnerHash");
    }

    override void EEInit()
    {
        super.EEInit();

        if (GetGame().IsServer())
        {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(JSA_SyncOwnerHash, 2000, true);
        }
    }

    override void EEDelete(EntityAI parent)
    {
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(JSA_SyncOwnerHash);
        super.EEDelete(parent);
    }

    void JSA_SyncOwnerHash()
    {
        if (!GetGame().IsServer())
            return;

        int newHash = 0;
        if (m_OwnerSteamID != "" && m_OwnerSteamID != "0")
            newHash = m_OwnerSteamID.Hash();

        if (newHash != JSA_OwnerHash)
        {
            JSA_OwnerHash = newHash;
            SetSynchDirty();
        }
    }

    bool JSA_CanAccessVehicle(PlayerBase player)
    {
        // Unclaimed vehicles are accessible to everyone
        if (JSA_OwnerHash == 0)
            return true;

        if (!player)
            return false;

        // Admin bypass
        if (LBAdmins.Get().HasPermissionActive("groups.build.enemy", player))
            return true;

        // Owner check
        string playerUID = player.GetMySteamId();
        if (playerUID != "" && playerUID.Hash() == JSA_OwnerHash)
            return true;

        // Group check - is the vehicle owner in my group?
        LBGroup myGroup = player.GetLBGroup();
        if (myGroup)
        {
            foreach (LBGroupMember member : myGroup.members)
            {
                if (member && member.steamid.Hash() == JSA_OwnerHash)
                    return true;
            }
        }

        return false;
    }

    override bool CanDisplayCargo()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanDisplayCargo();
    }

    override bool CanDisplayAttachmentSlot(int slot_id)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanDisplayAttachmentSlot(slot_id);
    }

    override bool CanReleaseAttachment(EntityAI attachment)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReleaseAttachment(attachment);
    }

    override bool CanReceiveItemIntoCargo(EntityAI item)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReceiveItemIntoCargo(item);
    }

    override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
            return false;

        return super.CanReceiveAttachment(attachment, slotId);
    }
};
