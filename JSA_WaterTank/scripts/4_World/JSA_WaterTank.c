class JSA_WaterTank_Kit extends Msp_Kit
{
};

// ===== JSON CONFIG =====
// Auto-created at: DayZServer/profiles/JSA_WaterTank/config.json
// Edit the JSON to tweak values, then restart server to apply.

class JSA_WaterTankConfig
{
	float tankCapacity = 1000.0;
	float rainFillRate = 5.0;
	float rainCheckSeconds = 10.0;
	float rainMinIntensity = 0.1;
	float plantWaterRadius = 20.0;
	float plantWaterCostPerSlot = 2.0;
	float plantSlotWaterMax = 200.0;
	float drinkDrainPerTick = 2.0;
	float washDrainPerTick = 3.0;
	float fillBottleDrainAmount = 10.0;

	static ref JSA_WaterTankConfig m_Instance;

	static JSA_WaterTankConfig Get()
	{
		if (!m_Instance)
		{
			m_Instance = new JSA_WaterTankConfig();

			if (GetGame().IsServer())
			{
				string path = "$profile:JSA_WaterTank/config.json";

				if (FileExist(path))
				{
					JsonFileLoader<JSA_WaterTankConfig>.JsonLoadFile(path, m_Instance);
				}
				else
				{
					MakeDirectory("$profile:JSA_WaterTank");
					JsonFileLoader<JSA_WaterTankConfig>.JsonSaveFile(path, m_Instance);
				}
			}
		}
		return m_Instance;
	}
};

// ===== MODDED VANILLA ACTIONS =====

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
			tank.DrainWater(JSA_WaterTankConfig.Get().fillBottleDrainAmount);
			return;
		}

		super.OnFinishProgressServer(action_data);
	}
};

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
			tank.DrainWater(JSA_WaterTankConfig.Get().drinkDrainPerTick);
	}
};

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
			tank.DrainWater(JSA_WaterTankConfig.Get().washDrainPerTick);
	}
};

// ===== WATER CROPS ACTION =====
// Uses same pattern as MuchFramework's ActionMFVSStoreContents (proven to work on Msp_Item)

class ActionWaterCropsFromTank extends ActionInteractBase
{
	void ActionWaterCropsFromTank()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override string GetText()
	{
		return "Water Crops";
	}

	override typename GetInputType()
	{
		return ContinuousInteractActionInput;
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		JSA_WaterTank tank = JSA_WaterTank.Cast(target.GetObject());
		if (!tank || !tank.HasWater())
			return false;
		return true;
	}

	override void OnStartServer(ActionData action_data)
	{
		JSA_WaterTank tank = JSA_WaterTank.Cast(action_data.m_Target.GetObject());
		if (tank)
			tank.JSA_WaterCropsNow();
	}
};

// ===== WATER TANK CLASS =====

class JSA_WaterTank extends Msp_Item
{
	protected float m_JSA_WaterLevel;
	protected bool m_JSA_LoadedFromStorage;

	void JSA_WaterTank()
	{
		RegisterNetSyncVariableFloat("m_JSA_WaterLevel", 0, 10000, 1);
	}

	override void EEInit()
	{
		super.EEInit();

		if (GetGame().IsServer())
		{
			JSA_WaterTankConfig cfg = JSA_WaterTankConfig.Get();

			// Start full when freshly placed (not loaded from storage)
			if (!m_JSA_LoadedFromStorage)
			{
				m_JSA_WaterLevel = cfg.tankCapacity;
				SetSynchDirty();
			}

			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(JSA_RainCheck, cfg.rainCheckSeconds * 1000, true);
		}
	}

