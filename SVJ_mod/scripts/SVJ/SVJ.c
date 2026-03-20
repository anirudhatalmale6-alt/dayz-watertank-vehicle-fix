class SVJ extends CarScript
{
	protected ref UniversalTemperatureSource m_UTSource;
	protected ref UniversalTemperatureSourceSettings m_UTSSettings;
	protected ref UniversalTemperatureSourceLambdaEngine m_UTSLEngine;
	
	void SVJ()
	{

		m_EngineStartOK			= "SVJ_Engine_start_SoundSet";
		m_EngineStartBattery 	= "offroad_engine_failed_start_battery_SoundSet";
		m_EngineStartPlug 		= "offroad_engine_failed_start_sparkplugs_SoundSet";
		m_EngineStartFuel 		= "offroad_engine_failed_start_fuel_SoundSet";
		m_EngineStopFuel 		= "SVJ_Engine_ext_stop_SoundSet";
		
		m_CarDoorOpenSound 		= "offroad_door_open_SoundSet";
		m_CarDoorCloseSound 	= "offroad_door_close_SoundSet";
		
		m_CarHornShortSoundName = "Offroad_Horn_Short_SoundSet";
		m_CarHornLongSoundName	= "Offroad_Horn_SoundSet";
		m_dmgContactCoef = 0.060;
		
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

	override bool CanDisplayCargo()
	{
		if ( !super.CanDisplayCargo() )
			return false;
		
		if ( GetCarDoorsState("SVJ_trunk") == CarDoorState.DOORS_CLOSED )
			return false;
		
		return true;
	}

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
	
	override CarLightBase CreateFrontLight()
	{
		return CarLightBase.Cast( ScriptedLightBase.CreateLight(SVJFrontLight) );
	}
	
	override CarRearLightBase CreateRearLight()
	{
		return CarRearLightBase.Cast( ScriptedLightBase.CreateLight(SVJRearLight) );
	}
	
	override bool CanReleaseAttachment( EntityAI attachment )
	{
		if( !super.CanReleaseAttachment( attachment ) )
			return false;
		
		string attType = attachment.GetType();
		
		switch( attType )
		{
			case "CarBattery": 
				if ( GetCarDoorsState("SVJ_hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
			
			case "SparkPlug":
				if ( GetCarDoorsState("SVJ_hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;

			case "CarRadiator":
				if ( GetCarDoorsState("SVJ_hood") == CarDoorState.DOORS_CLOSED || EngineIsOn() )
					return false;
			break;
		}

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
			case "SVJ_driver":
				if ( GetAnimationPhase("DoorsDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "SVJ_codriver":
				if ( GetAnimationPhase("DoorsCoDriver") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "SVJ_cargo1":
				if ( GetAnimationPhase("DoorsCargo1") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "SVJ_cargo2":
				if ( GetAnimationPhase("DoorsCargo2") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;
			break;
			
			case "SVJ_hood":
				if ( GetAnimationPhase("DoorsHood") > 0.5 )
					return CarDoorState.DOORS_OPEN;
				else
					return CarDoorState.DOORS_CLOSED;

			break;
			
			case "SVJ_trunk":
				if ( GetAnimationPhase("DoorsTrunk") > 0.5 )
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
				if ( GetCarDoorsState( "SVJ_driver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;
			
			case 1:
				if ( GetCarDoorsState( "SVJ_codriver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 2:
				if ( GetCarDoorsState( "SVJ_driver" ) == CarDoorState.DOORS_CLOSED )
					return false;

				return true;
			break;

			case 3:
				if ( GetCarDoorsState( "SVJ_codriver" ) == CarDoorState.DOORS_CLOSED )
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
		case 2:
			return "doors_driver";
		break;
		case 1:
		case 3:
			return "doors_codriver";
		break;
		}
		
		return super.GetDoorSelectionNameFromSeatPos(posIdx);
	}

	override string GetDoorInvSlotNameFromSeatPos(int posIdx)
	{
		switch( posIdx )
		{
		case 0:
		case 2:
			return "SVJ_driver";
		break;
		case 1:
		case 3:
			return "SVJ_codriver";
		break;
		}
		
		return super.GetDoorInvSlotNameFromSeatPos(posIdx);
	}
	
	override string GetAnimSourceFromSelection( string selection )
	{
		switch( selection )
		{
		case "doors_driver":
			return "DoorsDriver";
		case "doors_codriver":
			return "DoorsCoDriver";
		case "doors_hood":
			return "DoorsHood";
		case "doors_trunk":
			return "DoorsTrunk";
		case "seatback_driver":
			return "SeatDriver";
		case "seatback_codriver":
			return "SeatCoDriver";
		}

		return "";
	}
	
	override string GetDoorConditionPointFromSelection( string selection )
	{
		switch( selection )
		{
		case "seat_driver":
		case "seatback_driver":
		case "seat_cargo1":
			return "seat_con_1_1";
		break;
		case "seat_codriver":
		case "seatback_codriver":
		case "seat_cargo2":
			return "seat_con_2_1";
		break;
		}
		
		return "";
	}
	
	override int GetCrewIndex( string selection )
	{
		switch( selection )
		{
		case "seatback_driver":
			return 0;
		case "seatback_codriver":
			return 1;
		}

		return -1;
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
	if ( nextSeat == 0 && GetAnimationPhase("SeatDriver") > 0.5  )
			return false;
		
		if ( nextSeat == 1 && GetAnimationPhase("SeatCoDriver") > 0.5  )
			return false;
		
		switch( currentSeat )
		{
		case 0:
			if ( nextSeat == 1 )
			{
				return true;
			}
			break;
		case 1:
			if ( nextSeat == 0 )
			{
				return true;
			}
			break;
		case 2:
			if ( nextSeat == 3 )
			{
				return true;
			}
			break;
		case 3:
			if ( nextSeat == 2 )
			{
				return true;
			}
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
			if (pDoorsSelection == "DoorsDriver")
			{
				return true;
			}
		break;
		case 3:
			if (pDoorsSelection == "DoorsCoDriver")
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
			
			entity.GetInventory().CreateInInventory( "SVJ_codriver" );
			entity.GetInventory().CreateInInventory( "SVJ_driver" );
			entity.GetInventory().CreateInInventory( "SVJ_hood" );
			entity.GetInventory().CreateInInventory( "SVJ_trunk" );
			
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			
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

class SVJ_Blue extends SVJ
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "SVJ_codriver_Blue" );
			entity.GetInventory().CreateInInventory( "SVJ_driver_Blue" );
			entity.GetInventory().CreateInInventory( "SVJ_hood_Blue" );
			entity.GetInventory().CreateInInventory( "SVJ_trunk_Blue" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class SVJ_Red extends SVJ
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "SVJ_codriver_Red" );
			entity.GetInventory().CreateInInventory( "SVJ_driver_Red" );
			entity.GetInventory().CreateInInventory( "SVJ_hood_Red" );
			entity.GetInventory().CreateInInventory( "SVJ_trunk_Red" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class SVJ_yellow extends SVJ
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "SVJ_codriver_yellow" );
			entity.GetInventory().CreateInInventory( "SVJ_driver_yellow" );
			entity.GetInventory().CreateInInventory( "SVJ_hood_yellow" );
			entity.GetInventory().CreateInInventory( "SVJ_trunk_yellow" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class SVJ_white extends SVJ
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "SVJ_codriver_white" );
			entity.GetInventory().CreateInInventory( "SVJ_driver_white" );
			entity.GetInventory().CreateInInventory( "SVJ_hood_white" );
			entity.GetInventory().CreateInInventory( "SVJ_trunk_white" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};
class SVJ_black extends SVJ
{
	override void OnDebugSpawn()
	{
		EntityAI entity;
		
		if ( Class.CastTo(entity, this) )
		{
			entity.GetInventory().CreateInInventory( "CarBattery" );
			entity.GetInventory().CreateInInventory( "SparkPlug" );
			entity.GetInventory().CreateInInventory( "CarRadiator" );
			
			entity.GetInventory().CreateInInventory( "SVJ_codriver_black" );
			entity.GetInventory().CreateInInventory( "SVJ_driver_black" );
			entity.GetInventory().CreateInInventory( "SVJ_hood_black" );
			entity.GetInventory().CreateInInventory( "SVJ_trunk_black" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			entity.GetInventory().CreateInInventory( "SVJWheel_offroad" );
			
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
			entity.GetInventory().CreateInInventory( "HeadlightH7" );
		}

		Fill( CarFluid.FUEL, 94 );
		Fill( CarFluid.COOLANT, 6.0 );
		Fill( CarFluid.OIL, 4.0 );
	}
};