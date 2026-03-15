modded class CarScript
{
    protected int JSA_OwnerHash;
    protected int JSA_PrevOwnerHash;
    protected int JSA_DebugCounter;

    void CarScript()
    {
        RegisterNetSyncVariableInt("JSA_OwnerHash");
    }

    override void OnVariablesSynchronized()
    {
        super.OnVariablesSynchronized();

        // Client-side: physically lock/unlock inventory based on access
        if (!GetGame().IsServer())
        {
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (JSA_OwnerHash != 0 && player && !JSA_CanAccessVehicle(player))
            {
                // Lock cargo to physically hide it (bypasses CanDisplayCargo overrides from other mods)
                GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
                Print("[JSA_Vehicle] CLIENT locked inventory for " + GetType() + " (ownerHash=" + JSA_OwnerHash + ")");
            }
            else
            {
                // Unlock if unclaimed or player has access
                if (GetInventory().IsInventoryLockedForLockType(HIDE_INV_FROM_SCRIPT))
                {
                    GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
                    Print("[JSA_Vehicle] CLIENT unlocked inventory for " + GetType());
                }
            }
        }
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
        if (GetGame())
        {
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(JSA_SyncOwnerHash);
        }
        super.EEDelete(parent);
    }

    void JSA_SyncOwnerHash()
    {
        if (!GetGame() || !GetGame().IsServer())
            return;

        int newHash = 0;
        if (m_OwnerSteamID != "" && m_OwnerSteamID != "0")
            newHash = m_OwnerSteamID.Hash();

        // Debug: log on first sync and on changes
        if (JSA_PrevOwnerHash != newHash)
        {
            Print("[JSA_Vehicle] " + GetType() + " owner sync: m_OwnerSteamID=" + m_OwnerSteamID + " claimed=" + m_isVehicleClaimed + " hash=" + newHash);
        }

        // Detect new claim: hash went from 0 to non-0
        if (JSA_PrevOwnerHash == 0 && newHash != 0)
        {
            // Check if the claimant is in a group
            if (!JSA_IsClaimantInGroup(m_OwnerSteamID))
            {
                Print("[JSA_Vehicle] Claim reversed - player " + m_OwnerSteamID + " not in a group");
                // Player is not in a group - reverse the claim
                m_OwnerSteamID = "";
                m_isVehicleClaimed = false;
                m_OwnerGUID = "";
                m_isVehicleLocked = false;
                newHash = 0;
            }
        }

        JSA_PrevOwnerHash = newHash;

        if (newHash != JSA_OwnerHash)
        {
            JSA_OwnerHash = newHash;
            SetSynchDirty();
            Print("[JSA_Vehicle] Hash synced to clients: " + JSA_OwnerHash);
        }
    }

    bool JSA_IsClaimantInGroup(string steamID)
    {
        // Find the online player and check their group
        array<Man> players = new array<Man>();
        GetGame().GetPlayers(players);

        foreach (Man man : players)
        {
            PlayerBase pb = PlayerBase.Cast(man);
            if (pb && pb.GetIdentity() && pb.GetIdentity().GetPlainId() == steamID)
            {
                return pb.GetLBGroup() != null;
            }
        }

        // Player not online, check via group manager
        LBGroup group = LBGroupManager.Get().GetPlayersGroup(steamID);
        return group != null;
    }

    bool JSA_CanAccessVehicle(PlayerBase player)
    {
        // Unclaimed vehicles are accessible to everyone
        if (JSA_OwnerHash == 0)
            return true;

        if (!player)
            return false;

        // Get player Steam ID (try multiple methods for client/server compatibility)
        string playerUID = "";
        if (player.GetIdentity())
            playerUID = player.GetIdentity().GetPlainId();
        if (playerUID == "")
            playerUID = player.GetMySteamId();

        // Owner check
        if (playerUID != "" && playerUID.Hash() == JSA_OwnerHash)
            return true;

        // Admin bypass - server only (LBAdmins may not be available on client)
        if (GetGame().IsServer())
        {
            LBAdmins admins = LBAdmins.Get();
            if (admins && admins.HasPermissionActive("groups.build.enemy", player))
                return true;
        }

        // Group check - is the vehicle owner in my group?
        LBGroup myGroup = player.GetLBGroup();
        if (myGroup && myGroup.members)
        {
            foreach (LBGroupMember member : myGroup.members)
            {
                if (member && member.steamid != "" && member.steamid.Hash() == JSA_OwnerHash)
                    return true;
            }
        }

        return false;
    }

    override bool CanDisplayCargo()
    {
        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (player && !JSA_CanAccessVehicle(player))
        {
            // Debug: log denial periodically (every 100th check to avoid spam)
            JSA_DebugCounter++;
            if (JSA_DebugCounter % 100 == 1)
            {
                string uid = "";
                if (player.GetIdentity())
                    uid = player.GetIdentity().GetPlainId();
                if (uid == "")
                    uid = player.GetMySteamId();
                Print("[JSA_Vehicle] CanDisplayCargo DENIED for " + uid + " on " + GetType() + " (ownerHash=" + JSA_OwnerHash + ")");
            }
            return false;
        }

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
