class M3_G80 extends CCPoliceVehicleBase
{
	protected ref UniversalTemperatureSource m_UTSource;
	protected ref UniversalTemperatureSourceSettings m_UTSSettings;
	protected ref UniversalTemperatureSourceLambdaEngine m_UTSLEngine;
	
	void M3_G80()
	{

		m_EngineStartOK = "M3_G80_Engine_start_SoundSet";
		m_EngineStartBattery = "offroad_engine_failed_start_battery_SoundSet";
		m_EngineStartPlug = "offroad_engine_failed_start_sparkplugs_SoundSet";
		m_EngineStartFuel = "M3_G80_engine_ext_failed_start_SoundSet";
		m_EngineStopFuel = "M3_G80_engine_ext_stop_SoundSet";

		m_CarDoorOpenSound 		= "offroad_door_open_SoundSet";
		m_CarDoorCloseSound 	= "offroad_door_close_SoundSet";
		
		m_CarHornShortSoundName = "Offroad_Horn_Short_SoundSet";
		m_CarHornLongSoundName	= "Offroad_Horn_SoundSet";
		m_dmgContactCoef = 0.060;
		
	}
	
	override bool IsPoliceModel()
	{
		return GetModelName().Contains("M3_G80_un");
	}
	
	override vector GetBlueLightPosition()
	{		
		return "-0.689 0.836 2.638"; // example
	}
		
	override vector GetBlueLightPositionRear()
	{		
		return "-0.689 0.836 -2.638"; // example
	}
	
	override vector GetRedLightPosition()
	{
		return "0.689 0.836 2.638";	
	}
	override vector GetRedLightPositionRear()
	{
		return "0.689 0.836 -2.638";	
	}
	override vector GetBlueLightOrientation() 
	{
		return "0 0 0"; 
	}
	override vector GetBlueLightOrientationRear() 
	{
		return "180 0 0"; 
	}
	override vector GetRedLightOrientation() 
	{ 
		return "0 0 0"; 
	}
	override vector GetRedLightOrientationRear() 
	{ 
		return "180 0 0"; 
	}
	override string GetRedMaterialPath(string suffix)
	{
		return "M3_G80\\data\\policelights\\lightbar_main_" + suffix + ".rvmat";
	}

	override string GetBlueMaterialPath(string suffix)
	{
		return "M3_G80\\data\\policelights\\lightbar_main_" + suffix + ".rvmat";
	}

	override protected string GetRedSelectionName() 
	{ 
		return "lightbar_red"; 
	}
	override protected string GetBlueSelectionName() 
	{ 
		return "lightbar_blue"; 
	}
	
