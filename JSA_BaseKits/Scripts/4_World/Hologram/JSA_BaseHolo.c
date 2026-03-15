modded class Hologram
{
    override string ProjectionBasedOnParent()
    {
        // 2F Roof Kit
        JSA_Base_2F_Kit roof_kit = JSA_Base_2F_Kit.Cast(m_Player.GetHumanInventory().GetEntityInHands());
        if (roof_kit)
            return roof_kit.JSA_Base2FHolo();

        // 2F Lift Kit
        JSA_Base_2FLift_Kit lift_kit = JSA_Base_2FLift_Kit.Cast(m_Player.GetHumanInventory().GetEntityInHands());
        if (lift_kit)
            return lift_kit.JSA_Base2FLiftHolo();

        return super.ProjectionBasedOnParent();
    }

    override void EvaluateCollision(ItemBase action_item = null)
    {
        ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
        if (item_in_hands)
        {
            if (item_in_hands.IsInherited(JSA_Base_2F_Kit) || item_in_hands.IsInherited(JSA_Base_2FLift_Kit))
            {
                SetIsColliding(false);
                return;
            }
        }
        super.EvaluateCollision();
    }
};
