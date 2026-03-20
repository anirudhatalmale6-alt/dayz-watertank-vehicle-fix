////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 10.14
//https://mikero.bytex.digital/Downloads
//'now' is Fri Mar 20 16:11:21 2026 : 'file' last modified on Tue Sep 30 01:12:01 2025
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgSoundShaders
{
	class baseEngineSVJ_SoundShader
	{
		range = 80;
	};
	class SVJ_Engine_Ext_Rpm0_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Rpm0",1}};
		frequency = "0.95 * ((850 + ((rpm - 850)/(8000/5600))) max 850) / 850";
		volume = "0.85 * 1 * engineOn * 0.4 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) + 2.5*50),(((850+1200)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Ext_Rpm1_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Rpm1",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1200";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.6 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) - 2.5*50),(((850+1200)/2) + 50)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) + 2.5*150),(((1200+1700)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Offload_Ext_Rpm1_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Offload_Rpm1",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1200";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.6 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) - 2.5*50),(((850+1200)/2) + 50)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) + 2.5*150),(((1200+1700)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Ext_Rpm2_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Rpm2",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1700";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.85 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) - 2.5*150),(((1200+1700)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) + 2.5*150),(((1700+2300)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Offload_Ext_Rpm2_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Offload_Rpm2",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1700";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.85 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) - 2.5*150),(((1200+1700)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) + 2.5*150),(((1700+2300)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Ext_Rpm3_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Rpm3",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 2300";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) - 2.5*150),(((1700+2300)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) + 2.5*200),(((2300+3150)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Offload_Ext_Rpm3_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Offload_Rpm3",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 2300";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) - 2.5*150),(((1700+2300)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) + 2.5*200),(((2300+3150)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Ext_Rpm4_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Rpm4",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 3150";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) - 2.5*200),(((2300+3150)/2) + 200)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) + 2.5*200),(((3150+4400)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Offload_Ext_Rpm4_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Offload_Rpm4",2}};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 3150";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) - 2.5*200),(((2300+3150)/2) + 200)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) + 2.5*200),(((3150+4400)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Ext_Rpm5_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Rpm5",2}};
		frequency = "(1 * (850 + ((rpm - 850)/(8000/5600))) / 4400) min (8000/5600)";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) - 2.5*200),(((3150+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Offload_Ext_Rpm5_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_Engine_Ext_Offload_Rpm5",2}};
		frequency = "(1 * (850 + ((rpm - 850)/(8000/5600))) / 4400) min (8000/5600)";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) - 2.5*200),(((3150+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class SVJ_Engine_Start_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_engine_start",1}};
		volume = 0.7;
	};
	class SVJ_Engine_Stop_SoundShader: baseEngineSVJ_SoundShader
	{
		samples[] = {{"SVJ\sounds\SVJ_engine_stop",1}};
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
	class baseSVJ_Engine_EXT_SoundSet
	{
		sound3DProcessingType = "Vehicle_Ext_3DProcessingType";
		distanceFilter = "softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve = "vehicleEngineAttenuationCurve";
		volumeFactor = 1.1;
		spatial = 1;
		loop = 0;
	};
	class SVJ_Engine_Ext_Rpm0_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Ext_Rpm0_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Offload_Ext_Rpm1_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Offload_Ext_Rpm1_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Ext_Rpm1_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Ext_Rpm1_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Ext_Rpm2_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Ext_Rpm2_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Offload_Ext_Rpm2_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Offload_Ext_Rpm2_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Ext_Rpm3_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Ext_Rpm3_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Offload_Ext_Rpm3_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Offload_Ext_Rpm3_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Ext_Rpm4_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Ext_Rpm4_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Offload_Ext_Rpm4_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Offload_Ext_Rpm4_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Ext_Rpm5_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Ext_Rpm5_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_Offload_Ext_Rpm5_SoundSet: baseEngine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Offload_Ext_Rpm5_SoundShader"};
		volumeFactor = 1;
	};
	class SVJ_Engine_start_SoundSet: baseSVJ_Engine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Start_SoundShader"};
		frequencyFactor = 0.95;
		startDelay = 0;
		positionOffset[] = {0,0,1};
	};
	class SVJ_Engine_ext_stop_SoundSet: baseSVJ_Engine_EXT_SoundSet
	{
		soundShaders[] = {"SVJ_Engine_Stop_SoundShader"};
		frequencyFactor = 0.95;
		positionOffset[] = {0,0,1};
	};
};
class CfgMods
{
	class SVJ
	{
		dir = "SVJ";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "SVJ";
		credits = "";
		author = "Habbiblocksberg";
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
				files[] = {"SVJ/scripts/SVJ"};
			};
		};
	};
};
class CfgPatches
{
	class SVJ
	{
		units[] = {"SVJWheel_offroad","SVJWheel_offroad_destroyed","SVJ_driver","SVJ_codriver","SVJ_cargo1","SVJ_cargo2","SVJ_hood","SVJ_trunk","SVJ","JSA_Golden_SVJ","JSA_SVJ_hood_Gold","JSA_SVJ_trunk_Gold","JSA_SVJ_driver_Gold","JSA_SVJ_codriver_Gold"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Vehicles_Wheeled","DZ_Vehicles_Parts","DZ_Sounds_Effects","DZ_Data"};
	};
};
class CfgSlots
{
	class Slot_SVJWheel_offroad_1_1
	{
		name = "SVJWheel_offroad_1_1";
		displayName = "SVJ Front left wheel";
		selection = "wheel_1_1";
		ghostIcon = "wheel";
	};
	class Slot_SVJWheel_offroad_1_2
	{
		name = "SVJWheel_offroad_1_2";
		displayName = "SVJ Rear left wheel";
		selection = "wheel_1_2";
		ghostIcon = "wheel";
	};
	class Slot_SVJWheel_offroad_2_1
	{
		name = "SVJWheel_offroad_2_1";
		displayName = "SVJ Front right wheel";
		selection = "wheel_2_1";
		ghostIcon = "wheel";
	};
	class Slot_SVJWheel_offroad_2_2
	{
		name = "SVJWheel_offroad_2_2";
		displayName = "SVJ Rear right wheel";
		selection = "wheel_2_2";
		ghostIcon = "wheel";
	};
	class Slot_SVJ_driver
	{
		name = "SVJ_driver";
		displayName = "SVJ Front left door";
		selection = "doors_driver";
		ghostIcon = "doorfront";
	};
	class Slot_SVJ_codriver
	{
		name = "SVJ_codriver";
		displayName = "SVJ Front right door";
		selection = "doors_codriver";
		ghostIcon = "doorfront";
	};
	class Slot_SVJ_cargo1
	{
		name = "SVJ_cargo1";
		displayName = "SVJ Rear left door";
		selection = "doors_cargo1";
		ghostIcon = "doorrear";
	};
	class Slot_SVJ_cargo2
	{
		name = "SVJ_cargo2";
		displayName = "SVJ Rear right door";
		selection = "doors_cargo2";
		ghostIcon = "doorrear";
	};
	class Slot_SVJ_hood
	{
		name = "SVJ_hood";
		displayName = "SVJ Hood";
		selection = "doors_Hood";
		ghostIcon = "hood";
	};
	class Slot_SVJ_trunk
	{
		name = "SVJ_trunk";
		displayName = "SVJ Trunk";
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
	class SVJWheel_offroad: CarWheel
	{
		scope = 2;
		model = "\SVJ\proxy\SVJWheel_offroad.p3d";
		displayName = "Lamborghini Aventador SVJ Wheel";
		descriptionShort = "";
		itemSize[] = {6,6};
		rotationFlags = 4;
		repairableWithKits[] = {6};
		repairCosts[] = {30};
		inventorySlot[] = {"SVJWheel_offroad_1_1","SVJWheel_offroad_1_2","SVJWheel_offroad_2_1","SVJWheel_offroad_2_2","SVJWheel_offroad_spare_1","Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2","Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
		radiusByDamage[] = {0,0.3,0.26,0.26,0.9998,0.25,0.9999,0.22};
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
	class SVJWheel_offroad_destroyed: SVJWheel_offroad
	{
		model = "\SVJ\proxy\SVJWheel_offroad_destroyed.p3d";
		radius = 0.22;
		width = 0.2;
		tyreRollResistance = 1;
		tyreRollDrag = 75;
		tyreRoughness = 1.2;
		tyreTread = 0.5;
	};
	class SVJ_driver: CarDoor
	{
		scope = 2;
		displayName = "Lamborghini Aventador SVJ Door front left";
		descriptionShort = "Front left door for Lamborghini Aventador SVJ";
		model = "\SVJ\proxy\SVJ_driver.p3d";
		weight = 15000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "SVJ_driver";
		rotationFlags = 8;
		physLayer = "item_large";
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap.paa"};
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
	class SVJ_codriver: SVJ_driver
	{
		displayName = "Lamborghini Aventador SVJ Door front right";
		descriptionShort = "Front right door Lamborghini Aventador SVJ";
		model = "\SVJ\proxy\SVJ_codriver.p3d";
		inventorySlot = "SVJ_codriver";
		rotationFlags = 4;
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap.paa"};
	};
	class SVJ_hood: SVJ_driver
	{
		scope = 2;
		displayName = "Lamborghini Aventador SVJ Hood";
		descriptionShort = "Hood for Lamborghini Aventador SVJ";
		model = "\SVJ\proxy\SVJ_hood.p3d";
		weight = 10000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "SVJ_hood";
		rotationFlags = 2;
		physLayer = "item_large";
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap.paa"};
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
	class SVJ_trunk: SVJ_driver
	{
		scope = 2;
		displayName = "Lamborghini Aventador SVJ trunk";
		descriptionShort = "Trunk for Lamborghini Aventador SVJ";
		model = "\SVJ\proxy\SVJ_trunk.p3d";
		weight = 10000;
		itemSize[] = {10,10};
		itemBehaviour = 0;
		inventorySlot = "SVJ_trunk";
		rotationFlags = 3;
		physLayer = "item_large";
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap.paa"};
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
	class SVJ_hood_Blue: SVJ_hood
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_blue.paa"};
	};
	class SVJ_trunk_Blue: SVJ_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_blue.paa"};
	};
	class SVJ_driver_Blue: SVJ_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_blue.paa"};
	};
	class SVJ_codriver_Blue: SVJ_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_blue.paa"};
	};
	class SVJ_hood_Red: SVJ_hood
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_red.paa"};
	};
	class SVJ_trunk_Red: SVJ_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_red.paa"};
	};
	class SVJ_driver_Red: SVJ_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_red.paa"};
	};
	class SVJ_codriver_Red: SVJ_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_red.paa"};
	};
	class SVJ_hood_yellow: SVJ_hood
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_yellow.paa"};
	};
	class SVJ_trunk_yellow: SVJ_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_yellow.paa"};
	};
	class SVJ_driver_yellow: SVJ_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_yellow.paa"};
	};
	class SVJ_codriver_yellow: SVJ_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_yellow.paa"};
	};
	class SVJ_hood_white: SVJ_hood
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_white.paa"};
	};
	class SVJ_trunk_white: SVJ_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_white.paa"};
	};
	class SVJ_driver_white: SVJ_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_white.paa"};
	};
	class SVJ_codriver_white: SVJ_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_white.paa"};
	};
	class JSA_SVJ_hood_Gold: SVJ_hood
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_Gold.paa"};
	};
	class JSA_SVJ_trunk_Gold: SVJ_trunk
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_Gold.paa"};
	};
	class JSA_SVJ_driver_Gold: SVJ_driver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_Gold.paa"};
	};
	class JSA_SVJ_codriver_Gold: SVJ_codriver
	{
		hiddenSelections[] = {"camo_door"};
		hiddenSelectionsTextures[] = {"SVJ\data\SVJcampremap_Gold.paa"};
	};
	class SVJ: CarScript
	{
		scope = 2;
		displayname = "Lamborghini Aventador SVJ";
		descriptionShort = "";
		Model = "\SVJ\SVJ.p3d";
		attachments[] = {"CarBattery","Reflector_1_1","Reflector_2_1","CarRadiator","SparkPlug","SVJWheel_offroad_1_1","SVJWheel_offroad_1_2","SVJWheel_offroad_2_1","SVJWheel_offroad_2_2","SVJWheel_offroad_spare_1","SVJ_driver","SVJ_codriver","SVJ_trunk","SVJ_hood","Cassette","underglow01","aplate1"};
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","SVJ\data\SVJcampremap.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","SVJ\data\glossy.rvmat"};
		dashboardMatOn = "SVJ\data\SVJ_dashboardlight.rvmat";
		dashboardMatOff = "SVJ\data\SVJ_dashboardlight_off.rvmat";
		frontReflectorMatOn = "SVJ\data\SVJ_lights.rvmat";
		frontReflectorMatOff = "SVJ\data\SVJ_dashboardlight_off.rvmat";
		brakeReflectorMatOn = "SVJ\data\SVJ_lights.rvmat";
		brakeReflectorMatOff = "SVJ\data\SVJ_dashboardlight_off.rvmat";
		TailReflectorMatOn = "SVJ\data\SVJ_lights.rvmat";
		TailReflectorMatOff = "SVJ\data\SVJ_dashboardlight_off.rvmat";
		ReverseReflectorMatOn = "SVJ\data\SVJ_lights.rvmat";
		ReverseReflectorMatOff = "SVJ\data\SVJ_dashboardlight_off.rvmat";
		fuelCapacity = 80;
		fuelConsumption = 25;
		class Sounds
		{
			thrust = 0.6;
			thrustTurbo = 1;
			thrustGentle = 0.3;
			thrustSmoothCoef = 0.1;
			camposSmoothCoef = 0.03;
			soundSetsFilter[] = {"SVJ_Engine_Offload_Ext_Rpm1_SoundSet","SVJ_Engine_Offload_Ext_Rpm2_SoundSet","SVJ_Engine_Offload_Ext_Rpm3_SoundSet","SVJ_Engine_Offload_Ext_Rpm4_SoundSet","SVJ_Engine_Offload_Ext_Rpm5_SoundSet","SVJ_Engine_Ext_Rpm0_SoundSet","SVJ_Engine_Ext_Rpm1_SoundSet","SVJ_Engine_Ext_Rpm2_SoundSet","SVJ_Engine_Ext_Rpm3_SoundSet","SVJ_Engine_Ext_Rpm4_SoundSet","SVJ_Engine_Ext_Rpm5_SoundSet","offroad_Tires_rock_slow_Ext_SoundSet","offroad_Tires_rock_fast_Ext_SoundSet","offroad_Tires_grass_slow_Ext_SoundSet","offroad_Tires_grass_fast_Ext_SoundSet","offroad_Tires_gravel_slow_Ext_SoundSet","offroad_Tires_gravel_fast_Ext_SoundSet","offroad_Tires_asphalt_slow_Ext_SoundSet","offroad_Tires_asphalt_fast_Ext_SoundSet","offroad_Tires_water_slow_Ext_SoundSet","offroad_Tires_water_fast_Ext_SoundSet","offroad_skid_dirt_SoundSet","offroad_dirt_turn_SoundSet","offroad_Rain_Ext_SoundSet"};
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
				maxSteeringAngle = 36;
				increaseSpeed[] = {0,40,60,30,100,15};
				decreaseSpeed[] = {0,90,60,45,100,20};
				centeringSpeed[] = {0,0,15,27,60,45,100,63};
			};
			class Throttle
			{
				reactionTime = 0.81;
				defaultThrust = 0.85;
				gentleThrust = 0.7;
				turboCoef = 4;
				gentleCoef = 1;
			};
			class Brake
			{
				pressureBySpeed[] = {0,0.85,10,0.7,20,0.5,40,0.4,60,0.43,80,0.46,100,0.33999997,120,0.32};
				reactionTime = 0.25;
				driverless = 0.1;
			};
			class Aerodynamics
			{
				frontalArea = 2;
				dragCoefficient = 0.35;
				downforceCoefficient = 1;
				downforceOffset[] = {0,0.69,-2.74};
			};
			drive = "DRIVE_AWD";
			class Engine
			{
				torqueCurve[] = {904,510,2161,207,3487,266,5072,344,6966,313,8996,0};
				inertia = 0.25;
				frictionTorque = 176;
				rollingFriction = 0.5;
				viscousFriction = 0.1;
				rpmIdle = 1000;
				rpmMin = 1500;
				rpmClutch = 2000;
				rpmRedline = 7950;
			};
			class Clutch
			{
				maxTorqueTransfer = 400;
				uncoupleTime = 0.15;
				coupleTime = 0.25;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.51;
				ratios[] = {1.789,1.2,0.987,0.795,0.657,0.542};
			};
			class CentralDifferential
			{
				ratio = 1.5;
				type = "DIFFERENTIAL_LOCKED";
			};
			class Axles: Axles
			{
				class Front: Front
				{
					maxBrakeTorque = 2700;
					maxHandbrakeTorque = 2200;
					wheelHubMass = 20;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 33700;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.0882;
						travelMaxDown = 0.14;
					};
					class Wheels: wheels
					{
						class Left: Left
						{
							animTurn = "turnfrontleft";
							animRotation = "wheelfrontleft";
							wheelHub = "wheel_1_1_damper_land";
							animDamper = "damper_1_1";
							inventorySlot = "SVJWheel_offroad_1_1";
						};
						class Right: Right
						{
							animTurn = "turnfrontright";
							animRotation = "wheelfrontright";
							wheelHub = "wheel_2_1_damper_land";
							animDamper = "damper_2_1";
							inventorySlot = "SVJWheel_offroad_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque = 3200;
					maxHandbrakeTorque = 2200;
					wheelHubMass = 5;
					wheelHubRadius = 0.15;
					class Differential
					{
						ratio = 4.1;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 33700;
						compression = 2200;
						damping = 7600;
						travelMaxUp = 0.1587;
						travelMaxDown = 0.1587;
					};
					class Wheels: wheels
					{
						class Left: Left
						{
							animTurn = "turnbackleft";
							animRotation = "wheelbackleft";
							wheelHub = "wheel_1_2_damper_land";
							animDamper = "damper_1_2";
							inventorySlot = "SVJWheel_offroad_1_2";
						};
						class Right: Right
						{
							animTurn = "turnbacktright";
							animRotation = "wheelbackright";
							wheelHub = "wheel_2_2_damper_land";
							animDamper = "damper_2_2";
							inventorySlot = "SVJWheel_offroad_2_2";
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
				name = "SVJ Body";
				description = "";
				attachmentSlots[] = {"Reflector_1_1","Reflector_2_1","SVJ_driver","SVJ_codriver","SVJ_trunk","SVJ_hood"};
				icon = "cat_vehicle_body";
			};
			class Chassis
			{
				name = "SVJ Chassis";
				description = "";
				attachmentSlots[] = {"SVJWheel_offroad_1_1","SVJWheel_offroad_1_2","SVJWheel_offroad_2_1","SVJWheel_offroad_2_2"};
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
	class SVJ_Blue: SVJ
	{
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","SVJ\data\SVJcampremap_blue.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","SVJ\data\glossy.rvmat"};
	};
	class SVJ_Red: SVJ
	{
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","SVJ\data\SVJcampremap_red.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","SVJ\data\glossy.rvmat"};
	};
	class SVJ_yellow: SVJ
	{
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","SVJ\data\SVJcampremap_yellow.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","SVJ\data\glossy.rvmat"};
	};
	class SVJ_white: SVJ
	{
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","SVJ\data\SVJcampremap_white.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","SVJ\data\glossy.rvmat"};
	};
	class JSA_Golden_SVJ: SVJ
	{
		scope = 2;
		displayname = "JSA Golden SVJ";
		hiddenSelections[] = {"light_1_1","light_2_1","light_brake_1_2","light_brake_2_2","light_reverse_1_2","light_reverse_2_2","light_1_2","light_2_2","light_dashboard","camo7"};
		hiddenSelectionsTextures[] = {"","","","","","","","","","SVJ\data\SVJcampremap_Gold.paa"};
		hiddenSelectionsMaterials[] = {"","","","","","","","","","SVJ\data\Gold.rvmat"};
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
	class ProxySVJWheel_offroad: ProxyVehiclePart
	{
		model = "SVJ\proxy\SVJWheel_offroad.p3d";
		inventorySlot[] = {"SVJWheel_offroad_1_1","SVJWheel_offroad_1_2","SVJWheel_offroad_2_1","SVJWheel_offroad_2_2","SVJWheel_offroad_spare_1","Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2","Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
	};
	class ProxySVJWheel_offroad_destroyed: ProxyVehiclePart
	{
		model = "SVJ\proxy\SVJWheel_offroad_destroyed.p3d";
		inventorySlot[] = {"SVJWheel_offroad_1_1","SVJWheel_offroad_1_2","SVJWheel_offroad_2_1","SVJWheel_offroad_2_2","SVJWheel_offroad_spare_1","Hatchback_02_Wheel_1_1","Hatchback_02_Wheel_1_2","Hatchback_02_Wheel_2_1","Hatchback_02_Wheel_2_2","Sedan_02_Wheel_1_1","Sedan_02_Wheel_1_2","Sedan_02_Wheel_2_1","Sedan_02_Wheel_2_2"};
	};
	class ProxySVJ_driver: ProxyVehiclePart
	{
		model = "\SVJ\proxy\SVJ_driver.p3d";
		inventorySlot = "SVJ_driver";
	};
	class ProxySVJ_codriver: ProxyVehiclePart
	{
		model = "\SVJ\proxy\SVJ_codriver.p3d";
		inventorySlot = "SVJ_codriver";
	};
	class ProxySVJ_hood: ProxyVehiclePart
	{
		model = "\SVJ\proxy\SVJ_hood.p3d";
		inventorySlot = "SVJ_hood";
	};
	class ProxySVJ_trunk: ProxyVehiclePart
	{
		model = "\SVJ\proxy\SVJ_trunk.p3d";
		inventorySlot = "SVJ_trunk";
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
