class JSA_WaterTank_Kit extends Msp_Kit
{
};

// Custom fill action for the water tank
// ActionFillBottleBase doesn't work reliably on Container_Base objects
// because its conditions are designed for BuildingSuper (vanilla wells).
// This creates a simple wrapper that works on our tank.
class ActionFillBottleWaterTank extends ActionContinuousBase
{
	void ActionFillBottleWaterTank()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_FILLBOTTLEWELL;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_LockTargetOnUse = false;
		m_Text = "#fill";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined();
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override bool HasProneException()
	{
		return true;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!item || item.IsFullQuantity())
			return false;

		Object targetObject = target.GetObject();
		if (!targetObject || !targetObject.IsWell())
			return false;

		if (!Liquid.CanFillContainer(item, LIQUID_WATER))
			return false;

		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (action_data.m_MainItem)
		{
			Liquid.FillContainerEnviro(action_data.m_MainItem, LIQUID_WATER, action_data.m_MainItem.GetQuantityMax() * 0.25);
		}
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
