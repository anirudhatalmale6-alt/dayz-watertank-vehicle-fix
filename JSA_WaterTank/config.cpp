class CfgPatches
{
	class JSA_WaterTank
	{
		units[]          = {"JSA_WaterTank_Kit", "JSA_WaterTank"};
		weapons[]        = {};
		requiredVersion  = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Gear_Medical", "MSP_Scripts"};
	};
};

class CfgMods
{
	class JSA_WaterTank
	{
		dir         = "JSA_WaterTank";
		picture     = "";
		action      = "";
		hideName    = 1;
		hidePicture = 1;
		name        = "JSA Water Tank";
		credits     = "";
		author      = "BipolarBear";
		authorID    = "0";
		version     = "1.0";
		extra       = 0;
		type        = "mod";

		dependencies[] = {"World", "Mission"};

		class defs
		{
			class worldScriptModule
			{
				value   = "";
				files[] = {"JSA_WaterTank/scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Msp_Item : Inventory_Base {};
	class Msp_Kit  : Inventory_Base {};

	class JSA_WaterTank_Kit : Msp_Kit
	{
		scope       = 2;
		displayName = "Water Tank Kit";
		model       = "\MuchFramework\data\kitbox\kitbox.p3d";
		deployItem  = "JSA_WaterTank";
		itemSize[]  = {4, 4};
		weight      = 5000;
	};

	class JSA_WaterTank : Msp_Item
	{
		scope            = 2;
		displayName      = "Water Tank";
		descriptionShort = "A large water tank. Can be dismantled with a screwdriver.";
		model            = "JSA_WaterTank\WaterTank\watertank.p3d";
		packItem         = "JSA_WaterTank_Kit";
		visibilityModifier = 0.95;
		handheld         = 0;
		weight           = 1000000;
		absorbency       = 0;
		carveNavmesh     = 1;
		canBeDigged      = 0;
		itemSize[]       = {10, 15};
		rotationFlags    = 2;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100000000000;
				};
			};
		};
	};
};
