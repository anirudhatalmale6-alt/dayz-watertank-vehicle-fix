modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(ActionDismantleJSA_Base2F);
        actions.Insert(ActionDismantleJSA_Base2FLift);
    }
};
