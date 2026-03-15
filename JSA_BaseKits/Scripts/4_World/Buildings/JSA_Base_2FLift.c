class JSA_Base_2FLift : HouseNoDestruct
{
    void JSA_Base_2FLift() {}

    override bool CanPutInCargo(EntityAI parent)    { return false; }
    override bool CanPutIntoHands(EntityAI parent)  { return false; }

    string GetConstructionKitType() { return "JSA_Base_2FLift_Kit"; }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionDismantleJSA_Base2FLift);
    }
};
