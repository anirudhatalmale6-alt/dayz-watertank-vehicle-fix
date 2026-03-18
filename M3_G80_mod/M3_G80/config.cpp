////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.98
//https://mikero.bytex.digital/Downloads
//'now' is Tue Feb 03 16:02:54 2026 : 'file' last modified on Thu Jan 15 08:02:16 2026
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgSoundShaders
{
	class baseEngineM3_G80_SoundShader
	{
		range = 80;
	};
	class M3_G80_Engine_Ext_Rpm0_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Rpm0",1}};
		frequency = "0.95 * ((850 + ((rpm - 850)/(8000/5600))) max 850) / 850";
		volume = "0.85 * 1 * engineOn * 0.4 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) + 2.5*50),(((850+1200)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Ext_Rpm1_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Rpm1",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1200";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.6 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) - 2.5*50),(((850+1200)/2) + 50)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) + 2.5*150),(((1200+1700)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Offload_Rpm1",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1200";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.6 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) - 2.5*50),(((850+1200)/2) + 50)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) + 2.5*150),(((1200+1700)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Ext_Rpm2_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Rpm2",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1700";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.85 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) - 2.5*150),(((1200+1700)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) + 2.5*150),(((1700+2300)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Offload_Rpm2",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1700";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.85 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) - 2.5*150),(((1200+1700)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) + 2.5*150),(((1700+2300)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Ext_Rpm3_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Rpm3",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 2300";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) - 2.5*150),(((1700+2300)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) + 2.5*200),(((2300+3150)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Offload_Rpm3",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 2300";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) - 2.5*150),(((1700+2300)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) + 2.5*200),(((2300+3150)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Ext_Rpm4_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Rpm4",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 3150";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) - 2.5*200),(((2300+3150)/2) + 200)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) + 2.5*200),(((3150+4400)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Offload_Rpm4",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 3150";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) - 2.5*200),(((2300+3150)/2) + 200)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) + 2.5*200),(((3150+4400)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Ext_Rpm5_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Rpm5",2}};
		frequency = "(1 * (850 + ((rpm - 850)/(8000/5600))) / 4400) min (8000/5600)";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) - 2.5*200),(((3150+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Offload_Ext_Rpm5_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_Engine_Ext_Offload_Rpm5",2}};
		frequency = "(1 * (850 + ((rpm - 850)/(8000/5600))) / 4400) min (8000/5600)";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) - 2.5*200),(((3150+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class M3_G80_Engine_Start_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_engine_start",1}};
		volume = 0.7;
	};
	class M3_G80_Engine_Stop_SoundShader: baseEngineM3_G80_SoundShader
	{
		samples[] = {{"M3_G80\sounds\M3_G80_engine_stop",1}};
		volume = 0.7;
	};
};
class CfgSoundSets
{
	class baseEngine_EXT_SoundSet
	{
		sound3DProcessingType = "Vehicle_Ext_3DProcessingType";
		distanceFilter = "softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve = "vehicleEngineAttenuationCurve";
		volumeFactor = 1.1;
		occlusionFactor = 0;
		obstructionFactor = 0;
		spatial = 1;
		loop = 1;
	};
	class baseM3_G80_Engine_EXT_SoundSet
	{
		sound3DProcessingType = "Vehicle_Ext_3DProcessingType";
		distanceFilter = "softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve = "vehicleEngineAttenuationCurve";
		volumeFactor = 1.1;
		spatial = 1;
		loop = 0;
	};
	class M3_G80_Engine_Ext_Rpm0_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Ext_Rpm0_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Offload_Ext_Rpm1_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Offload_Ext_Rpm1_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Ext_Rpm1_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Ext_Rpm1_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Ext_Rpm2_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Ext_Rpm2_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Offload_Ext_Rpm2_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Offload_Ext_Rpm2_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Ext_Rpm3_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Ext_Rpm3_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Offload_Ext_Rpm3_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Offload_Ext_Rpm3_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Ext_Rpm4_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Ext_Rpm4_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Offload_Ext_Rpm4_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Offload_Ext_Rpm4_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Ext_Rpm5_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Ext_Rpm5_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_Offload_Ext_Rpm5_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Offload_Ext_Rpm5_SoundShader"};
		volumeFactor = 1;
	};
	class M3_G80_Engine_start_SoundSet: baseM3_G80_Engine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Start_SoundShader"};
		frequencyFactor = 0.95;
		startDelay = 0;
		positionOffset[] = {0,0,1};
	};
	class M3_G80_Engine_ext_stop_SoundSet: baseM3_G80_Engine_EXT_SoundSet
	{
		soundShaders[] = {"M3_G80_Engine_Stop_SoundShader"};
		frequencyFactor = 0.95;
		positionOffset[] = {0,0,1};
	};
};
class CfgMods
{
	class M3_G80
	{
		dir = "M3_G80";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "M3_G80";
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
				files[] = {"M3_G80/scripts/M3_G80"};
			};
		};
	};
};
class CfgPatches
{
	class M3_G80
	{
		units[] = {"M3_G80Wheel_offroad","M3_G80Wheel_offroad_destroyed","M3_G80_driver","M3_G80_codriver","M3_G80_cargo1","M3_G80_cargo2","M3_G80_hood","M3_G80_trunk","M3_G80","JSA_M3_Admin","M3_G80_hood_JSA","M3_G80_trunk_JSA","M3_G80_driver_JSA","M3_G80_codriver_JSA","M3_G80_cargo1_JSA","M3_G80_cargo2_JSA"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Vehicles_Wheeled","DZ_Vehicles_Parts","DZ_Sounds_Effects","DZ_Data"};
	};
};
class CfgSlots
{
	class Slot_M3_G80Wheel_offroad_1_1
	{
		name = "M3_G80Wheel_offroad_1_1";
		displayName = "M3_G80 Front left wheel";
		selection = "wheel_1_1";
		ghostIcon = "wheel";
	};
	class Slot_M3_G80Wheel_offroad_1_2
	{
		name = "M3_G80Wheel_offroad_1_2";
		displayName = "M3_G80 Rear left wheel";
		selection = "wheel_1_2";
		ghostIcon = "wheel";
	};
	class Slot_M3_G80Wheel_offroad_2_1
	{
		name = "M3_G80Wheel_offroad_2_1";
		displayName = "M3_G80 Front right wheel";
		selection = "wheel_2_1";
		ghostIcon = "wheel";
	};
	class Slot_M3_G80Wheel_offroad_2_2
	{
		name = "M3_G80Wheel_offroad_2_2";
		displayName = "M3_G80 Rear right wheel";
		selection = "wheel_2_2";
		ghostIcon = "wheel";
	};
	class Slot_M3_G80_driver
	{
		name = "M3_G80_driver";
		displayName = "M3_G80 Front left door";
		selection = "doors_driver";
		ghostIcon = "doorfront";
	};
	class Slot_M3_G80_codriver
	{
		name = "M3_G80_codriver";
		displayName = "M3_G80 Front right door";
		selection = "doors_codriver";
		ghostIcon = "doorfront";
	};
	class Slot_M3_G80_cargo1
	{
		name = "M3_G80_cargo1";
		displayName = "M3_G80 Rear left door";
		selection = "doors_cargo1";
		ghostIcon = "doorrear";
	};
	class Slot_M3_G80_cargo2
	{
		name = "M3_G80_cargo2";
		displayName = "M3_G80 Rear right door";
		selection = "doors_cargo2";
		ghostIcon = "doorrear";
	};
	class Slot_M3_G80_hood
	{
		name = "M3_G80_hood";
		displayName = "M3_G80 Hood";
		selection = "doors_Hood";
		ghostIcon = "hood";
	};
	class Slot_M3_G80_trunk
	{
		name = "M3_G80_trunk";
		displayName = "M3_G80 Trunk";
		selection = "doors_Trunk";
		ghostIcon = "trunk";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Transmitter_Base;
	class DamageSystem;
	class GlobalHealth;
	class DamageZones;
	class Window;
	class Health;
	class Container_Base;
	class Bottle_Base;
	class Car;
	class Axles;
	class Front;
	class Rear;
	class Left;
	class Crew;
	class Driver;
	class CoDriver;
	class Right;
	class wheels;
	class CarWheel;
	class CarDoor;
	class CarScript;
	class SimulationModule;
	class AnimationSources;
	class Doors;
	class M3_G80Wheel_offroad: CarWheel
	{
		scope = 2;
		model = "\M3_G80\proxy\M3_G80Wheel_offroad.p3d";
		displayName = "BMW M3_G80 Wheel";
		descriptionShort = "";
		itemSize[] = {6,6};
		rotationFlags = 4;
		repairableWithKits[] = {6};
		repairCosts[] = {30};
		inventorySlot[] = {"M3_G80Wheel_offroad_1_1","M3_G80Wheel_offroad_1_2","M3_G80Wheel_offroad_2_1","M3_G80Wheel_offroad_2_2","M3_G80Wheel_offroad_spare_1","Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2","Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
		radiusByDamage[] = {0,0.4,0.26,0.26,0.9998,0.25,0.9999,0.273};
		radius = 0.3;
		width = 0.2;
		tyreOffroadResistance = 0.43;
		tyreGrip = 1;
		tyreRollResistance = 0.016;
		tyreTread = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
		};
	};
	class M3_G80Wheel_offroad_destroyed: M3_G80Wheel_offroad
	{
		model = "\M3_G80\proxy\M3_G80Wheel_offroad_destroyed.p3d";
		radius = 0.22;
		width = 0.2;
		tyreRollResistance = 1;
		tyreRollDrag = 75;
		tyreRoughness = 1.2;
		tyreTread = 0.5;
	};
	class M3_G80_driver: CarDoor
	{
		scope = 2;
		displayName = "BMW M3_G80 Door front left";
		descriptionShort = "Front left door for BMW M3_G80";
		model = "\M3_G80\proxy\M3_G80_driver.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "M3_G80_driver";
		rotationFlags = 8;
		physLayer = "item_large";
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap.paa","M3_G80\data\M3_G80campremap_red.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					healthLevels[] = {{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
			class DamageZones
			{
				class Window
				{
					class Health
					{
						hitpoints = 10000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					componentNames[] = {"dmgzone_window"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
				class Doors
				{
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					componentNames[] = {"dmgzone_doors"};
					fatalInjuryCoef = -1;
					inventorySlots[] = {};
				};
			};
		};
	};
	class M3_G80_codriver: M3_G80_driver
	{
		displayName = "BMW M3_G80 Door front right";
		descriptionShort = "Front right door for BMW M3_G80";
		model = "\M3_G80\proxy\M3_G80_codriver.p3d";
		inventorySlot = "M3_G80_codriver";
		rotationFlags = 4;
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap.paa","M3_G80\data\M3_G80campremap_red.paa"};
	};
	class M3_G80_cargo1: M3_G80_driver
	{
		displayName = "BMW M3_G80 door cargo1";
		descriptionShort = "BMW M3_G80 cargo1";
		model = "\M3_G80\proxy\M3_G80_cargo1.p3d";
		inventorySlot = "M3_G80_cargo1";
	};
	class M3_G80_cargo2: M3_G80_driver
	{
		displayName = "BMW M3_G80 door cargo2";
		descriptionShort = "BMW M3_G80 door cargo2";
		model = "\M3_G80\proxy\M3_G80_cargo2.p3d";
		inventorySlot = "M3_G80_cargo2";
	};
	class M3_G80_hood: M3_G80_driver
	{
		scope = 2;
		displayName = "BMW M3_G80 Hood";
		descriptionShort = "Hood for BMW M3_G80";
		model = "\M3_G80\proxy\M3_G80_hood.p3d";
		weight = 10000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "M3_G80_hood";
		rotationFlags = 2;
		physLayer = "item_large";
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap.paa","M3_G80\data\M3_G80campremap_red.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUp
				{
					soundSet = "hatchbackdoors_driver_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "hatchbackhood_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class M3_G80_trunk: M3_G80_driver
	{
		scope = 2;
		displayName = "BMW M3_G80 Trunk";
		descriptionShort = "Trunk for BMW M3_G80";
		model = "\M3_G80\proxy\M3_G80_trunk.p3d";
		weight = 10000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "M3_G80_trunk";
		rotationFlags = 3;
		physLayer = "item_large";
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap.paa","M3_G80\data\M3_G80campremap_red.paa"};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
				};
			};
		};
	};
	class M3_G80_hood_Blue: M3_G80_hood
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_blue.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_trunk_Blue: M3_G80_trunk
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_blue.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_driver_Blue: M3_G80_driver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_blue.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_codriver_Blue: M3_G80_codriver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_blue.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_hood_Red: M3_G80_hood
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_red.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_trunk_Red: M3_G80_trunk
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_red.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_driver_Red: M3_G80_driver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_red.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_codriver_Red: M3_G80_codriver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_red.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_hood_yellow: M3_G80_hood
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_yellow.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_trunk_yellow: M3_G80_trunk
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_yellow.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_driver_yellow: M3_G80_driver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_yellow.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_codriver_yellow: M3_G80_codriver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_yellow.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_hood_white: M3_G80_hood
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_white.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_trunk_white: M3_G80_trunk
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_white.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_driver_white: M3_G80_driver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_white.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_codriver_white: M3_G80_codriver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_white.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_cargo1_white: M3_G80_cargo1
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_white.paa"};
	};
	class M3_G80_cargo2_white: M3_G80_cargo2
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_white.paa"};
	};
	class M3_G80_cargo1_Red: M3_G80_cargo1
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_red.paa"};
	};
	class M3_G80_cargo2_Red: M3_G80_cargo2
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_red.paa"};
	};
	class M3_G80_cargo1_Blue: M3_G80_cargo1
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_blue.paa"};
	};
	class M3_G80_cargo2_Blue: M3_G80_cargo2
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_blue.paa"};
	};
	class M3_G80_cargo1_yellow: M3_G80_cargo1
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_yellow.paa"};
	};
	class M3_G80_cargo2_yellow: M3_G80_cargo2
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_yellow.paa"};
	};
	class M3_G80_hood_Police: M3_G80_hood
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_trunk_Police: M3_G80_trunk
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_driver_Police: M3_G80_driver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_codriver_Police: M3_G80_codriver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_cargo1_Police: M3_G80_cargo1
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police.paa"};
	};
	class M3_G80_cargo2_Police: M3_G80_cargo2
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police.paa"};
	};
	class M3_G80_hood_Police2: M3_G80_hood
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police2.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_trunk_Police2: M3_G80_trunk
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police2.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_driver_Police2: M3_G80_driver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police3.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_codriver_Police2: M3_G80_codriver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police3.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_cargo1_Police2: M3_G80_cargo1
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police3.paa"};
	};
	class M3_G80_cargo2_Police2: M3_G80_cargo2
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_police3.paa"};
	};
	class M3_G80_hood_JSA: M3_G80_hood
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_trunk_JSA: M3_G80_trunk
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_driver_JSA: M3_G80_driver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_codriver_JSA: M3_G80_codriver
	{
		hiddenSelections[] = {"camo_door","camo6"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_JSA.paa","M3_G80\data\M3_G80campremap.paa"};
	};
	class M3_G80_cargo1_JSA: M3_G80_cargo1
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_JSA.paa"};
	};
	class M3_G80_cargo2_JSA: M3_G80_cargo2
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"M3_G80\data\M3_G80campremap_JSA.paa"};
	};
	class M3_G80: CarScript
	{
		scope = 2;
		displayname = "BMW M3_G80";
		descriptionShort = "";
		centerOfMass[] = {0,-0.45,0};
		Model = "\M3_G80\M3_G80.p3d";
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1","CarRadiator","SparkPlug","M3_G80Wheel_offroad_1_1","M3_G80Wheel_offroad_1_2","M3_G80Wheel_offroad_2_1","M3_G80Wheel_offroad_2_2","M3_G80Wheel_offroad_spare_1","M3_G80_driver","M3_G80_codriver","M3_G80_cargo1","M3_G80_cargo2","M3_G80_trunk","M3_G80_hood","Cassette","underglow01","aplate1"};
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap.paa","M3_G80\data\M3_G80campremap_red.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","M3_G80\data\glossy.rvmat"};
		dashboardMatOn = "M3_G80\data\M3_G80_dashboardlight.rvmat";
		dashboardMatOff = "M3_G80\data\M3_G80_dashboardlight_off.rvmat";
		frontReflectorMatOn = "M3_G80\data\M3_G80_lights.rvmat";
		frontReflectorMatOff = "M3_G80\data\M3_G80_dashboardlight_off.rvmat";
		brakeReflectorMatOn = "M3_G80\data\M3_G80_lights.rvmat";
		brakeReflectorMatOff = "M3_G80\data\M3_G80_dashboardlight_off.rvmat";
		TailReflectorMatOn = "M3_G80\data\M3_G80_lights.rvmat";
		TailReflectorMatOff = "M3_G80\data\M3_G80_dashboardlight_off.rvmat";
		ReverseReflectorMatOn = "M3_G80\data\M3_G80_lights.rvmat";
		ReverseReflectorMatOff = "M3_G80\data\M3_G80_dashboardlight_off.rvmat";
		fuelCapacity = 80;
		fuelConsumption = 25;
		class Sounds
		{
			thrust = 0.6;
			thrustTurbo = 1;
			thrustGentle = 0.3;
			thrustSmoothCoef = 0.1;
			camposSmoothCoef = 0.03;
			soundSetsFilter[] = {"M3_G80_Engine_Offload_Ext_Rpm1_SoundSet","M3_G80_Engine_Offload_Ext_Rpm2_SoundSet","M3_G80_Engine_Offload_Ext_Rpm3_SoundSet","M3_G80_Engine_Offload_Ext_Rpm4_SoundSet","M3_G80_Engine_Offload_Ext_Rpm5_SoundSet","M3_G80_Engine_Ext_Rpm0_SoundSet","M3_G80_Engine_Ext_Rpm1_SoundSet","M3_G80_Engine_Ext_Rpm2_SoundSet","M3_G80_Engine_Ext_Rpm3_SoundSet","M3_G80_Engine_Ext_Rpm4_SoundSet","M3_G80_Engine_Ext_Rpm5_SoundSet","offroad_Tires_rock_slow_Ext_SoundSet","offroad_Tires_rock_fast_Ext_SoundSet","offroad_Tires_grass_slow_Ext_SoundSet","offroad_Tires_grass_fast_Ext_SoundSet","offroad_Tires_gravel_slow_Ext_SoundSet","offroad_Tires_gravel_fast_Ext_SoundSet","offroad_Tires_asphalt_slow_Ext_SoundSet","offroad_Tires_asphalt_fast_Ext_SoundSet","offroad_Tires_water_slow_Ext_SoundSet","offroad_Tires_water_fast_Ext_SoundSet","offroad_skid_dirt_SoundSet","offroad_dirt_turn_SoundSet","offroad_Rain_Ext_SoundSet"};
			soundSetsInt[] = {"offroad_Tires_Asphalt_Slow_General_Int_SoundSet","offroad_Tires_Asphalt_Fast_General_Int_SoundSet","offroad_Wind_SoundSet"};
		};
		class Crew: Crew
		{
			class Driver: Driver{};
			class CoDriver: CoDriver{};
			class Cargo1
			{
				actionSel = "seat_cargo1";
				proxyPos = "crewCargo1";
				getInPos = "pos_driver";
				getInDir = "pos_driver_dir";
			};
			class Cargo2
			{
				actionSel = "seat_cargo2";
				proxyPos = "crewCargo2";
				getInPos = "pos_coDriver";
				getInDir = "pos_coDriver_dir";
			};
		};
		class AnimationSources: AnimationSources
		{
			class SeatDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.8;
			};
			class SeatCoDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.8;
			};
			class DoorsDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCoDriver: DoorsDriver{};
			class DoorsHood: DoorsDriver{};
			class DoorsTrunk: DoorsDriver{};
			class DoorsCargo1: DoorsDriver{};
			class DoorsCargo2: DoorsDriver{};
			class engine_rotate
			{
				initPhase = 0;
				animPeriod = 0.3;
			};
			class engine_rotate1
			{
				initPhase = 0;
				animPeriod = 0.5;
			};
			class engine_rotate2
			{
				initPhase = 0;
				animPeriod = 0.5;
			};
			class damper_1_1
			{
				source = "user";
				initPhase = 0.4002;
				animPeriod = 1;
			};
			class damper_2_1: damper_1_1{};
			class damper_1_2
			{
				source = "user";
				initPhase = 0.4002;
				animPeriod = 1;
			};
			class damper_2_2: damper_1_2{};
		};
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 35;
				increaseSpeed[] = {0,40,60,30,100,15};
				decreaseSpeed[] = {0,90,60,45,100,20};
				centeringSpeed[] = {0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime = 1;
				defaultThrust = 0.89;
				gentleThrust = 0.7;
				turboCoef = 2.45;
				gentleCoef = 0.95;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.85,10,0.7,20,0.5,40,0.4,60,0.43,80,0.46,100,0.52,120,0.7};
				reactionTime = 0.25;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2.15;
				dragCoefficient = 0.15;
				downforceCoefficient = 0.8;
				downforceOffset[] = {0,0.4,-2.2};
			};
			drive = "DRIVE_AWD";
			class Engine
			{
				torqueCurve[] = {650,0,1360,290,3333,369,6036,424,8732,390,11020,0};
				inertia = 0.61;
				frictionTorque = 122;
				rollingFriction = 2.3;
				viscousFriction = 1.7;
				rpmIdle = 900;
				rpmMin = 1000;
				rpmClutch = 1352;
				rpmRedline = 9000;
			};
			class Clutch
			{
				maxTorqueTransfer = 505;
				uncoupleTime = 0.02;
				coupleTime = 0.17;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.726;
				ratios[] = {3.5,2.144,1.469,1.061,0.804};
			};
			class CentralDifferential
			{
				ratio = 0.75;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque = 2800;
					maxHandbrakeTorque = 2200;
					wheelHubMass = 30;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 50000;
						compression = 2600;
						damping = 9000;
						travelMaxUp = 0.08;
						travelMaxDown = 0.12;
					};
					class Wheels: wheels
					{
						class Left: Left
						{
							animTurn = "turnfrontleft";
							animRotation = "wheelfrontleft";
							wheelHub = "wheel_1_1_damper_land";
							animDamper = "damper_1_1";
							inventorySlot = "M3_G80Wheel_offroad_1_1";
						};
						class Right: Right
						{
							animTurn = "turnfrontright";
							animRotation = "wheelfrontright";
							wheelHub = "wheel_2_1_damper_land";
							animDamper = "damper_2_1";
							inventorySlot = "M3_G80Wheel_offroad_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque = 3000;
					maxHandbrakeTorque = 2500;
					wheelHubMass = 25;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 52000;
						compression = 2500;
						damping = 9200;
						travelMaxUp = 0.12;
						travelMaxDown = 0.14;
					};
					class Wheels: wheels
					{
						class Left: Left
						{
							animTurn = "turnbackleft";
							animRotation = "wheelbackleft";
							wheelHub = "wheel_1_2_damper_land";
							animDamper = "damper_1_2";
							inventorySlot = "M3_G80Wheel_offroad_1_2";
						};
						class Right: Right
						{
							animTurn = "turnbacktright";
							animRotation = "wheelbackright";
							wheelHub = "wheel_2_2_damper_land";
							animDamper = "damper_2_2";
							inventorySlot = "M3_G80Wheel_offroad_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			itemsCargoSize[] = {10,100};
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 80000;
					healthLevels[] = {{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					displayName = "$STR_CfgVehicleDmg_Chassis0";
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgZone_chassis"};
					class Health
					{
						hitpoints = 80000;
						transferToGlobalCoef = 0;
					};
					inventorySlots[] = {};
				};
				class Front
				{
					displayName = "$STR_CfgVehicleDmg_Bumper0";
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_front"};
					componentNames[] = {"dmgZone_front","dmgZone_bumper_1"};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					transferToZonesNames[] = {"Fender_1_1","Fender_2_1"};
					transferToZonesCoefs[] = {0.2,0.2};
					inventorySlots[] = {"CarRadiator"};
					inventorySlotsCoefs[] = {0.25,0.3,0.15,0.15};
				};
				class Reflector_1_1
				{
					displayName = "$STR_CfgVehicleDmg_Reflector0";
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_lights_1_1"};
					componentNames[] = {"dmgZone_lights_1_1"};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					transferToZonesNames[] = {"Front","Fender_1_1"};
					transferToZonesCoefs[] = {1,1};
					inventorySlots[] = {""};
					inventorySlotsCoefs[] = {1,0.1};
				};
				class Reflector_2_1: Reflector_1_1
				{
					memoryPoints[] = {"dmgZone_lights_2_1"};
					componentNames[] = {"dmgZone_lights_2_1"};
					transferToZonesNames[] = {"Front","Fender_2_1"};
					inventorySlots[] = {""};
				};
				class Back
				{
					displayName = "$STR_CfgVehicleDmg_Bumper0";
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_back"};
					componentNames[] = {"dmgZone_back"};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					transferToZonesNames[] = {"Fender_1_2","Fender_2_2","Engine"};
					transferToZonesCoefs[] = {0.2,0.2,0.17};
					inventorySlots[] = {""};
					inventorySlotsCoefs[] = {0.15,0.1,0.1};
				};
				class Roof
				{
					displayName = "$STR_CfgVehicleDmg_Roof0";
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_roof"};
					componentNames[] = {"dmgZone_roof"};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					inventorySlots[] = {};
				};
				class Fender_1_1
				{
					displayName = "$STR_CfgVehicleDmg_Fender0";
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_fender_1_1"};
					componentNames[] = {"dmgZone_fender_1_1"};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					transferToZonesNames[] = {"Front","Reflector_1_1"};
					transferToZonesCoefs[] = {0.25,0.25};
					inventorySlots[] = {""};
					inventorySlotsCoefs[] = {0.2,0.15,0.15};
				};
				class Fender_2_1: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_1"};
					componentNames[] = {"dmgZone_fender_2_1"};
					transferToZonesNames[] = {"Front","Reflector_2_1"};
					transferToZonesCoefs[] = {0.25,0.25};
					inventorySlots[] = {""};
					inventorySlotsCoefs[] = {0.2,0.1,0.1};
				};
				class Fender_1_2: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_1_2"};
					componentNames[] = {"dmgZone_fender_1_2"};
					transferToZonesNames[] = {"Back","Engine","FuelTank"};
					transferToZonesCoefs[] = {0.25,0.08,0.3};
					inventorySlots[] = {""};
					inventorySlotsCoefs[] = {0.2,0.15,0.15};
				};
				class Fender_2_2: Fender_1_1
				{
					memoryPoints[] = {"dmgZone_fender_2_2"};
					componentNames[] = {"dmgZone_fender_2_2"};
					transferToZonesNames[] = {"Back","Engine","FuelTank"};
					transferToZonesCoefs[] = {0.25,0.08,0.3};
					inventorySlots[] = {""};
					inventorySlotsCoefs[] = {0.2,0.15,0.15};
				};
				class WindowFront
				{
					displayName = "$STR_CfgVehicleDmg_Window0";
					fatalInjuryCoef = -1;
					memoryPoints[] = {"dmgZone_windowFront"};
					componentNames[] = {"dmgZone_windowFront"};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
				class WindowBack: WindowFront
				{
					componentNames[] = {"dmgZone_windowBack"};
					memoryPoints[] = {"dmgZone_windowBack"};
				};
				class Engine
				{
					displayName = "$STR_CfgVehicleDmg_Engine0";
					fatalInjuryCoef = 0.001;
					memoryPoints[] = {"dmgZone_engine"};
					componentNames[] = {"dmgZone_engine"};
					class Health
					{
						hitpoints = 20000;
						transferToGlobalCoef = 1;
						healthLevels[] = {{1,{""}},{0.7,{""}},{0.5,{""}},{0.3,{""}},{0,{""}}};
					};
					inventorySlots[] = {"CarBattery","SparkPlug"};
					inventorySlotsCoefs[] = {0.1,0.05};
				};
				class FuelTank
				{
					displayName = "$STR_CfgVehicleDmg_FuelTank0";
					fatalInjuryCoef = -1;
					componentNames[] = {"dmgZone_fuelTank"};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						healthLevels[] = {{1,{}},{0.7,{}},{0.5,{}},{0.3,{}},{0,{}}};
					};
					inventorySlots[] = {};
					inventorySlotsCoefs[] = {};
				};
			};
		};
		class ObstacleGenerator
		{
			carve = 1;
			timeToStationary = 5;
			moveThreshold = 0.5;
			class Shapes
			{
				class Cylindric
				{
					class Cyl1
					{
						radius = 1;
						height = 1.5;
						center[] = {0,0,0.7};
					};
					class Cyl3
					{
						radius = 1;
						height = 1.5;
						center[] = {0,0,-0.7};
					};
				};
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Engine
			{
				name = "Engine";
				description = "";
				attachmentSlots[] = {"CarBattery","CarRadiator","SparkPlug"};
				icon = "cat_vehicle_engine";
			};
			class Body
			{
				name = "M3_G80 Body";
				description = "";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","M3_G80_driver","M3_G80_codriver","M3_G80_cargo1","M3_G80_cargo2","M3_G80_trunk","M3_G80_hood"};
				icon = "cat_vehicle_body";
			};
			class Chassis
			{
				name = "M3_G80 Chassis";
				description = "";
				attachmentSlots[] = {"M3_G80Wheel_offroad_1_1","M3_G80Wheel_offroad_1_2","M3_G80Wheel_offroad_2_1","M3_G80Wheel_offroad_2_2"};
				icon = "cat_vehicle_chassis";
			};
			class FoXyRadio
			{
				name = "Radio";
				description = "Radio";
				icon = "default";
				attachmentSlots[] = {"Cassette"};
			};
			class mebradsattachments
			{
				name = "Underglow and Plate";
				description = "";
				icon = "cat_vehicle_chassis";
				attachmentSlots[] = {"underglow01","aplate1"};
			};
		};
	};
	class M3_G80_Blue: M3_G80
	{
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap_blue.paa","M3_G80\data\M3_G80campremap.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","M3_G80\data\glossy.rvmat"};
	};
	class M3_G80_Red: M3_G80
	{
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap_red.paa","M3_G80\data\M3_G80campremap.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","M3_G80\data\glossy.rvmat"};
	};
	class M3_G80_yellow: M3_G80
	{
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap_yellow.paa","M3_G80\data\M3_G80campremap.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","M3_G80\data\glossy.rvmat"};
	};
	class M3_G80_white: M3_G80
	{
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap_white.paa","M3_G80\data\M3_G80campremap.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","M3_G80\data\glossy.rvmat"};
	};
	class M3_G80_un: M3_G80
	{
		scope = 2;
		model = "M3_G80\M3_G80_un.p3d";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6","lightbar_red","lightbar_blue"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap.paa","","M3_G80\data\policelights\micron_diffuse.paa","M3_G80\data\policelights\micron_diffuse.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","","M3_G80\data\policelights\lightbar_main.rvmat","M3_G80\data\policelights\lightbar_main.rvmat"};
	};
	class M3_G80_Police: M3_G80
	{
		scope = 2;
		model = "M3_G80\M3_G80_Police.p3d";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6","lightbar_red","lightbar_blue"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap_police.paa","","M3_G80\data\policelights\micron_diffuse.paa","M3_G80\data\policelights\micron_diffuse.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","","M3_G80\data\policelights\lightbar_main.rvmat","M3_G80\data\policelights\lightbar_main.rvmat"};
	};
	class M3_G80_Police2: M3_G80
	{
		scope = 2;
		model = "M3_G80\M3_G80_Police.p3d";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6","lightbar_red","lightbar_blue"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap_police2.paa","","M3_G80\data\policelights\micron_diffuse.paa","M3_G80\data\policelights\micron_diffuse.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","","M3_G80\data\policelights\lightbar_main.rvmat","M3_G80\data\policelights\lightbar_main.rvmat"};
	};
	class JSA_M3_Admin: M3_G80
	{
		scope = 2;
		displayname = "JSA M3 Admin";
		model = "M3_G80\M3_G80_Police.p3d";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7","camo6","lightbar_red","lightbar_blue"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","M3_G80\data\M3_G80campremap_JSA.paa","","M3_G80\data\policelights\micron_diffuse.paa","M3_G80\data\policelights\micron_diffuse.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","M3_G80\data\glossy.rvmat","","M3_G80\data\policelights\lightbar_main.rvmat","M3_G80\data\policelights\lightbar_main.rvmat"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyVehiclePart: ProxyAttachment
	{
		scope = 2;
		simulation = "ProxyInventory";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 0;
	};
	class ProxyM3_G80Wheel_offroad: ProxyVehiclePart
	{
		model = "M3_G80\proxy\M3_G80Wheel_offroad.p3d";
		inventorySlot[] = {"M3_G80Wheel_offroad_1_1","M3_G80Wheel_offroad_1_2","M3_G80Wheel_offroad_2_1","M3_G80Wheel_offroad_2_2","M3_G80Wheel_offroad_spare_1","Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2","Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
	};
	class ProxyM3_G80Wheel_offroad_destroyed: ProxyVehiclePart
	{
		model = "M3_G80\proxy\M3_G80Wheel_offroad_destroyed.p3d";
		inventorySlot[] = {"M3_G80Wheel_offroad_1_1","M3_G80Wheel_offroad_1_2","M3_G80Wheel_offroad_2_1","M3_G80Wheel_offroad_2_2","M3_G80Wheel_offroad_spare_1","Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2","Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
	};
	class ProxyM3_G80_driver: ProxyVehiclePart
	{
		model = "\M3_G80\proxy\M3_G80_driver.p3d";
		inventorySlot = "M3_G80_driver";
	};
	class ProxyM3_G80_codriver: ProxyVehiclePart
	{
		model = "\M3_G80\proxy\M3_G80_codriver.p3d";
		inventorySlot = "M3_G80_codriver";
	};
	class ProxyM3_G80_hood: ProxyVehiclePart
	{
		model = "\M3_G80\proxy\M3_G80_hood.p3d";
		inventorySlot = "M3_G80_hood";
	};
	class ProxyM3_G80_cargo1: ProxyVehiclePart
	{
		model = "\M3_G80\proxy\M3_G80_cargo1.p3d";
		inventorySlot = "M3_G80_cargo1";
	};
	class ProxyM3_G80_cargo2: ProxyVehiclePart
	{
		model = "\M3_G80\proxy\M3_G80_cargo2.p3d";
		inventorySlot = "M3_G80_cargo2";
	};
	class ProxyM3_G80_trunk: ProxyVehiclePart
	{
		model = "\M3_G80\proxy\M3_G80_trunk.p3d";
		inventorySlot = "M3_G80_trunk";
	};
	class Proxyunderglow: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "underglow01";
		model = "MBM_UnderglowLights\underglow.p3d";
	};
	class Proxya_plate: ProxyAttachment
	{
		scope = 2;
		model = "Armada_plate\a_plate.p3d";
		inventorySlot[] += {"aplate1"};
	};
	class ProxyPart
	{
		scope = 2;
		simulation = "ProxyInventory";
		model = "";
		inventorySlot = "";
		autocenter = 0;
		animated = 0;
		shadow = 1;
		reversed = 1;
	};
};
