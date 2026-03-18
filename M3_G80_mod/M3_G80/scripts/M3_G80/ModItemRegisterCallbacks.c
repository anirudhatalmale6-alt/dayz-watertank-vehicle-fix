modded class ModItemRegisterCallbacks
{
	
	override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		super.RegisterHeavy( pType, pBehavior );
		
        pType.AddItemInHandsProfileIK("M3_G80Wheel_offroad",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_wheel.anm");
		pType.AddItemInHandsProfileIK("M3_G80_driver",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		pType.AddItemInHandsProfileIK("M3_G80_codriver",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		
		pType.AddItemInHandsProfileIK("M3_G80_hood",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
		pType.AddItemInHandsProfileIK("M3_G80_trunk",       "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,	"dz/anims/anm/player/ik/vehicles/hatchback_02/Hatchback_02_Door_driver.anm");
        
	}
}