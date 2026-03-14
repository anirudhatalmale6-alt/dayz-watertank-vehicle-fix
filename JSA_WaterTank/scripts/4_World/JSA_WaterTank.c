class JSA_WaterTank_Kit extends Msp_Kit
{
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

	// --- FIX 1: Override GetWaterSourceObjectType ---
	// ActionFillBottleBase checks: GetWaterSourceObjectType() != EWaterSourceObjectType.NONE
	// ActionWashHandsWell checks:  GetWaterSourceObjectType() != EWaterSourceObjectType.NONE || IsWell()
	// Without this override, the default returns NONE and fill/wash actions never activate.
	override EWaterSourceObjectType GetWaterSourceObjectType()
	{
		return EWaterSourceObjectType.WELL;
	}

	// --- FIX 2: IsWell() now derived from GetWaterSourceObjectType ---
	// This matches the vanilla Well class pattern
	override bool IsWell()
	{
		return true;
	}

	// --- FIX 3: GetLiquidThroughputCoef for fill speed ---
	override float GetLiquidThroughputCoef()
	{
		return LIQUID_THROUGHPUT_WELL;
	}

	override void SetActions()
	{
		super.SetActions();

		// --- FIX 4: Correct action class names ---
		// ActionWashHandsWellOne does not exist in vanilla DayZ - it's ActionWashHandsWell
		AddAction(ActionWashHandsWell);
		AddAction(ActionDrinkWellContinuous);
		AddAction(ActionFillBottleBase);
	}
};
