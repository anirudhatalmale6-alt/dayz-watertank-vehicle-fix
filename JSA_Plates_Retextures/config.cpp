class CfgPatches
{
	class JSA_Plates_Retextures
	{
		units[] = {"JSA_Plate_Armada","JSA_Plate_Mil","JSA_Plate_SWAT"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","a_plate"};
	};
};

class CfgVehicles
{
	// Forward-declare base class from Armada_plate mod
	class a_plate_base;

	// --- JSA Armada Plate (uses original Armada plate texture) ---
	class JSA_Plate_Armada: a_plate_base
	{
		scope = 2;
		displayName = "JSA Armada Plate";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"JSA_Plates_Retextures\data\a_plate.paa"};
	};

	// --- JSA Military Plate (uses Candy SWATSUV mil plate texture) ---
	class JSA_Plate_Mil: a_plate_base
	{
		scope = 2;
		displayName = "JSA Military Plate";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"JSA_Plates_Retextures\data\numer_mil_co.paa"};
	};

	// --- JSA SWAT Plate (uses Candy SWATSUV swat plate texture) ---
	class JSA_Plate_SWAT: a_plate_base
	{
		scope = 2;
		displayName = "JSA SWAT Plate";
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"JSA_Plates_Retextures\data\numer_swat_co.paa"};
	};
};
