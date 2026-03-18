class JSA_Base_2F : House
{
    void JSA_Base_2F() {}

    override bool CanPutInCargo(EntityAI parent)    { return false; }
    override bool CanPutIntoHands(EntityAI parent)  { return false; }

    string GetConstructionKitType() { return "JSA_Base_2F_Kit"; }

    override void EEInit()
    {
        super.EEInit();

        if (GetGame().IsServer())
        {
            // ch_bases models have their origin at the CENTER of the building,
            // not at the bottom. When placed at terrain level, the bottom half
            // goes underground. This self-corrects the height on any terrain.

            vector pos = GetPosition();
            float surfaceY = GetGame().SurfaceY(pos[0], pos[2]);

            // Get model bounding box to find where the bottom is
            vector boundingBox[2];
            ClippingInfo(boundingBox);
            // boundingBox[0] = mins, boundingBox[1] = maxs
            // mins[1] is negative for center-origin models (distance below origin to bottom)
            float modelBottomY = pos[1] + boundingBox[0][1];

            Print("[JSA_Base_2F] EEInit pos=" + pos.ToString() + " surfaceY=" + surfaceY + " mins1=" + boundingBox[0][1].ToString() + " bottomY=" + modelBottomY);

            // If the bottom of the building is more than 0.5m below terrain, raise it
            if (modelBottomY < surfaceY - 0.5)
            {
                vector newPos = pos;
                newPos[1] = surfaceY - boundingBox[0][1]; // raise so bottom sits at terrain
                SetPosition(newPos);
                Print("[JSA_Base_2F] Raised to " + newPos.ToString());
            }
        }
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionDismantleJSA_Base2F);
    }
};
