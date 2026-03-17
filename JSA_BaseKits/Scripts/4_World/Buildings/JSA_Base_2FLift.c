class JSA_Base_2FLift : House
{
    void JSA_Base_2FLift() {}

    override bool CanPutInCargo(EntityAI parent)    { return false; }
    override bool CanPutIntoHands(EntityAI parent)  { return false; }

    string GetConstructionKitType() { return "JSA_Base_2FLift_Kit"; }

    override void EEInit()
    {
        super.EEInit();

        if (GetGame().IsServer())
        {
            vector pos = GetPosition();
            float surfaceY = GetGame().SurfaceY(pos[0], pos[2]);

            vector mins, maxs;
            ClippingInfo(mins, maxs);

            float modelBottomY = pos[1] + mins[1];

            Print("[JSA_Base_2FLift] EEInit pos=" + pos.ToString() + " surfaceY=" + surfaceY + " mins[1]=" + mins[1] + " bottomY=" + modelBottomY);

            if (modelBottomY < surfaceY - 0.5)
            {
                vector newPos = pos;
                newPos[1] = surfaceY - mins[1];
                SetPosition(newPos);
                Print("[JSA_Base_2FLift] Raised to " + newPos.ToString());
            }
        }
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionDismantleJSA_Base2FLift);
    }
};
