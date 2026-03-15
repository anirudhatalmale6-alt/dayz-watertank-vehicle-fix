class JSA_Base_2F_Kit : ItemBase
{
    ref protected EffectSound m_DeployLoopSound;

    string JSA_Base2FHolo() { return "JSA_Base_2F"; }

    void JSA_Base_2F_Kit()
    {
        RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
    }

    override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
    {
        super.OnPlacementComplete(player, position, orientation);
        if (GetGame().IsServer())
        {
            JSA_Base_2F building = JSA_Base_2F.Cast(GetGame().CreateObjectEx("JSA_Base_2F", position, ECE_PLACE_ON_SURFACE));
            building.SetPosition(position);
            building.SetOrientation(orientation);
            building.Update();
            this.Delete();
        }
        SetIsDeploySound(true);
    }

    override bool IsBasebuildingKit()   { return true; }
    override bool IsDeployable()        { return true; }

    override string GetDeploySoundset()     { return "placeHescoBox_SoundSet"; }
    override string GetLoopDeploySoundset() { return "hescobox_deploy_SoundSet"; }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionTogglePlaceObject);
        AddAction(ActionPlaceObject);
    }
};
