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
            // Delay height correction so model geometry is fully loaded
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CorrectHeight, 500, false);
        }
    }

    void CorrectHeight()
    {
        vector pos = GetPosition();
        float surfaceY = GetGame().SurfaceY(pos[0], pos[2]);

        // Try to get bounding box, use fallback if not available
        float halfHeight = 3.5; // fallback for ch_b_2f_roof_w_n_p
        vector boundingBox[2];
        ClippingInfo(boundingBox);
        if (boundingBox[0][1] < 0)
        {
            halfHeight = -boundingBox[0][1];
        }

        float modelBottomY = pos[1] - halfHeight;

        Print("[JSA_Base_2F] pos=" + pos.ToString() + " surfaceY=" + surfaceY + " halfH=" + halfHeight + " bottomY=" + modelBottomY);

        if (modelBottomY < surfaceY - 0.5)
        {
            vector newPos = pos;
            newPos[1] = surfaceY + halfHeight;
            SetPosition(newPos);
            Print("[JSA_Base_2F] Raised to " + newPos.ToString());
        }
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionDismantleJSA_Base2F);
    }
};
