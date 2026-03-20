class CfgPatches
{
	class JSA_Vehicle_Retextures
	{
		units[] = {"JSA_Golden_SVJ","JSA_SVJ_hood_Gold","JSA_SVJ_trunk_Gold","JSA_SVJ_driver_Gold","JSA_SVJ_codriver_Gold","JSA_Huracan_Holo","JSA_Huracan_Tecnica_trunk_Holo","JSA_Huracan_Tecnica_driver_Holo","JSA_Huracan_Tecnica_codriver_Holo","M4W_JSA","m4w_hood_JSA","m4w_trunk_JSA","m4w_driver_JSA","m4w_codriver_JSA","R8_Rally_JSA","Star_Audi_R8_hood_JSA","Star_Audi_R8_trunk_JSA","Star_Audi_R8_driver_JSA","Star_Audi_R8_codriver_JSA","JSA_M3_Admin","M3_G80_hood_JSA","M3_G80_trunk_JSA","M3_G80_driver_JSA","M3_G80_codriver_JSA","M3_G80_cargo1_JSA","M3_G80_cargo2_JSA"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Vehicles_Wheeled","DZ_Vehicles_Parts","SVJ","Huracan_Tecnica","m4w","Star_Audi_R8","M3_G80"};
	};
};
class CfgMods
{
	class JSA_Vehicle_Retextures
	{
		dir = "JSA_Vehicle_Retextures";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "JSA_Vehicle_Retextures";
		credits = "";
		author = "";
		authorID = "0";
		version = 1;
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"JSA_Vehicle_Retextures\scripts\JSA_Vehicle_Retextures"};
			};
		};
	};
};
class CfgVehicles
{
	// ===========================
	// BASE CLASS REFERENCES
	// ===========================
	class CarScript;

	// --- SVJ base classes ---
	class SVJ: CarScript {};
	class SVJ_hood;
	class SVJ_trunk;
	class SVJ_driver;
	class SVJ_codriver;

	// --- Huracan base classes ---
	class Huracan_Tecnica: CarScript {};
	class Huracan_Tecnica_trunk;
	class Huracan_Tecnica_driver;
	class Huracan_Tecnica_codriver;

	// --- M4W base classes ---
	class m4w: CarScript {};
	class m4w_hood;
	class m4w_trunk;
	class m4w_driver;
	class m4w_codriver;

	// --- Star Audi R8 base classes ---
	class Star_Audi_R8: CarScript {};
	class Star_Audi_R8_hood;
	class Star_Audi_R8_trunk;
	class Star_Audi_R8_driver;
	class Star_Audi_R8_codriver;

	// --- M3 G80 base classes ---
	class M3_G80: CarScript {};
	class M3_G80_hood;
	class M3_G80_trunk;
	class M3_G80_driver;
	class M3_G80_codriver;
	class M3_G80_cargo1;
	class M3_G80_cargo2;

	// ===========================
	// JSA GOLDEN SVJ
	// ===========================
	class JSA_SVJ_hood_Gold: SVJ_hood
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\SVJ\SVJcampremap_Gold.paa"};
	};
	class JSA_SVJ_trunk_Gold: SVJ_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\SVJ\SVJcampremap_Gold.paa"};
	};
	class JSA_SVJ_driver_Gold: SVJ_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\SVJ\SVJcampremap_Gold.paa"};
	};
	class JSA_SVJ_codriver_Gold: SVJ_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\SVJ\SVJcampremap_Gold.paa"};
	};
	class JSA_Golden_SVJ: SVJ
	{
		scope = 2;
		displayname = "JSA Golden SVJ";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","JSA_Vehicle_Retextures\data\SVJ\SVJcampremap_Gold.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","JSA_Vehicle_Retextures\data\SVJ\Gold.rvmat"};
	};

	// ===========================
	// JSA HURACAN HOLO
	// ===========================
	class JSA_Huracan_Tecnica_trunk_Holo: Huracan_Tecnica_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\Huracan\Holo_co.paa"};
	};
	class JSA_Huracan_Tecnica_driver_Holo: Huracan_Tecnica_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\Huracan\Holo_co.paa"};
	};
	class JSA_Huracan_Tecnica_codriver_Holo: Huracan_Tecnica_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\Huracan\Holo_co.paa"};
	};
	class JSA_Huracan_Holo: Huracan_Tecnica
	{
		scope = 2;
		displayname = "JSA Huracan Holo";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","JSA_Vehicle_Retextures\data\Huracan\Holo_co.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","JSA_Vehicle_Retextures\data\Huracan\Holo_Perl.rvmat"};
	};

	// ===========================
	// M4W JSA
	// ===========================
	class m4w_hood_JSA: m4w_hood
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M4W\m4wJSA.paa"};
	};
	class m4w_trunk_JSA: m4w_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M4W\m4wJSA.paa"};
	};
	class m4w_driver_JSA: m4w_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M4W\m4wJSA.paa"};
	};
	class m4w_codriver_JSA: m4w_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M4W\m4wJSA.paa"};
	};
	class M4W_JSA: m4w
	{
		scope = 2;
		displayname = "M4W_JSA";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","JSA_Vehicle_Retextures\data\M4W\m4wJSA.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","m4w\data\glossy.rvmat"};
	};

	// ===========================
	// R8 RALLY JSA
	// ===========================
	class Star_Audi_R8_hood_JSA: Star_Audi_R8_hood
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\AudiR8\audir8_JSA_rally.paa"};
	};
	class Star_Audi_R8_trunk_JSA: Star_Audi_R8_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\AudiR8\audir8_JSA_rally.paa"};
	};
	class Star_Audi_R8_driver_JSA: Star_Audi_R8_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\AudiR8\audir8_JSA_rally.paa"};
	};
	class Star_Audi_R8_codriver_JSA: Star_Audi_R8_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\AudiR8\audir8_JSA_rally.paa"};
	};
	class R8_Rally_JSA: Star_Audi_R8
	{
		scope = 2;
		displayname = "R8_Rally_JSA";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","JSA_Vehicle_Retextures\data\AudiR8\audir8_JSA_rally.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","Star_Audi_R8\data\glossy.rvmat"};
	};

	// ===========================
	// JSA M3 ADMIN
	// ===========================
	class M3_G80_hood_JSA: M3_G80_hood
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M3_G80\M3_G80campremap_police2_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_trunk_JSA: M3_G80_trunk
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M3_G80\M3_G80campremap_police2_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_driver_JSA: M3_G80_driver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M3_G80\M3_G80campremap_police3_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_codriver_JSA: M3_G80_codriver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M3_G80\M3_G80campremap_police3_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_cargo1_JSA: M3_G80_cargo1
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M3_G80\M3_G80campremap_police3_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_cargo2_JSA: M3_G80_cargo2
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"JSA_Vehicle_Retextures\data\M3_G80\M3_G80campremap_police3_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class JSA_M3_Admin: M3_G80
	{
		scope = 2;
		displayname = "JSA M3 Admin";
		model = "M3_G80\M3_G80_Police.p3d";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6","lightbar_red","lightbar_blue"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","JSA_Vehicle_Retextures\data\M3_G80\M3_G80campremap_JSA.paa","","M3_G80\data\policelights\micron_diffuse.paa","M3_G80\data\policelights\micron_diffuse.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","","M3_G80\data\policelights\lightbar_main.rvmat","M3_G80\data\policelights\lightbar_main.rvmat"};
	};
};
