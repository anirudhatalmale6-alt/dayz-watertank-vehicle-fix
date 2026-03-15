class JSA_WaterTank_Kit extends Msp_Kit
{
};

// ===== MODDED VANILLA ACTIONS =====

// Extend vanilla fill bottle to work with our tank + check water level
modded class ActionFillBottleBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		JSA_WaterTank tank = JSA_WaterTank.Cast(targetObject);
		if (tank)
		{
			if (!tank.HasWater())
				return false;
			if (item && !item.IsFullQuantity())
				return true;
			return false;
		}

		return super.ActionCondition(player, target, item);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		Object target = action_data.m_Target.GetObject();
		JSA_WaterTank tank = JSA_WaterTank.Cast(target);
		if (tank && action_data.m_MainItem)
		{
			float fillAmount = action_data.m_MainItem.GetQuantityMax();
			Liquid.FillContainerEnviro(action_data.m_MainItem, LIQUID_WATER, fillAmount);
			tank.DrainWater(fillAmount * 0.5);
			return;
		}

		super.OnFinishProgressServer(action_data);
	}
};

// Only show drink action when tank has water, drain tank while drinking
modded class ActionDrinkWellContinuous
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		JSA_WaterTank tank = JSA_WaterTank.Cast(targetObject);
		if (tank && !tank.HasWater())
			return false;

		return super.ActionCondition(player, target, item);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		Object target = action_data.m_Target.GetObject();
		JSA_WaterTank tank = JSA_WaterTank.Cast(target);
		if (tank)
			tank.DrainWater(2.0);
	}
};

// Only show wash action when tank has water, drain tank while washing
modded class ActionWashHandsWell
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		JSA_WaterTank tank = JSA_WaterTank.Cast(targetObject);
		if (tank && !tank.HasWater())
			return false;

		return super.ActionCondition(player, target, item);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		Object target = action_data.m_Target.GetObject();
		JSA_WaterTank tank = JSA_WaterTank.Cast(target);
		if (tank)
			tank.DrainWater(3.0);
	}
};

// ===== WATER TANK CLASS =====

class JSA_WaterTank extends Msp_Item
{
	// --- Configuration (adjust these values as needed) ---
	static const float JSA_TANK_CAPACITY       = 1000.0;  // Max water (liters)
	static const float JSA_RAIN_FILL_RATE      = 5.0;     // Liters gained per rain tick (scaled by intensity)
	static const float JSA_PLANT_WATER_COST    = 2.0;     // Water used per garden slot watered
	static const float JSA_PLANT_WATER_RADIUS  = 20.0;    // Radius (meters) for auto-watering
	static const float JSA_RAIN_CHECK_SEC      = 10.0;    // Seconds between rain checks
	static const float JSA_PLANT_CHECK_SEC     = 60.0;    // Seconds between plant watering checks
	static const float JSA_SLOT_WATER_MAX      = 200.0;   // Max water per garden slot (vanilla default)

	// --- State ---
	protected float m_JSA_WaterLevel;

	void JSA_WaterTank()
	{
		RegisterNetSyncVariableFloat("m_JSA_WaterLevel", 0, JSA_TANK_CAPACITY, 1);
	}

	override void EEInit()
	{
		super.EEInit();

		if (GetGame().IsServer())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(JSA_RainCheck, JSA_RAIN_CHECK_SEC * 1000, true);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(JSA_WaterPlantsCheck, JSA_PLANT_CHECK_SEC * 1000, true);
		}
	}

	override void EEDelete(EntityAI parent)
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(JSA_RainCheck);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(JSA_WaterPlantsCheck);
		super.EEDelete(parent);
	}

	// --- Persistence across server restarts ---
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(m_JSA_WaterLevel);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;

		if (!ctx.Read(m_JSA_WaterLevel))
			m_JSA_WaterLevel = 0;

		return true;
	}

	// --- Water Management ---
	float GetWaterLevel()
	{
		return m_JSA_WaterLevel;
	}

	float GetWaterCapacity()
	{
		return JSA_TANK_CAPACITY;
	}

	bool HasWater()
	{
		return m_JSA_WaterLevel > 0;
	}

	void DrainWater(float amount)
	{
		if (!GetGame().IsServer())
			return;

		m_JSA_WaterLevel = Math.Clamp(m_JSA_WaterLevel - amount, 0, JSA_TANK_CAPACITY);
		SetSynchDirty();
	}

	void AddWater(float amount)
	{
		if (!GetGame().IsServer())
			return;

		float oldLevel = m_JSA_WaterLevel;
		m_JSA_WaterLevel = Math.Clamp(m_JSA_WaterLevel + amount, 0, JSA_TANK_CAPACITY);
		if (m_JSA_WaterLevel != oldLevel)
			SetSynchDirty();
	}

	// --- Rain Fill ---
	void JSA_RainCheck()
	{
		if (!GetGame().IsServer())
			return;

		if (m_JSA_WaterLevel >= JSA_TANK_CAPACITY)
			return;

		Weather weather = GetGame().GetWeather();
		if (!weather)
			return;

		float rainIntensity = weather.GetRain().GetActual();
		if (rainIntensity > 0.1)
		{
			AddWater(JSA_RAIN_FILL_RATE * rainIntensity);
		}
	}

	// --- Auto-Water Nearby Gardens ---
	void JSA_WaterPlantsCheck()
	{
		if (!GetGame().IsServer())
			return;

		if (m_JSA_WaterLevel <= 0)
			return;

		array<Object> objects = new array<Object>();
		array<CargoBase> proxyCargos = new array<CargoBase>();
		GetGame().GetObjectsAtPosition(GetPosition(), JSA_PLANT_WATER_RADIUS, objects, proxyCargos);

		foreach (Object obj : objects)
		{
			GardenBase garden = GardenBase.Cast(obj);
			if (!garden)
				continue;

			if (m_JSA_WaterLevel <= 0)
				break;

			int slotCount = garden.GetGardenSlotsCount();
			for (int i = 0; i < slotCount; i++)
			{
				Slot slot = garden.GetSlotByIndex(i);
				if (slot)
				{
					float currentWater = slot.GetWaterQuantity();
					if (currentWater < JSA_SLOT_WATER_MAX)
					{
						float needed = JSA_SLOT_WATER_MAX - currentWater;
						slot.GiveWater(needed);
						DrainWater(JSA_PLANT_WATER_COST);

						if (m_JSA_WaterLevel <= 0)
							break;
					}
				}
			}
		}
	}

	// --- Existing overrides ---
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
