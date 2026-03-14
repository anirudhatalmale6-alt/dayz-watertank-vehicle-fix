class JSA_WaterTank_Kit extends Msp_Kit
{
};

// Extend the vanilla fill-bottle action to recognize our custom water tank.
// ActionFillBottleBase is already registered on all vanilla bottles and canteens.
// Its default condition only recognizes vanilla well classes (BuildingSuper).
// This override adds JSA_WaterTank support so players can fill bottles at the tank.
modded class ActionFillBottleBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		if (targetObject && targetObject.IsKindOf("JSA_WaterTank"))
		{
			if (item && !item.IsFullQuantity())
				return true;
			return false;
		}

		return super.ActionCondition(player, target, item);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		Object target = action_data.m_Target.GetObject();
		if (target && target.IsKindOf("JSA_WaterTank") && action_data.m_MainItem)
		{
			Liquid.FillContainerEnviro(action_data.m_MainItem, LIQUID_WATER, action_data.m_MainItem.GetQuantityMax());
			return;
		}

		super.OnFinishProgressServer(action_data);
	}
};

class JSA_WaterTank extends Msp_Item
{
	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override EWaterSourceObjectType GetWaterSourceObjectType()
	{
		return EWaterSourceObjectType.WELL;
	}

	override bool IsWell()
	{
		return true;
	}

	override float GetLiquidThroughputCoef()
	{
		return LIQUID_THROUGHPUT_WELL;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionWashHandsWell);
		AddAction(ActionDrinkWellContinuous);
	}
};