	override void EEDelete(EntityAI parent)
	{
		if (GetGame())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove(JSA_RainCheck);
		}
		super.EEDelete(parent);
	}

	// --- Persistence ---
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

		m_JSA_LoadedFromStorage = true;
		return true;
	}

	// --- Water Management ---
	float GetWaterLevel()
	{
		return m_JSA_WaterLevel;
	}

	bool HasWater()
	{
		return m_JSA_WaterLevel > 0;
	}

	void DrainWater(float amount)
	{
		if (!GetGame().IsServer())
			return;

		float cap = JSA_WaterTankConfig.Get().tankCapacity;
		m_JSA_WaterLevel = Math.Clamp(m_JSA_WaterLevel - amount, 0, cap);
		SetSynchDirty();
	}

	void AddWater(float amount)
	{
		if (!GetGame().IsServer())
			return;

		float cap = JSA_WaterTankConfig.Get().tankCapacity;
		float oldLevel = m_JSA_WaterLevel;
		m_JSA_WaterLevel = Math.Clamp(m_JSA_WaterLevel + amount, 0, cap);
		if (m_JSA_WaterLevel != oldLevel)
			SetSynchDirty();
	}

	// --- Rain Fill ---
	void JSA_RainCheck()
	{
		if (!GetGame() || !GetGame().IsServer())
			return;

		JSA_WaterTankConfig cfg = JSA_WaterTankConfig.Get();

		if (m_JSA_WaterLevel >= cfg.tankCapacity)
			return;

		Weather weather = GetGame().GetWeather();
		if (!weather)
			return;

		float rainIntensity = weather.GetRain().GetActual();
		if (rainIntensity > cfg.rainMinIntensity)
		{
			AddWater(cfg.rainFillRate * rainIntensity);
		}
	}

	// --- Water Crops (manual action) ---
	void JSA_WaterCropsNow()
	{
		if (!GetGame() || !GetGame().IsServer())
			return;

		if (m_JSA_WaterLevel <= 0)
			return;

		JSA_WaterTankConfig cfg = JSA_WaterTankConfig.Get();

		array<Object> objects = new array<Object>();
		array<CargoBase> proxyCargos = new array<CargoBase>();
		GetGame().GetObjectsAtPosition(GetPosition(), cfg.plantWaterRadius, objects, proxyCargos);

		Print("[JSA_WaterTank] Water Crops triggered. Found " + objects.Count() + " objects within " + cfg.plantWaterRadius + "m");

		int gardensFound = 0;
		int slotsWatered = 0;

		foreach (Object obj : objects)
		{
			GardenBase garden = GardenBase.Cast(obj);
			if (!garden)
			{
				if (obj.IsKindOf("GardenBase"))
					Print("[JSA_WaterTank] Object " + obj.GetType() + " IsKindOf GardenBase but Cast failed");
				continue;
			}

			gardensFound++;
			Print("[JSA_WaterTank] Found garden: " + garden.GetType() + " with " + garden.GetGardenSlotsCount() + " slots");

			if (m_JSA_WaterLevel <= 0)
				break;

			int slotCount = garden.GetGardenSlotsCount();
			for (int i = 0; i < slotCount; i++)
			{
				Slot slot = garden.GetSlotByIndex(i);
				if (slot)
				{
					float currentWater = slot.GetWater();
					if (currentWater < cfg.plantSlotWaterMax)
					{
						float needed = cfg.plantSlotWaterMax - currentWater;
						slot.GiveWater(needed);
						DrainWater(cfg.plantWaterCostPerSlot);
						slotsWatered++;

						if (m_JSA_WaterLevel <= 0)
							break;
					}
				}
			}
		}

		Print("[JSA_WaterTank] Water Crops done. Gardens: " + gardensFound + ", Slots watered: " + slotsWatered);
	}

	// --- Display ---
	override string GetDisplayName()
	{
		string name = super.GetDisplayName();
		float cap = JSA_WaterTankConfig.Get().tankCapacity;
		int percent = 0;
		if (cap > 0)
			percent = Math.Round((m_JSA_WaterLevel / cap) * 100);
		return name + " [" + percent.ToString() + "%]";
	}

	// --- Standard overrides ---
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
		AddAction(ActionWaterCropsFromTank);
	}
};
