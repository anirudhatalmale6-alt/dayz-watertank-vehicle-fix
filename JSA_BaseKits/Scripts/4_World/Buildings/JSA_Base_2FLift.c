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

            vector boundingBox[2];
            ClippingInfo(boundingBox);
            // boundingBox[0] = mins, boundingBox[1] = maxs
            float modelBottomY = pos[1] + boundingBox[0][1];

            Print("[JSA_Base_2FLift] EEInit pos=" + pos.ToString() + " surfaceY=" + surfaceY + " mins1=" + boundingBox[0][1].ToString() + " bottomY=" + modelBottomY);

            if (modelBottomY < surfaceY - 0.5)
            {
                vector newPos = pos;
                newPos[1] = surfaceY - boundingBox[0][1];
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
