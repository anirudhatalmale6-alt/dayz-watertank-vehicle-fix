class JSA_WaterTank_Kit extends Msp_Kit
{
};

class ActionFillBottleWaterTank extends ActionSingleUseBase
{
	void ActionFillBottleWaterTank()
	{
		m_Text = "#fill";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override typename GetInputType()
	{
		return InteractActionInput;
	}

	override bool HasTarget()
	{
		return true;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!item)
			return false;

		if (item.IsFullQuantity())
			return false;

		Object targetObject = target.GetObject();
		if (!targetObject)
			return false;

		if (!targetObject.IsKindOf("JSA_WaterTank"))
			return false;

		return true;
	}

	override void OnExecuteServer(ActionData action_data)
	{
		if (action_data.m_MainItem)
		{
			Liquid.FillContainerEnviro(action_data.m_MainItem, LIQUID_WATER, action_data.m_MainItem.GetQuantityMax());
		}
	}
};

// Register fill action on bottles/canteens so it appears when holding them near the water tank
modded class Bottle_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionFillBottleWaterTank);
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
		AddAction(ActionFillBottleWaterTank);
	}
};
