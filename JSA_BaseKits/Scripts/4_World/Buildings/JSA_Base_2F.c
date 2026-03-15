class JSA_Base_2F : HouseNoDestruct
{
    void JSA_Base_2F() {}

    override bool CanPutInCargo(EntityAI parent)    { return false; }
    override bool CanPutIntoHands(EntityAI parent)  { return false; }

    string GetConstructionKitType() { return "JSA_Base_2F_Kit"; }

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionDismantleJSA_Base2F);
    }
};