	override void EEInit()
	{		
		super.EEInit();
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
 			m_UTSSettings 					= new UniversalTemperatureSourceSettings();
			m_UTSSettings.m_ManualUpdate 	= true;
			m_UTSSettings.m_TemperatureMin	= 0;
			m_UTSSettings.m_TemperatureMax	= 30;
			m_UTSSettings.m_RangeFull		= 0.5;
			m_UTSSettings.m_RangeMax		= 2;
			m_UTSSettings.m_TemperatureCap	= 25;
			
			m_UTSLEngine					= new UniversalTemperatureSourceLambdaEngine();
			m_UTSource						= new UniversalTemperatureSource(this, m_UTSSettings, m_UTSLEngine);
		}		
	}
	override void OnEngineStart()
	{
		super.OnEngineStart();

		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.SetDefferedActive(true, 20.0);
		}
	}
	
	override void OnEngineStop()
	{
		super.OnEngineStop();

		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.SetDefferedActive(false, 10.0);
		}
	}
	
	// CAMERA //
    override float GetTransportCameraDistance()
    {
        return 6.5;
    }

    override vector GetTransportCameraOffset()
    {
        return "0.0 1.7 0.0";
    } 
    // CAMERA END//

	override int GetAnimInstance()
	{
		return VehicleAnimInstances.SEDAN;
	}

	override int GetSeatAnimationType( int posIdx )
	{
		switch( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		}

		return 0;
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
				
		if ( GetCrashHeavySound() )
			PlayCrashHeavySound();
		else if ( GetCrashLightSound() )
			PlayCrashLightSound();
		
		UpdateLights();
	}
	override void EEItemAttached ( EntityAI item, string slot_name ) 
	{
		super.EEItemAttached( item, slot_name );
		if ( GetGame().IsServer() )
		{
			if ( slot_name == "Reflector_1_1" )
				SetHealth( "Reflector_1_1", "Health", item.GetHealth() );

			if ( slot_name == "Reflector_2_1" )
				SetHealth( "Reflector_2_1", "Health", item.GetHealth() );

			if ( slot_name == "CarBattery" )
				m_BatteryHealth = item.GetHealth01();
						
			if ( slot_name == "SparkPlug" )
				m_PlugHealth = item.GetHealth01();
			
			Synchronize();
		}
		UpdateHeadlightState();
		UpdateLights();
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		if ( GetGame().IsServer() )
		{
			//int slot_id = InventorySlots.GetSlotIdFromString(slot_name);
			if ( IsScriptedLightsOn() )
			{
				if ( slot_name == "CarBattery" || slot_name == "SparkPlug" )
				{
					ToggleHeadlights();
				}
			}

			if ( EngineIsOn() )
			{
				if ( slot_name == "SparkPlug" || slot_name == "CarBattery" )
					EngineStop();
			}
			
			if ( slot_name == "CarBattery" )
				m_BatteryHealth = -1;

			if ( slot_name == "SparkPlug" )
				m_PlugHealth = -1;

			if ( slot_name == "CarRadiator" )
			{
				LeakAll( CarFluid.COOLANT );
				SetHealth( "Radiator", "Health", 0);
			}

			Synchronize();
		}
		
		UpdateHeadlightState();
		UpdateLights();

	}
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast( ScriptedLightBase.CreateLight(M3_G80FrontLight) );
	}
	
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast( ScriptedLightBase.CreateLight(M3_G80RearLight) );
	}
	
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		
		string attType = attachment.GetType();
		
		if ( EngineIsOn() || GetCarDoorsState("M3_G80_hood") == CarDoorState.DOORS_CLOSED )
		{
			if ( attType == "CarRadiator" || attType == "SparkPlug" || attType == "CarBattery")
				return false;
		}
		if ( GetCarDoorsState("M3_G80_trunk") == CarDoorState.DOORS_CLOSED )
		{
			if (attType == "M3_G80Wheel_offroad_1_1" || attType == "M3_G80Wheel_offroad_1_2"  || attType == "M3_G80Wheel_offroad_2_1" || attType == "M3_G80Wheel_offroad_2_2")
				return false;
		}

		return true;
	}
	
	override bool CanDisplayAttachmentCategory( string category_name )
	{

		category_name.ToLower();
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if ( category_name.Contains( "Engine" ) )
		{
			if ( GetCarDoorsState("M3_G80_hood") == CarDoorState.DOORS_CLOSED )
				return false;
		}
				
		return true;
	}
	
	override bool CanDisplayCargo()
	{
		if ( !super.CanDisplayCargo() )
			return false;
		
		if ( GetCarDoorsState("M3_G80_trunk") == CarDoorState.DOORS_CLOSED )
			return false;
		
		return true;
	}
	
	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor )
			return CarDoorState.DOORS_MISSING;
	
		switch( slotType )
		{
			case "M3_G80_driver":
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "M3_G80_codriver":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "M3_G80_cargo1":
				if ( GetAnimationPhase("DoorsCargo1") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "M3_G80_cargo2":
				if ( GetAnimationPhase("DoorsCargo2") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
			
			case "M3_G80_trunk":
				if ( GetAnimationPhase("DoorsTrunk") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "M3_G80_hood":
				if ( GetAnimationPhase("DoorsHood") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
		}

		return CarDoorState.DOORS_MISSING;
	}
	

	override bool CrewCanGetThrough( int posIdx )
	{
		switch( posIdx )
		{
			case 0:
				if ( GetCarDoorsState( "M3_G80_driver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 1:
				if ( GetCarDoorsState( "M3_G80_codriver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 2:
				if ( GetCarDoorsState( "M3_G80_cargo1" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 3:
				if ( GetCarDoorsState( "M3_G80_cargo2" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
		}

		return false;
	}

	override string GetDoorSelectionNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "doors_driver";
		break;
		case 1:
			return "doors_codriver";
		break;
		case 2:
			return "doors_cargo1";
		break;
		case 3:
			return "doors_cargo2";
		break;
		}
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}
	bool IsVitalKeys_M3_G80()
	{
		return true;
	}
	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "M3_G80_driver";
		break;
		case 1:
			return "M3_G80_codriver";
		break;
		case 2:
			return "M3_G80_cargo1";
		break;
		case 3:
			return "M3_G80_cargo2";
		break;
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}

	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 1;
				
				//-----
				if ( GetCarDoorsState( "M3_G80_driver" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "M3_G80_codriver" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetCarDoorsState( "M3_G80_cargo1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "M3_G80_cargo2" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetHealthLevel( "WindowFront") == GameConstants.STATE_RUINED )
					newValue -= 0.6;

				//-----
				if ( GetHealthLevel( "WindowBack") == GameConstants.STATE_RUINED )
					newValue -= 0.6;
			
				if ( newValue > 1 )
					newValue = 1;
			
				if ( newValue < 0 )
					newValue = 0;
			
				return newValue;
			break;
		}

		return oldValue;
	}

	override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_cargo1":
			return "DoorsCargo1";
		case "doors_cargo2":
			return "DoorsCargo2";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";
		}

		return "";
	}

	override bool IsVitalTruckBattery()
	{
		return false;
	}

	override bool IsVitalGlowPlug()
	{
		return false;
	}
	
	override bool CanReachSeatFromSeat( int currentSeat, int nextSeat )
	{
		switch( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 )
				return true;
			break;
		case 1:
			if ( nextSeat == 0 )
				return true;
			break;
		case 2:
			if ( nextSeat == 3 )
				return true;
			break;
		case 3:
			if ( nextSeat == 2 )
				return true;
			break;
		}
		
		return false;
	}

	override bool CanReachDoorsFromSeat( string pDoorsSelection, int pCurrentSeat )
	{
		switch( pCurrentSeat )
		{
		case 0:
			if (pDoorsSelection == "DoorsDriver")
			{
				return true;
			}
		break;
		case 1:
			if (pDoorsSelection == "DoorsCoDriver")
			{
				return true;
			}
		break;
		case 2:
			if (pDoorsSelection == "DoorsCargo1")
			{
				return true;
			}
		break;
		case 3:
			if (pDoorsSelection == "DoorsCargo2")
			{
				return true;
			}
		break;
		}
		
		return false;		
	}

	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{

			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "M3_G80_codriver" );
			entity.GetInventory().CreateInInventory( "M3_G80_driver" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo1" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo2" );
			entity.GetInventory().CreateInInventory( "M3_G80_hood" );
			entity.GetInventory().CreateInInventory( "M3_G80_trunk" );
			
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		};

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
	
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAnimateSeats);
	}
}

class M3_G80_Blue extends M3_G80
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "M3_G80_codriver_Blue" );
			entity.GetInventory().CreateInInventory( "M3_G80_driver_Blue" );
			entity.GetInventory().CreateInInventory( "M3_G80_hood_Blue" );
			entity.GetInventory().CreateInInventory( "M3_G80_trunk_Blue" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo1_Blue" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo2_Blue" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class M3_G80_Red extends M3_G80
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "M3_G80_codriver_Red" );
			entity.GetInventory().CreateInInventory( "M3_G80_driver_Red" );
			entity.GetInventory().CreateInInventory( "M3_G80_hood_Red" );
			entity.GetInventory().CreateInInventory( "M3_G80_trunk_Red" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo1_Red" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo2_Red" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class M3_G80_yellow extends M3_G80
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "M3_G80_codriver_yellow" );
			entity.GetInventory().CreateInInventory( "M3_G80_driver_yellow" );
			entity.GetInventory().CreateInInventory( "M3_G80_hood_yellow" );
			entity.GetInventory().CreateInInventory( "M3_G80_trunk_yellow" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo1_yellow" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo2_yellow" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class M3_G80_white extends M3_G80
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "M3_G80_codriver_white" );
			entity.GetInventory().CreateInInventory( "M3_G80_driver_white" );
			entity.GetInventory().CreateInInventory( "M3_G80_hood_white" );
			entity.GetInventory().CreateInInventory( "M3_G80_trunk_white" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo1_white" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo2_white" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class M3_G80_un extends M3_G80
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "M3_G80_codriver" );
			entity.GetInventory().CreateInInventory( "M3_G80_driver" );
			entity.GetInventory().CreateInInventory( "M3_G80_hood" );
			entity.GetInventory().CreateInInventory( "M3_G80_trunk" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo1" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo2" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};

class M3_G80_Police extends CCfullPoliceVehicleBase
{
	protected ref UniversalTemperatureSource m_UTSource;
	protected ref UniversalTemperatureSourceSettings m_UTSSettings;
	protected ref UniversalTemperatureSourceLambdaEngine m_UTSLEngine;
	void M3_G80_Police()
	{

		m_EngineStartOK = "M3_G80_Engine_start_SoundSet";
		m_EngineStartBattery = "offroad_engine_failed_start_battery_SoundSet";
		m_EngineStartPlug = "offroad_engine_failed_start_sparkplugs_SoundSet";
		m_EngineStartFuel = "M3_G80_engine_ext_failed_start_SoundSet";
		m_EngineStopFuel = "M3_G80_engine_ext_stop_SoundSet";

		m_CarDoorOpenSound 		= "offroad_door_open_SoundSet";
		m_CarDoorCloseSound 	= "offroad_door_close_SoundSet";
		
		m_CarHornShortSoundName = "Offroad_Horn_Short_SoundSet";
		m_CarHornLongSoundName	= "Offroad_Horn_SoundSet";
		m_dmgContactCoef = 0.060;
		
	}
	
	override bool IsPoliceModel()
	{
		return GetModelName().Contains("M3_G80_Police");
	}
	
	override vector GetBlueLightPosition()
	{		
		return "-0.689 0.836 2.638"; // example
	}
		
	override vector GetBlueLightPositionRear()
	{		
		return "-0.689 0.836 -2.638"; // example
	}
	
	override vector GetRedLightPosition()
	{
		return "0.689 0.836 2.638";	
	}
	override vector GetRedLightPositionRear()
	{
		return "0.689 0.836 -2.638";	
	}
	override vector GetBlueLightOrientation() 
	{
		return "0 0 0"; 
	}
	override vector GetBlueLightOrientationRear() 
	{
		return "180 0 0"; 
	}
	override vector GetRedLightOrientation() 
	{ 
		return "0 0 0"; 
	}
	override vector GetRedLightOrientationRear() 
	{ 
		return "180 0 0"; 
	}
	override string GetRedMaterialPath(string suffix)
	{
		return "M3_G80\\data\\policelights\\lightbar_main_" + suffix + ".rvmat";
	}

	override string GetBlueMaterialPath(string suffix)
	{
		return "M3_G80\\data\\policelights\\lightbar_main_" + suffix + ".rvmat";
	}

	override protected vector GetSideLeftLightPosition()  { return "-1.00 1.535 0.00"; }
	override protected vector GetSideLeftLightOrientation(){ return "-90 0 0"; }
	override protected vector GetSideRightLightPosition() { return "1.00 1.535 0.00"; }
	override protected vector GetSideRightLightOrientation(){ return "90 0 0"; }

	override protected string GetRedSelectionName() 
	{ 
		return "lightbar_red"; 
	}
	override protected string GetBlueSelectionName() 
	{ 
		return "lightbar_blue"; 
	}
	
	override void EEInit()
	{		
		super.EEInit();
		
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
 			m_UTSSettings 					= new UniversalTemperatureSourceSettings();
			m_UTSSettings.m_ManualUpdate 	= true;
			m_UTSSettings.m_TemperatureMin	= 0;
			m_UTSSettings.m_TemperatureMax	= 30;
			m_UTSSettings.m_RangeFull		= 0.5;
			m_UTSSettings.m_RangeMax		= 2;
			m_UTSSettings.m_TemperatureCap	= 25;
			
			m_UTSLEngine					= new UniversalTemperatureSourceLambdaEngine();
			m_UTSource						= new UniversalTemperatureSource(this, m_UTSSettings, m_UTSLEngine);
		}		
	}
	override void OnEngineStart()
	{
		super.OnEngineStart();

		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.SetDefferedActive(true, 20.0);
		}
	}
	
	override void OnEngineStop()
	{
		super.OnEngineStop();

		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			m_UTSource.SetDefferedActive(false, 10.0);
		}
	}
	
	// CAMERA //
    override float GetTransportCameraDistance()
    {
        return 6.5;
    }

    override vector GetTransportCameraOffset()
    {
        return "0.0 1.7 0.0";
    } 
    // CAMERA END//

	override int GetAnimInstance()
	{
		return VehicleAnimInstances.SEDAN;
	}

	override int GetSeatAnimationType( int posIdx )
	{
		switch( posIdx )
		{
		case 0:
			return DayZPlayerConstants.VEHICLESEAT_DRIVER;
		case 1:
			return DayZPlayerConstants.VEHICLESEAT_CODRIVER;
		case 2:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_L;
		case 3:
			return DayZPlayerConstants.VEHICLESEAT_PASSENGER_R;
		}

		return 0;
	}
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
				
		if ( GetCrashHeavySound() )
			PlayCrashHeavySound();
		else if ( GetCrashLightSound() )
			PlayCrashLightSound();
		
		UpdateLights();
	}
	override void EEItemAttached ( EntityAI item, string slot_name ) 
	{
		super.EEItemAttached( item, slot_name );
		if ( GetGame().IsServer() )
		{
			if ( slot_name == "Reflector_1_1" )
				SetHealth( "Reflector_1_1", "Health", item.GetHealth() );

			if ( slot_name == "Reflector_2_1" )
				SetHealth( "Reflector_2_1", "Health", item.GetHealth() );

			if ( slot_name == "CarBattery" )
				m_BatteryHealth = item.GetHealth01();
						
			if ( slot_name == "SparkPlug" )
				m_PlugHealth = item.GetHealth01();
			
			Synchronize();
		}
		UpdateHeadlightState();
		UpdateLights();
	}
	override void EEItemDetached(EntityAI item, string slot_name)
	{
		if ( GetGame().IsServer() )
		{
			//int slot_id = InventorySlots.GetSlotIdFromString(slot_name);
			if ( IsScriptedLightsOn() )
			{
				if ( slot_name == "CarBattery" || slot_name == "SparkPlug" )
				{
					ToggleHeadlights();
				}
			}

			if ( EngineIsOn() )
			{
				if ( slot_name == "SparkPlug" || slot_name == "CarBattery" )
					EngineStop();
			}
			
			if ( slot_name == "CarBattery" )
				m_BatteryHealth = -1;

			if ( slot_name == "SparkPlug" )
				m_PlugHealth = -1;

			if ( slot_name == "CarRadiator" )
			{
				LeakAll( CarFluid.COOLANT );
				SetHealth( "Radiator", "Health", 0);
			}

			Synchronize();
		}
		
		UpdateHeadlightState();
		UpdateLights();

	}
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast( ScriptedLightBase.CreateLight(M3_G80FrontLight) );
	}
	
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast( ScriptedLightBase.CreateLight(M3_G80RearLight) );
	}
	
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		
		string attType = attachment.GetType();
		
		if ( EngineIsOn() || GetCarDoorsState("M3_G80_hood") == CarDoorState.DOORS_CLOSED )
		{
			if ( attType == "CarRadiator" || attType == "SparkPlug" || attType == "CarBattery")
				return false;
		}
		if ( GetCarDoorsState("M3_G80_trunk") == CarDoorState.DOORS_CLOSED )
		{
			if (attType == "M3_G80Wheel_offroad_1_1" || attType == "M3_G80Wheel_offroad_1_2"  || attType == "M3_G80Wheel_offroad_2_1" || attType == "M3_G80Wheel_offroad_2_2")
				return false;
		}

		return true;
	}
	
	override bool CanDisplayAttachmentCategory( string category_name )
	{

		category_name.ToLower();
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if ( category_name.Contains( "Engine" ) )
		{
			if ( GetCarDoorsState("M3_G80_hood") == CarDoorState.DOORS_CLOSED )
				return false;
		}
				
		return true;
	}
	
	override bool CanDisplayCargo()
	{
		if ( !super.CanDisplayCargo() )
			return false;
		
		if ( GetCarDoorsState("M3_G80_trunk") == CarDoorState.DOORS_CLOSED )
			return false;
		
		return true;
	}
	
	override int GetCarDoorsState( string slotType )
	{
		CarDoor carDoor;

		Class.CastTo( carDoor, FindAttachmentBySlotName( slotType ) );
		if ( !carDoor )
			return CarDoorState.DOORS_MISSING;
	
		switch( slotType )
		{
			case "M3_G80_driver":
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "M3_G80_codriver":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "M3_G80_cargo1":
				if ( GetAnimationPhase("DoorsCargo1") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "M3_G80_cargo2":
				if ( GetAnimationPhase("DoorsCargo2") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
			
			case "M3_G80_trunk":
				if ( GetAnimationPhase("DoorsTrunk") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "M3_G80_hood":
				if ( GetAnimationPhase("DoorsHood") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
		}

		return CarDoorState.DOORS_MISSING;
	}
	

	override bool CrewCanGetThrough( int posIdx )
	{
		switch( posIdx )
		{
			case 0:
				if ( GetCarDoorsState( "M3_G80_driver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 1:
				if ( GetCarDoorsState( "M3_G80_codriver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 2:
				if ( GetCarDoorsState( "M3_G80_cargo1" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 3:
				if ( GetCarDoorsState( "M3_G80_cargo2" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
		}

		return false;
	}

	override string GetDoorSelectionNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "doors_driver";
		break;
		case 1:
			return "doors_codriver";
		break;
		case 2:
			return "doors_cargo1";
		break;
		case 3:
			return "doors_cargo2";
		break;
		}
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}
	bool IsVitalKeys_M3_G80()
	{
		return true;
	}
	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
			return "M3_G80_driver";
		break;
		case 1:
			return "M3_G80_codriver";
		break;
		case 2:
			return "M3_G80_cargo1";
		break;
		case 3:
			return "M3_G80_cargo2";
		break;
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}

	override float OnSound( CarSoundCtrl ctrl, float oldValue )
	{
		switch ( ctrl )
		{
			case CarSoundCtrl.DOORS:
				float newValue = 1;
				
				//-----
				if ( GetCarDoorsState( "M3_G80_driver" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "M3_G80_codriver" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetCarDoorsState( "M3_G80_cargo1" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;

				//-----
				if ( GetCarDoorsState( "M3_G80_cargo2" ) == CarDoorState.DOORS_CLOSED )
					newValue += 0.25;
			
				//-----
				if ( GetHealthLevel( "WindowFront") == GameConstants.STATE_RUINED )
					newValue -= 0.6;

				//-----
				if ( GetHealthLevel( "WindowBack") == GameConstants.STATE_RUINED )
					newValue -= 0.6;
			
				if ( newValue > 1 )
					newValue = 1;
			
				if ( newValue < 0 )
					newValue = 0;
			
				return newValue;
			break;
		}

		return oldValue;
	}

	override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_cargo1":
			return "DoorsCargo1";
		case "doors_cargo2":
			return "DoorsCargo2";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";
		}

		return "";
	}

	override bool IsVitalTruckBattery()
	{
		return false;
	}

	override bool IsVitalGlowPlug()
	{
		return false;
	}
	
	override bool CanReachSeatFromSeat( int currentSeat, int nextSeat )
	{
		switch( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 )
				return true;
			break;
		case 1:
			if ( nextSeat == 0 )
				return true;
			break;
		case 2:
			if ( nextSeat == 3 )
				return true;
			break;
		case 3:
			if ( nextSeat == 2 )
				return true;
			break;
		}
		
		return false;
	}

	override bool CanReachDoorsFromSeat( string pDoorsSelection, int pCurrentSeat )
	{
		switch( pCurrentSeat )
		{
		case 0:
			if (pDoorsSelection == "DoorsDriver")
			{
				return true;
			}
		break;
		case 1:
			if (pDoorsSelection == "DoorsCoDriver")
			{
				return true;
			}
		break;
		case 2:
			if (pDoorsSelection == "DoorsCargo1")
			{
				return true;
			}
		break;
		case 3:
			if (pDoorsSelection == "DoorsCargo2")
			{
				return true;
			}
		break;
		}
		
		return false;		
	}
	
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{

			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "M3_G80_codriver_Police" );
			entity.GetInventory().CreateInInventory( "M3_G80_driver_Police" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo1_Police" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo2_Police" );
			entity.GetInventory().CreateInInventory( "M3_G80_hood_Police" );
			entity.GetInventory().CreateInInventory( "M3_G80_trunk_Police" );
			
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		};

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class M3_G80_Police2 extends M3_G80_Police
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{

			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "M3_G80_codriver_Police2" );
			entity.GetInventory().CreateInInventory( "M3_G80_driver_Police2" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo1_Police2" );
			entity.GetInventory().CreateInInventory( "M3_G80_cargo2_Police2" );
			entity.GetInventory().CreateInInventory( "M3_G80_hood_Police2" );
			entity.GetInventory().CreateInInventory( "M3_G80_trunk_Police2" );
			
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			entity.GetInventory().CreateInInventory( "M3_G80Wheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		};

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};