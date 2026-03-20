class Huracan_TecnicaWheel_offroad extends CarWheel {
	override void EEKilled(Object killer)
	{
		string newWheel = "";
		switch( GetType() )
		{
			case "Huracan_TecnicaWheel_offroad":
				newWheel = "Huracan_TecnicaWheel_offroad_destroyed";
			break;
		}
		if ( newWheel != "" )
		{
			ReplaceWheelLambda lambda = new ReplaceWheelLambda ( this, newWheel, NULL);
			lambda.SetTransferParams(true, true, true);
			GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, lambda);
		}
	}

	override int GetMeleeTargetType()
	{
		return EMeleeTargetType.NONALIGNABLE;
	}
	
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionDetach);
		AddAction(ActionAttachOnSelection);
	}
};
class Huracan_TecnicaWheel_offroad_destroyed extends ItemBase {};

class Huracan_TecnicaWheel_offroad_black extends CarWheel {
	override void EEKilled(Object killer)
	{
		string newWheel = "";
		switch( GetType() )
		{
			case "Huracan_TecnicaWheel_offroad_black":
				newWheel = "Huracan_TecnicaWheel_offroad_destroyed_black";
			break;
		}
		if ( newWheel != "" )
		{
			ReplaceWheelLambda lambda = new ReplaceWheelLambda ( this, newWheel, NULL);
			lambda.SetTransferParams(true, true, true);
			GetInventory().ReplaceItemWithNew(InventoryMode.SERVER, lambda);
		}
	}

	override bool CanDetachAttachment(EntityAI parent)
	{
		//parent.FindAtt
		InventoryLocation loc = new InventoryLocation();
		
		bool isPresent = GetInventory().GetCurrentInventoryLocation( loc );
		
		if ( !isPresent || loc.GetSlot() == -1 )
			return false;
		
		string slotName = InventorySlots.GetSlotName( loc.GetSlot() );

		if ( slotName && CarScript.Cast( parent ).GetCarDoorsState( slotName ) == CarDoorState.DOORS_OPEN )
			return true;
		
		return false;
	}

	override int GetMeleeTargetType()
	{
		return EMeleeTargetType.NONALIGNABLE;
	}
	
	override void EEHealthLevelChanged(int oldLevel, int newLevel, string zone)
	{
		super.EEHealthLevelChanged(oldLevel,newLevel,zone);
		
		if ( newLevel ==  GameConstants.STATE_RUINED )
		{
			EffectSound sound_plug;
			switch( zone )
			{
				case "Window":
					PlaySoundSet( sound_plug, "offroad_hit_window_small_SoundSet", 0, 0 );
				break;
			}
		}
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAttachOnSelection);
		AddAction(ActionDetach);
	}
};
class Huracan_TecnicaWheel_offroad_destroyed_black extends ItemBase {};

class Huracan_Tecnica_driver extends CarDoor {};
class Huracan_Tecnica_cargo1 extends CarDoor {};
class Huracan_Tecnica_codriver extends CarDoor {};
class Huracan_Tecnica_cargo2 extends CarDoor {};
class Huracan_Tecnica_hood extends CarDoor {};
class Huracan_Tecnica_trunk extends CarDoor {};