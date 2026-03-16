modded class CarScript
{
    protected int JSA_OwnerHash;
    protected int JSA_PrevOwnerHash;
    protected int JSA_DebugCounter;
    protected string JSA_LastNotifiedSteamID;

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
                GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
            }
            else
            {
                if (GetInventory().IsInventoryLockedForLockType(HIDE_INV_FROM_SCRIPT))
                {
                    GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
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

        // If vehicle is claimed, check if the owner is in a group
        // We do NOT fight HM Vehicle Claim (it re-asserts variables endlessly)
        // Instead: only activate inventory protection when the owner IS in a group
        // Solo claims still "work" in HM's system but provide NO inventory protection
        if (newHash != 0)
        {
            if (!JSA_IsClaimantInGroup(m_OwnerSteamID))
            {
                // Owner is NOT in a group — do NOT sync hash to clients
                // This means JSA_OwnerHash stays 0 on clients = no inventory restriction
                // The vehicle appears "claimed" in HM but cargo is accessible to everyone

                // Notify the player once that they need a group for inventory protection
                if (m_OwnerSteamID != JSA_LastNotifiedSteamID)
                {
                    JSA_LastNotifiedSteamID = m_OwnerSteamID;
                    JSA_NotifyNoGroup(m_OwnerSteamID);
                    Print("[JSA_Vehicle] " + GetType() + " claimed by " + m_OwnerSteamID + " but NOT in group — inventory protection disabled");
                }

                newHash = 0; // Don't sync to clients
            }
            else
            {
                // Owner IS in a group — full inventory protection active
                JSA_LastNotifiedSteamID = "";

                if (JSA_PrevOwnerHash != newHash)
                    Print("[JSA_Vehicle] " + GetType() + " claimed by " + m_OwnerSteamID + " (in group) — inventory protection active, hash=" + newHash);
            }
        }
        else
        {
            // Vehicle unclaimed
            if (JSA_PrevOwnerHash != 0)
                Print("[JSA_Vehicle] " + GetType() + " unclaimed");
            JSA_LastNotifiedSteamID = "";
        }

        JSA_PrevOwnerHash = newHash;

        if (newHash != JSA_OwnerHash)
        {
            JSA_OwnerHash = newHash;
            SetSynchDirty();
        }
    }

    void JSA_NotifyNoGroup(string steamID)
    {
        array<Man> allPlayers = new array<Man>();
        GetGame().GetPlayers(allPlayers);

        foreach (Man man : allPlayers)
        {
            PlayerBase pb = PlayerBase.Cast(man);
            if (pb && pb.GetIdentity() && pb.GetIdentity().GetPlainId() == steamID)
            {
                // Action message RPC (center screen) - same method MuchFramework uses
                // Important: first param must be the PLAYER, not the vehicle
                Param1<string> msgParam = new Param1<string>("You need to be in a group for vehicle inventory protection!");
                GetGame().RPCSingleParam(pb, ERPCs.RPC_USER_ACTION_MESSAGE, msgParam, true, pb.GetIdentity());

                Print("[JSA_Vehicle] Sent no-group notification to " + steamID);
                break;
            }
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
        // Unclaimed or unprotected vehicles are accessible to everyone
        if (JSA_OwnerHash == 0)
            return true;

        if (!player)
            return false;

        // Get player Steam ID
        string playerUID = "";
        if (player.GetIdentity())
            playerUID = player.GetIdentity().GetPlainId();
        if (playerUID == "")
            playerUID = player.GetMySteamId();

        // Owner check
        if (playerUID != "" && playerUID.Hash() == JSA_OwnerHash)
            return true;

        // Admin bypass - server only
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
