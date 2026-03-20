modded class ModItemRegisterCallbacks
{
	
	override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		super.RegisterHeavy( pType, pBehavior );
		
        pType.AddItemInHandsProfileIK("Star_Audi_R8_Wheel",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
		pType.AddItemInHandsProfileIK("Star_Audi_R8_driver",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		pType.AddItemInHandsProfileIK("Star_Audi_R8_codriver",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		
		pType.AddItemInHandsProfileIK("Star_Audi_R8_hood",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		pType.AddItemInHandsProfileIK("Star_Audi_R8_trunk",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
        
	}
}