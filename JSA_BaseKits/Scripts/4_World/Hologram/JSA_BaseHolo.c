modded class Hologram
{
	override string ProjectionBasedOnParent()
	{
		JSA_Base_2F_Kit kit2f = JSA_Base_2F_Kit.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if (kit2f)
		{
			return kit2f.GetBuildingClass();
		}

		JSA_Base_2FLift_Kit kit2fl = JSA_Base_2FLift_Kit.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		if (kit2fl)
		{
			return kit2fl.GetBuildingClass();
		}

		return super.ProjectionBasedOnParent();
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());

		if (item_in_hands && (item_in_hands.IsInherited(JSA_Base_2F_Kit) || item_in_hands.IsInherited(JSA_Base_2FLift_Kit)))
		{
			SetIsColliding(false);
			return;
		}

		super.EvaluateCollision();
	}
};
