class CfgPatches
{
	class JSA_Tools_Retextures
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Weapons_Melee", "DZ_Weapons_Blades"};
	};
};

class CfgVehicles
{
	// Forward declarations of parent classes from DayZ vanilla
	class CombatKnife;
	class Crowbar;
	class FirefighterAxe;
	class Hacksaw;
	class Hammer;
	class Hatchet;
	class HuntingKnife;
	class Pickaxe;
	class Pliers;
	class Shovel;
	class SledgeHammer;
	class Woodaxe;

	class JSA_CombatKnife: CombatKnife
	{
		scope = 2;
		displayName = "JSA Combat Knife";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\CombatKnife_jsa_co.paa"};
	};
	class JSA_Crowbar: Crowbar
	{
		scope = 2;
		displayName = "JSA Crowbar";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Crowbar_jsa_co.paa"};
	};
	class JSA_FirefighterAxe: FirefighterAxe
	{
		scope = 2;
		displayName = "JSA Firefighter Axe";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Fireaxe_jsa_co.paa"};
	};
	class JSA_Hacksaw: Hacksaw
	{
		scope = 2;
		displayName = "JSA Hacksaw";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Hacksaw_jsa_co.paa"};
	};
	class JSA_Hammer: Hammer
	{
		scope = 2;
		displayName = "JSA Hammer";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Hammer_jsa_co.paa"};
	};
	class JSA_Hatchet: Hatchet
	{
		scope = 2;
		displayName = "JSA Hatchet";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Hatchet_jsa_co.paa"};
	};
	class JSA_HuntingKnife: HuntingKnife
	{
		scope = 2;
		displayName = "JSA Hunting Knife";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\HuntingKnife_jsa_co.paa"};
	};
	class JSA_Pickaxe: Pickaxe
	{
		scope = 2;
		displayName = "JSA Pickaxe";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Pickaxe_jsa_co.paa"};
	};
	class JSA_Pliers: Pliers
	{
		scope = 2;
		displayName = "JSA Pliers";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Pliers_jsa_co.paa"};
	};
	class JSA_Shovel: Shovel
	{
		scope = 2;
		displayName = "JSA Shovel";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Shovel_jsa_co.paa"};
	};
	class JSA_SledgeHammer: SledgeHammer
	{
		scope = 2;
		displayName = "JSA Sledge Hammer";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Sledgehammer_jsa_co.paa"};
	};
	class JSA_Woodaxe: Woodaxe
	{
		scope = 2;
		displayName = "JSA Wood Axe";
		hiddenSelections[] = {"zbytek"};
		hiddenSelectionsTextures[] = {"JSA_Tools_Retextures\data\Woodaxe_jsa_co.paa"};
		hiddenSelectionsMaterials[] = {"JSA_Tools_Retextures\data\Woodaxe.rvmat"};
	};
};
