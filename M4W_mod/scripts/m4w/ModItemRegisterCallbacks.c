modded class ModItemRegisterCallbacks
{
	
	override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		super.RegisterHeavy( pType, pBehavior );
		
        pType.AddItemInHandsProfileIK("m4wWheel_offroad",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
		pType.AddItemInHandsProfileIK("m4w_driver",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		pType.AddItemInHandsProfileIK("m4w_codriver",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		
		pType.AddItemInHandsProfileIK("m4w_hood",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		pType.AddItemInHandsProfileIK("m4w_trunk",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
        
	}
}