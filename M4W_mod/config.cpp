class CfgSoundShaders
{
	class baseEnginem4w_SoundShader
	{
		range = 80;
	};
	class m4w_engine_ext_start_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_start",
				1
			}
		};
		volume = 0.3499999940395355;
	};
	class m4w_door_open_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_door_open",
				1
			}
		};
		volume = 0.5;
	};
	class m4w_door_close_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_door_close",
				1
			}
		};
		volume = 0.5;
	};
	class m4w_engine_ext_failed_start_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_failed_start",
				1
			}
		};
		volume = 0.5;
	};
	class m4w_engine_ext_stop_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_stop",
				1
			}
		};
		volume = 0.3499999940395355;
	};
	class m4w_engine_ext_rpm0_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_rpm0",
				1
			}
		};
		frequency = "1 * ((850 + ((rpm - 850)/(8000/5600))) max 850) / 850";
		volume = "0.70 * 1 * engineOn * 0.4 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) + 2.5*50),(((850+1200)/2) - 50)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_ext_rpm1_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_rpm1",
				2
			}
		};
		frequency = "0.7 * (850 + ((rpm - 850)/(8000/5600))) / 1200";
		volume = "0.75 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.6 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) - 2.5*50),(((850+1200)/2) + 50)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) + 2.5*150),(((1200+1700)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_offload_ext_rpm1_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_offload_rpm1",
				2
			}
		};
		frequency = "1 * (850 + ((rpm - 850)/(8000/5600))) / 1200";
		volume = "0.75 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.6 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((850+1200)/2) - 2.5*50),(((850+1200)/2) + 50)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) + 2.5*150),(((1200+1700)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_ext_rpm2_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_rpm2",
				2
			}
		};
		frequency = "0.7 * (850 + ((rpm - 850)/(8000/5600))) / 1700";
		volume = "0.80 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.85 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) - 2.5*150),(((1200+1700)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) + 2.5*150),(((1700+2300)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_offload_ext_rpm2_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_offload_rpm2",
				2
			}
		};
		frequency = "0.7 * (850 + ((rpm - 850)/(8000/5600))) / 1700";
		volume = "0.80 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 0.85 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1200+1700)/2) - 2.5*150),(((1200+1700)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) + 2.5*150),(((1700+2300)/2) - 150)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_ext_rpm3_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_rpm3",
				2
			}
		};
		frequency = "0.7 * (850 + ((rpm - 850)/(8000/5600))) / 2300";
		volume = "0.85 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) - 2.5*150),(((1700+2300)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) + 2.5*200),(((2300+3150)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_offload_ext_rpm3_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_offload_rpm3",
				2
			}
		};
		frequency = "0.75 * (850 + ((rpm - 850)/(8000/5600))) / 2300";
		volume = "0.85 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((1700+2300)/2) - 2.5*150),(((1700+2300)/2) + 150)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) + 2.5*200),(((2300+3150)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_ext_rpm4_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_rpm4",
				2
			}
		};
		frequency = "0.75 * (850 + ((rpm - 850)/(8000/5600))) / 3150";
		volume = "0.90 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) - 2.5*200),(((2300+3150)/2) + 200)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) + 2.5*200),(((3150+4400)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_offload_ext_rpm4_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_offload_rpm4",
				2
			}
		};
		frequency = "0.725 * (850 + ((rpm - 850)/(8000/5600))) / 3150";
		volume = "0.90 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((2300+3150)/2) - 2.5*200),(((2300+3150)/2) + 200)]) * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) + 2.5*200),(((3150+4400)/2) - 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_ext_rpm5_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_rpm5",
				2
			}
		};
		frequency = "(0.65 * (850 + ((rpm - 850)/(8000/5600))) / 4400) min (8000/5600)";
		volume = "0.90 * 1 * (thrust factor[0.1,0.45]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) - 2.5*200),(((3150+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_offload_ext_rpm5_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_offload_rpm5",
				2
			}
		};
		frequency = "(0.65 * (850 + ((rpm - 850)/(8000/5600))) / 4400) min (8000/5600)";
		volume = "0.90 * 1 * (thrust factor[0.6,0.2]) * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) - 2.5*200),(((3150+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos)";
	};
	class m4w_engine_ext_Broken_SoundShader: baseEnginem4w_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\m4w_engine_ext_broken",
				2
			}
		};
		frequency = 0.8999999761581421;
		volume = "1 * 1 * (0.7 + 0.3 * (speed factor [10,60])) * engineOn * 1 * ((850 + ((rpm - 850)/(8000/5600))) factor [(((3150+4400)/2) - 2.5*200),(((3150+4400)/2) + 200)]) * ((1 - 0.25*doors) max campos) * (rpm factor[4700,6500])";
	};
	class german_Horn_SoundShader
	{
		samples[] =
		{
			{
				"m4w\sounds\german",
				1
			}
		};
		volume = 1;
		range = 230;
		angeCurve[] =
		{
			{
				0,
				1
			},
			{
				55,
				1
			},
			{
				120,
				0.550000011920929
			},
			{
				170,
				0.3100000023841858
			},
			{
				195,
				0.20999999344348907
			},
			{
				230,
				0
			}
		};
	};
};
class CfgSoundSets
{
	class baseEngine_EXT_SoundSet
	{
		sound3DProcessingType = "Vehicle_Ext_3DProcessingType";
		distanceFilter = "softVehiclesDistanceFreqAttenuationFilter";
		volumeCurve = "vehicleEngineAttenuationCurve";
		volumeFactor = 1;
		spatial = 1;
		loop = 1;
	};
	class m4w_engine_ext_start_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_start_SoundShader"
		};
		frequencyFactor = 0.949999988079071;
		startDelay = 0;
		ositionOffset[] =
		{
			0,
			0,
			1
		};
		loop = 0;
	};
	class m4w_door_open_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_door_open_SoundShader"
		};
		frequencyFactor = 0.949999988079071;
		startDelay = 0;
		ositionOffset[] =
		{
			0,
			0,
			0
		};
		loop = 0;
	};
	class m4w_door_close_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_door_close_SoundShader"
		};
		frequencyFactor = 0.949999988079071;
		startDelay = 0;
		ositionOffset[] =
		{
			0,
			0,
			0
		};
		loop = 0;
	};
	class m4w_engine_ext_failed_start_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_failed_start_SoundShader"
		};
		frequencyFactor = 0.949999988079071;
		startDelay = 0;
		ositionOffset[] =
		{
			0,
			0,
			1
		};
		loop = 0;
	};
	class m4w_engine_ext_stop_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_stop_SoundShader"
		};
		frequencyFactor = 0.949999988079071;
		ositionOffset[] =
		{
			0,
			0,
			1
		};
		loop = 0;
	};
	class m4w_engine_ext_rpm0_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_rpm0_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_offload_ext_rpm1_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_offload_ext_rpm1_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_ext_rpm1_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_rpm1_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_ext_rpm2_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_rpm2_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_offload_ext_rpm2_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_offload_ext_rpm2_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_ext_rpm3_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_rpm3_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_offload_ext_rpm3_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_offload_ext_rpm3_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_ext_rpm4_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_rpm4_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_offload_ext_rpm4_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_offload_ext_rpm4_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_ext_rpm5_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_rpm5_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_offload_ext_rpm5_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_offload_ext_rpm5_SoundShader"
		};
		volumeFactor = 1;
		startDelay = 1;
	};
	class m4w_engine_ext_Broken_SoundSet: baseEngine_EXT_SoundSet
	{
		oundShaders[] =
		{
			"m4w_engine_ext_Broken_SoundShader"
		};
		volumeFactor = 1;
	};
	class baseTruck_01_Character_SoundSet
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class german_Horn_SoundSet: baseTruck_01_Character_SoundSet
	{
		oundShaders[] =
		{
			"german_Horn_SoundShader"
		};
		volumefactor = 0.5;
		loop = 1;
	};
};
class CfgMods
{
	class m4w
	{
		dir = "m4w";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "m4w";
		credits = "";
		author = "";
		authorID = "0";
		version = 1;
		extra = 0;
		type = "mod";
		ependencies[] =
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				iles[] =
				{
					"m4w/scripts/m4w"
				};
			};
		};
	};
};
class CfgPatches
{
	class m4w
	{
		units[] =
		{
			"m4wWheel_offroad",
			"m4wWheel_offroad_destroyed",
			"m4w_driver",
			"m4w_codriver",
			"m4w_cargo1",
			"m4w_cargo2",
			"m4w_hood",
			"m4w_trunk",
			"m4w",
			"M4W_JSA",
			"m4w_hood_JSA",
			"m4w_trunk_JSA",
			"m4w_driver_JSA",
			"m4w_codriver_JSA"
		};
		weapons[] =
		{
		};
		requiredVersion = 0.10000000149011612;
		requiredAddons[] =
		{
			"DZ_Vehicles_Wheeled",
			"DZ_Vehicles_Parts",
			"DZ_Sounds_Effects",
			"DZ_Data"
		};
	};
};
class CfgSlots
{
	class Slot_m4wWheel_offroad_1_1
	{
		name = "m4wWheel_offroad_1_1";
		displayName = "m4w Front left wheel";
		selection = "wheel_1_1";
		ghostIcon = "wheel";
	};
	class Slot_m4wWheel_offroad_1_2
	{
		name = "m4wWheel_offroad_1_2";
		displayName = "m4w Rear left wheel";
		selection = "wheel_1_2";
		ghostIcon = "wheel";
	};
	class Slot_m4wWheel_offroad_2_1
	{
		name = "m4wWheel_offroad_2_1";
		displayName = "m4w Front right wheel";
		selection = "wheel_2_1";
		ghostIcon = "wheel";
	};
	class Slot_m4wWheel_offroad_2_2
	{
		name = "m4wWheel_offroad_2_2";
		displayName = "m4w Rear right wheel";
		selection = "wheel_2_2";
		ghostIcon = "wheel";
	};
	class Slot_m4w_driver
	{
		name = "m4w_driver";
		displayName = "m4w Front left door";
		selection = "doors_driver";
		ghostIcon = "doorfront";
	};
	class Slot_m4w_codriver
	{
		name = "m4w_codriver";
		displayName = "m4w Front right door";
		selection = "doors_codriver";
		ghostIcon = "doorfront";
	};
	class Slot_m4w_cargo1
	{
		name = "m4w_cargo1";
		displayName = "m4w Rear left door";
		selection = "doors_cargo1";
		ghostIcon = "doorrear";
	};
	class Slot_m4w_cargo2
	{
		name = "m4w_cargo2";
		displayName = "m4w Rear right door";
		selection = "doors_cargo2";
		ghostIcon = "doorrear";
	};
	class Slot_m4w_hood
	{
		name = "m4w_hood";
		displayName = "m4w Hood";
		selection = "doors_Hood";
		ghostIcon = "hood";
	};
	class Slot_m4w_trunk
	{
		name = "m4w_trunk";
		displayName = "m4w Trunk";
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
	class m4wWheel_offroad: CarWheel
	{
		scope = 2;
		model = "\m4w\proxy\m4wWheel_offroad.p3d";
		displayName = "m4w Wheel";
		descriptionShort = "";
		temSize[] =
		{
			6,
			6
		};
		rotationFlags = 4;
		epairableWithKits[] =
		{
			6
		};
		epairCosts[] =
		{
			30
		};
		nventorySlot[] =
		{
			"m4wWheel_offroad_1_1",
			"m4wWheel_offroad_1_2",
			"m4wWheel_offroad_2_1",
			"m4wWheel_offroad_2_2",
			"m4wWheel_offroad_spare_1",
			"Hatchback_02_Wheel_1_1",
			"Hatchback_02_Wheel_1_2",
			"Hatchback_02_Wheel_2_1",
			"Hatchback_02_Wheel_2_2",
			"Sedan_02_Wheel_1_1",
			"Sedan_02_Wheel_1_2",
			"Sedan_02_Wheel_2_1",
			"Sedan_02_Wheel_2_2"
		};
		adiusByDamage[] =
		{
			0,
			0.30000001192092896,
			0.25999999046325684,
			0.25999999046325684,
			0.9998000264167786,
			0.25,
			0.9998999834060669,
			0.2199999988079071
		};
		radius = 0.2800000011920929;
		width = 0.20000000298023224;
		tyreOffroadResistance = 0.4300000071525574;
		tyreGrip = 1;
		tyreRollResistance = 0.01600000075995922;
		tyreTread = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					ealthLevels[] =
					{
						{
							1,
							{
								""
							}
						},
						{
							0.699999988079071,
							{
								""
							}
						},
						{
							0.5,
							{
								""
							}
						},
						{
							0.30000001192092896,
							{
								""
							}
						},
						{
							0,
							{
								""
							}
						}
					};
				};
			};
		};
	};
	class m4wWheel_offroad_destroyed: m4wWheel_offroad
	{
		model = "\m4w\proxy\m4wWheel_offroad_destroyed.p3d";
		radius = 0.2199999988079071;
		width = 0.20000000298023224;
		tyreRollResistance = 1;
		tyreRollDrag = 75;
		tyreRoughness = 1.2000000476837158;
		tyreTread = 0.5;
	};
	class m4w_driver: CarDoor
	{
		scope = 2;
		displayName = "m4w Door front left";
		descriptionShort = "Front left door for m4w";
		model = "\m4w\proxy\m4w_driver.p3d";
		weight = 15000;
		temSize[] =
		{
			10,
			10
		};
		itemBehaviour = 0;
		inventorySlot = "m4w_driver";
		rotationFlags = 8;
		physLayer = "item_large";
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_cay.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					ealthLevels[] =
					{
						{
							1,
							{
							}
						},
						{
							0.699999988079071,
							{
							}
						},
						{
							0.5,
							{
							}
						},
						{
							0.30000001192092896,
							{
							}
						},
						{
							0,
							{
							}
						}
					};
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
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					omponentNames[] =
					{
						"dmgzone_window"
					};
					fatalInjuryCoef = 4294967295;
					nventorySlots[] =
					{
					};
				};
				class Doors
				{
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 1;
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					omponentNames[] =
					{
						"dmgzone_doors"
					};
					fatalInjuryCoef = 4294967295;
					nventorySlots[] =
					{
					};
				};
			};
		};
	};
	class m4w_codriver: m4w_driver
	{
		displayName = "m4w Door front right";
		descriptionShort = "Front right door for m4w";
		model = "\m4w\proxy\m4w_codriver.p3d";
		inventorySlot = "m4w_codriver";
		rotationFlags = 4;
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_cay.paa"
		};
	};
	class m4w_hood: m4w_driver
	{
		scope = 2;
		displayName = "m4w Hood";
		descriptionShort = "Hood for m4w";
		model = "\m4w\proxy\m4w_hood.p3d";
		weight = 10000;
		temSize[] =
		{
			10,
			10
		};
		itemBehaviour = 0;
		inventorySlot = "m4w_hood";
		rotationFlags = 2;
		physLayer = "item_large";
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_cay.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					ealthLevels[] =
					{
						{
							1,
							{
								""
							}
						},
						{
							0.699999988079071,
							{
								""
							}
						},
						{
							0.5,
							{
								""
							}
						},
						{
							0.30000001192092896,
							{
								""
							}
						},
						{
							0,
							{
								""
							}
						}
					};
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
	class m4w_trunk: m4w_driver
	{
		scope = 2;
		displayName = "m4w Trunk";
		descriptionShort = "Trunk for m4w";
		model = "\m4w\proxy\m4w_trunk.p3d";
		weight = 10000;
		temSize[] =
		{
			10,
			10
		};
		itemBehaviour = 0;
		inventorySlot = "m4w_trunk";
		rotationFlags = 3;
		physLayer = "item_large";
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_cay.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 15000;
					ealthLevels[] =
					{
						{
							1,
							{
								""
							}
						},
						{
							0.699999988079071,
							{
								""
							}
						},
						{
							0.5,
							{
								""
							}
						},
						{
							0.30000001192092896,
							{
								""
							}
						},
						{
							0,
							{
								""
							}
						}
					};
				};
			};
		};
	};
	class m4w_hood_Blue: m4w_hood
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_blue.paa"
		};
	};
	class m4w_trunk_Blue: m4w_trunk
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_blue.paa"
		};
	};
	class m4w_driver_Blue: m4w_driver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_blue.paa"
		};
	};
	class m4w_codriver_Blue: m4w_codriver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_blue.paa"
		};
	};
	class m4w_hood_Red: m4w_hood
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_red.paa"
		};
	};
	class m4w_trunk_Red: m4w_trunk
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_red.paa"
		};
	};
	class m4w_driver_Red: m4w_driver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_red.paa"
		};
	};
	class m4w_codriver_Red: m4w_codriver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_red.paa"
		};
	};
	class m4w_hood_yellow: m4w_hood
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_yellow.paa"
		};
	};
	class m4w_trunk_yellow: m4w_trunk
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_yellow.paa"
		};
	};
	class m4w_driver_yellow: m4w_driver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_yellow.paa"
		};
	};
	class m4w_codriver_yellow: m4w_codriver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_yellow.paa"
		};
	};
	class m4w_hood_white: m4w_hood
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_white.paa"
		};
	};
	class m4w_trunk_white: m4w_trunk
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_white.paa"
		};
	};
	class m4w_driver_white: m4w_driver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_white.paa"
		};
	};
	class m4w_codriver_white: m4w_codriver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap_white.paa"
		};
	};
	class m4w_hood_black: m4w_hood
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap.paa"
		};
	};
	class m4w_trunk_black: m4w_trunk
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap.paa"
		};
	};
	class m4w_driver_black: m4w_driver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap.paa"
		};
	};
	class m4w_codriver_black: m4w_codriver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wcampremap.paa"
		};
	};
	class m4w_hood_JSA: m4w_hood
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wJSA.paa"
		};
	};
	class m4w_trunk_JSA: m4w_trunk
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wJSA.paa"
		};
	};
	class m4w_driver_JSA: m4w_driver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wJSA.paa"
		};
	};
	class m4w_codriver_JSA: m4w_codriver
	{
		hiddenSelections[] =
		{
			"camo_door"
		};
		hiddenSelectionsTextures[] =
		{
			"m4w\data\m4wJSA.paa"
		};
	};
	class m4w: CarScript
	{
		scope = 2;
		displayname = "m4w";
		descriptionShort = "";
		Model = "\m4w\m4w.p3d";
		aattachments[] =
		{
			"CarBattery",
			"Reflector_1_1",
			"Reflector_2_1",
			"CarRadiator",
			"SparkPlug",
			"m4wWheel_offroad_1_1",
			"m4wWheel_offroad_1_2",
			"m4wWheel_offroad_2_1",
			"m4wWheel_offroad_2_2",
			"m4wWheel_offroad_spare_1",
			"m4w_driver",
			"m4w_codriver",
			"m4w_trunk",
			"m4w_hood",
			"Cassette",
			"underglow01",
			"aplate1"
		};
		hiddenSelections[] =
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo7"
		};
		hiddenSelectionsTextures[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\m4wcampremap_cay.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\glossy.rvmat"
		};
		dashboardMatOn = "m4w\data\m4w_dashboardlight.rvmat";
		dashboardMatOff = "m4w\data\m4w_dashboardlight_off.rvmat";
		frontReflectorMatOn = "m4w\data\m4w_lights.rvmat";
		frontReflectorMatOff = "m4w\data\m4w_dashboardlight_off.rvmat";
		brakeReflectorMatOn = "m4w\data\m4w_lights.rvmat";
		brakeReflectorMatOff = "m4w\data\m4w_dashboardlight_off.rvmat";
		TailReflectorMatOn = "m4w\data\m4w_lights.rvmat";
		TailReflectorMatOff = "m4w\data\m4w_dashboardlight_off.rvmat";
		ReverseReflectorMatOn = "m4w\data\m4w_lights.rvmat";
		ReverseReflectorMatOff = "m4w\data\m4w_dashboardlight_off.rvmat";
		fuelCapacity = 80;
		fuelConsumption = 25;
		class Sounds
		{
			thrust = 0.6000000238418579;
			thrustTurbo = 1;
			thrustGentle = 0.30000001192092896;
			thrustSmoothCoef = 0.10000000149011612;
			camposSmoothCoef = 0.029999999329447746;
			soundSetsFilter[] =
			{
				"m4w_engine_offload_ext_Rpm1_SoundSet",
				"m4w_engine_offload_ext_Rpm2_SoundSet",
				"m4w_engine_offload_ext_Rpm3_SoundSet",
				"m4w_engine_offload_ext_Rpm4_SoundSet",
				"m4w_engine_offload_ext_Rpm5_SoundSet",
				"m4w_engine_ext_Rpm0_SoundSet",
				"m4w_engine_ext_Rpm1_SoundSet",
				"m4w_engine_ext_Rpm2_SoundSet",
				"m4w_engine_ext_Rpm3_SoundSet",
				"m4w_engine_ext_Rpm4_SoundSet",
				"m4w_engine_ext_Rpm5_SoundSet",
				"m4w_engine_ext_Broken_SoundSet",
				"offroad_Tires_rock_slow_Ext_SoundSet",
				"offroad_Tires_rock_fast_Ext_SoundSet",
				"offroad_Tires_grass_slow_Ext_SoundSet",
				"offroad_Tires_grass_fast_Ext_SoundSet",
				"offroad_Tires_gravel_slow_Ext_SoundSet",
				"offroad_Tires_gravel_fast_Ext_SoundSet",
				"offroad_Tires_asphalt_slow_Ext_SoundSet",
				"offroad_Tires_asphalt_fast_Ext_SoundSet",
				"offroad_Tires_water_slow_Ext_SoundSet",
				"offroad_Tires_water_fast_Ext_SoundSet",
				"offroad_skid_dirt_SoundSet",
				"offroad_dirt_turn_SoundSet",
				"offroad_Rain_Ext_SoundSet",
				"offroad_damper_left_SoundSet",
				"offroad_damper_right_SoundSet",
				"m4w_ext_engine_failed_start_SoundSet",
				"m4w_ext_engine_start_SoundSet",
				"m4w_ext_engine_stop_SoundSet"
			};
			oundSetsInt[] =
			{
				"offroad_Tires_Asphalt_Slow_General_Int_SoundSet",
				"offroad_Tires_Asphalt_Fast_General_Int_SoundSet",
				"offroad_Wind_SoundSet"
			};
		};
		class Crew: Crew
		{
			class Driver: Driver
			{
			};
			class CoDriver: CoDriver
			{
			};
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
				animPeriod = 0.800000011920929;
			};
			class SeatCoDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.800000011920929;
			};
			class DoorsDriver
			{
				source = "user";
				initPhase = 0;
				animPeriod = 0.5;
			};
			class DoorsCoDriver: DoorsDriver
			{
			};
			class DoorsHood: DoorsDriver
			{
			};
			class DoorsTrunk: DoorsDriver
			{
			};
			class DoorsCargo1: DoorsDriver
			{
			};
			class DoorsCargo2: DoorsDriver
			{
			};
			class engine_rotate
			{
				initPhase = 0;
				animPeriod = 0.30000001192092896;
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
				initPhase = 0.4002000093460083;
				animPeriod = 1;
			};
			class damper_2_1: damper_1_1
			{
			};
			class damper_1_2
			{
				source = "user";
				initPhase = 0.4002000093460083;
				animPeriod = 1;
			};
			class damper_2_2: damper_1_2
			{
			};
		};
		class SimulationModule: SimulationModule
		{
			class Steering
			{
				maxSteeringAngle = 36;
				ncreaseSpeed[] =
				{
					0,
					40,
					60,
					30,
					100,
					15
				};
				ecreaseSpeed[] =
				{
					0,
					90,
					60,
					45,
					100,
					20
				};
				enteringSpeed[] =
				{
					0,
					0,
					15,
					27,
					60,
					45,
					100,
					63
				};
			};
			class Throttle
			{
				reactionTime = 0.8100000023841858;
				defaultThrust = 0.8500000238418579;
				gentleThrust = 0.699999988079071;
				turboCoef = 4;
				gentleCoef = 1;
			};
			class Brake
			{
				ressureBySpeed[] =
				{
					0,
					0.8500000238418579,
					10,
					0.699999988079071,
					20,
					0.5,
					40,
					0.4000000059604645,
					60,
					0.4300000071525574,
					80,
					0.46000000834465027,
					100,
					0.3399999737739563,
					120,
					0.3199999928474426
				};
				reactionTime = 0.25;
				driverless = 0.10000000149011612;
			};
			class Aerodynamics
			{
				frontalArea = 2;
				dragCoefficient = 0.3499999940395355;
				downforceCoefficient = 1;
				ownforceOffset[] =
				{
					0,
					0.6899999976158142,
					-2.740000009536743
				};
			};
			drive = "DRIVE_AWD";
			class Engine
			{
				orqueCurve[] =
				{
					904,
					510,
					2161,
					207,
					3487,
					266,
					5072,
					344,
					6966,
					313,
					8996,
					0
				};
				inertia = 0.25;
				frictionTorque = 176;
				rollingFriction = 0.5;
				viscousFriction = 0.10000000149011612;
				rpmIdle = 1000;
				rpmMin = 1500;
				rpmClutch = 2000;
				rpmRedline = 7950;
			};
			class Clutch
			{
				maxTorqueTransfer = 400;
				uncoupleTime = 0.15000000596046448;
				coupleTime = 0.25;
			};
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 3.509999990463257;
				atios[] =
				{
					1.7890000343322754,
					1.2000000476837158,
					0.9869999885559082,
					0.7950000166893005,
					0.6570000052452087,
					0.5419999957084656
				};
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
					wheelHubRadius = 0.15000000596046448;
					class Differential
					{
						ratio = 4.099999904632568;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 33700;
						compression = 2100;
						damping = 7500;
						travelMaxUp = 0.08820000290870667;
						travelMaxDown = 0.14000000059604645;
					};
					class Wheels: wheels
					{
						class Left: Left
						{
							animTurn = "turnfrontleft";
							animRotation = "wheelfrontleft";
							wheelHub = "wheel_1_1_damper_land";
							animDamper = "damper_1_1";
							inventorySlot = "m4wWheel_offroad_1_1";
						};
						class Right: Right
						{
							animTurn = "turnfrontright";
							animRotation = "wheelfrontright";
							wheelHub = "wheel_2_1_damper_land";
							animDamper = "damper_2_1";
							inventorySlot = "m4wWheel_offroad_2_1";
						};
					};
				};
				class Rear: Rear
				{
					maxBrakeTorque = 3200;
					maxHandbrakeTorque = 2200;
					wheelHubMass = 5;
					wheelHubRadius = 0.15000000596046448;
					class Differential
					{
						ratio = 4.099999904632568;
						type = "DIFFERENTIAL_OPEN";
					};
					class Suspension
					{
						stiffness = 33700;
						compression = 2200;
						damping = 7600;
						travelMaxUp = 0.15870000422000885;
						travelMaxDown = 0.15870000422000885;
					};
					class Wheels: wheels
					{
						class Left: Left
						{
							animTurn = "turnbackleft";
							animRotation = "wheelbackleft";
							wheelHub = "wheel_1_2_damper_land";
							animDamper = "damper_1_2";
							inventorySlot = "m4wWheel_offroad_1_2";
						};
						class Right: Right
						{
							animTurn = "turnbacktright";
							animRotation = "wheelbackright";
							wheelHub = "wheel_2_2_damper_land";
							animDamper = "damper_2_2";
							inventorySlot = "m4wWheel_offroad_2_2";
						};
					};
				};
			};
		};
		class Cargo
		{
			temsCargoSize[] =
			{
				10,
				100
			};
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
					ealthLevels[] =
					{
						{
							1,
							{
							}
						},
						{
							0.699999988079071,
							{
							}
						},
						{
							0.5,
							{
							}
						},
						{
							0.30000001192092896,
							{
							}
						},
						{
							0,
							{
							}
						}
					};
				};
			};
			class DamageZones
			{
				class Chassis
				{
					displayName = "$STR_CfgVehicleDmg_Chassis0";
					fatalInjuryCoef = 4294967295;
					omponentNames[] =
					{
						"dmgZone_chassis"
					};
					class Health
					{
						hitpoints = 80000;
						transferToGlobalCoef = 0;
					};
					nventorySlots[] =
					{
					};
				};
				class Front
				{
					displayName = "$STR_CfgVehicleDmg_Bumper0";
					fatalInjuryCoef = 4294967295;
					emoryPoints[] =
					{
						"dmgZone_front"
					};
					omponentNames[] =
					{
						"dmgZone_front",
						"dmgZone_bumper_1"
					};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					ransferToZonesNames[] =
					{
						"Fender_1_1",
						"Fender_2_1"
					};
					ransferToZonesCoefs[] =
					{
						0.20000000298023224,
						0.20000000298023224
					};
					nventorySlots[] =
					{
						"CarRadiator"
					};
					nventorySlotsCoefs[] =
					{
						0.25,
						0.30000001192092896,
						0.15000000596046448,
						0.15000000596046448
					};
				};
				class Reflector_1_1
				{
					displayName = "$STR_CfgVehicleDmg_Reflector0";
					fatalInjuryCoef = 4294967295;
					emoryPoints[] =
					{
						"dmgZone_lights_1_1"
					};
					omponentNames[] =
					{
						"dmgZone_lights_1_1"
					};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					ransferToZonesNames[] =
					{
						"Front",
						"Fender_1_1"
					};
					ransferToZonesCoefs[] =
					{
						1,
						1
					};
					nventorySlots[] =
					{
						""
					};
					nventorySlotsCoefs[] =
					{
						1,
						0.10000000149011612
					};
				};
				class Reflector_2_1: Reflector_1_1
				{
					emoryPoints[] =
					{
						"dmgZone_lights_2_1"
					};
					omponentNames[] =
					{
						"dmgZone_lights_2_1"
					};
					ransferToZonesNames[] =
					{
						"Front",
						"Fender_2_1"
					};
					nventorySlots[] =
					{
						""
					};
				};
				class Back
				{
					displayName = "$STR_CfgVehicleDmg_Bumper0";
					fatalInjuryCoef = 4294967295;
					emoryPoints[] =
					{
						"dmgZone_back"
					};
					omponentNames[] =
					{
						"dmgZone_back"
					};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					ransferToZonesNames[] =
					{
						"Fender_1_2",
						"Fender_2_2",
						"Engine"
					};
					ransferToZonesCoefs[] =
					{
						0.20000000298023224,
						0.20000000298023224,
						0.17000000178813934
					};
					nventorySlots[] =
					{
						""
					};
					nventorySlotsCoefs[] =
					{
						0.15000000596046448,
						0.10000000149011612,
						0.10000000149011612
					};
				};
				class Roof
				{
					displayName = "$STR_CfgVehicleDmg_Roof0";
					fatalInjuryCoef = 4294967295;
					emoryPoints[] =
					{
						"dmgZone_roof"
					};
					omponentNames[] =
					{
						"dmgZone_roof"
					};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					nventorySlots[] =
					{
					};
				};
				class Fender_1_1
				{
					displayName = "$STR_CfgVehicleDmg_Fender0";
					fatalInjuryCoef = 4294967295;
					emoryPoints[] =
					{
						"dmgZone_fender_1_1"
					};
					omponentNames[] =
					{
						"dmgZone_fender_1_1"
					};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					ransferToZonesNames[] =
					{
						"Front",
						"Reflector_1_1"
					};
					ransferToZonesCoefs[] =
					{
						0.25,
						0.25
					};
					nventorySlots[] =
					{
						""
					};
					nventorySlotsCoefs[] =
					{
						0.20000000298023224,
						0.15000000596046448,
						0.15000000596046448
					};
				};
				class Fender_2_1: Fender_1_1
				{
					emoryPoints[] =
					{
						"dmgZone_fender_2_1"
					};
					omponentNames[] =
					{
						"dmgZone_fender_2_1"
					};
					ransferToZonesNames[] =
					{
						"Front",
						"Reflector_2_1"
					};
					ransferToZonesCoefs[] =
					{
						0.25,
						0.25
					};
					nventorySlots[] =
					{
						""
					};
					nventorySlotsCoefs[] =
					{
						0.20000000298023224,
						0.10000000149011612,
						0.10000000149011612
					};
				};
				class Fender_1_2: Fender_1_1
				{
					emoryPoints[] =
					{
						"dmgZone_fender_1_2"
					};
					omponentNames[] =
					{
						"dmgZone_fender_1_2"
					};
					ransferToZonesNames[] =
					{
						"Back",
						"Engine",
						"FuelTank"
					};
					ransferToZonesCoefs[] =
					{
						0.25,
						0.07999999821186066,
						0.30000001192092896
					};
					nventorySlots[] =
					{
						""
					};
					nventorySlotsCoefs[] =
					{
						0.20000000298023224,
						0.15000000596046448,
						0.15000000596046448
					};
				};
				class Fender_2_2: Fender_1_1
				{
					emoryPoints[] =
					{
						"dmgZone_fender_2_2"
					};
					omponentNames[] =
					{
						"dmgZone_fender_2_2"
					};
					ransferToZonesNames[] =
					{
						"Back",
						"Engine",
						"FuelTank"
					};
					ransferToZonesCoefs[] =
					{
						0.25,
						0.07999999821186066,
						0.30000001192092896
					};
					nventorySlots[] =
					{
						""
					};
					nventorySlotsCoefs[] =
					{
						0.20000000298023224,
						0.15000000596046448,
						0.15000000596046448
					};
				};
				class WindowFront
				{
					displayName = "$STR_CfgVehicleDmg_Window0";
					fatalInjuryCoef = 4294967295;
					emoryPoints[] =
					{
						"dmgZone_windowFront"
					};
					omponentNames[] =
					{
						"dmgZone_windowFront"
					};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					nventorySlots[] =
					{
					};
					nventorySlotsCoefs[] =
					{
					};
				};
				class WindowBack: WindowFront
				{
					omponentNames[] =
					{
						"dmgZone_windowBack"
					};
					emoryPoints[] =
					{
						"dmgZone_windowBack"
					};
				};
				class Engine
				{
					displayName = "$STR_CfgVehicleDmg_Engine0";
					fatalInjuryCoef = 0.0010000000474974513;
					emoryPoints[] =
					{
						"dmgZone_engine"
					};
					omponentNames[] =
					{
						"dmgZone_engine"
					};
					class Health
					{
						hitpoints = 20000;
						transferToGlobalCoef = 1;
						ealthLevels[] =
						{
							{
								1,
								{
									""
								}
							},
							{
								0.699999988079071,
								{
									""
								}
							},
							{
								0.5,
								{
									""
								}
							},
							{
								0.30000001192092896,
								{
									""
								}
							},
							{
								0,
								{
									""
								}
							}
						};
					};
					nventorySlots[] =
					{
						"CarBattery",
						"SparkPlug"
					};
					nventorySlotsCoefs[] =
					{
						0.10000000149011612,
						0.05000000074505806
					};
				};
				class FuelTank
				{
					displayName = "$STR_CfgVehicleDmg_FuelTank0";
					fatalInjuryCoef = 4294967295;
					omponentNames[] =
					{
						"dmgZone_fuelTank"
					};
					class Health
					{
						hitpoints = 15000;
						transferToGlobalCoef = 0;
						ealthLevels[] =
						{
							{
								1,
								{
								}
							},
							{
								0.699999988079071,
								{
								}
							},
							{
								0.5,
								{
								}
							},
							{
								0.30000001192092896,
								{
								}
							},
							{
								0,
								{
								}
							}
						};
					};
					nventorySlots[] =
					{
					};
					nventorySlotsCoefs[] =
					{
					};
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
						enter[] =
						{
							0,
							0,
							0.699999988079071
						};
					};
					class Cyl3
					{
						radius = 1;
						height = 1.5;
						enter[] =
						{
							0,
							0,
							-0.699999988079071
						};
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
				aattachmentSlots[] =
				{
					"CarBattery",
					"CarRadiator",
					"SparkPlug"
				};
				icon = "cat_vehicle_engine";
			};
			class Body
			{
				name = "m4w Body";
				description = "";
				aattachmentSlots[] =
				{
					"Reflector_1_1",
					"Reflector_2_1",
					"m4w_driver",
					"m4w_codriver",
					"m4w_trunk",
					"m4w_hood"
				};
				icon = "cat_vehicle_body";
			};
			class Chassis
			{
				name = "m4w Chassis";
				description = "";
				aattachmentSlots[] =
				{
					"m4wWheel_offroad_1_1",
					"m4wWheel_offroad_1_2",
					"m4wWheel_offroad_2_1",
					"m4wWheel_offroad_2_2"
				};
				icon = "cat_vehicle_chassis";
			};
			class FoXyRadio
			{
				name = "Radio";
				description = "Radio";
				icon = "default";
				aattachmentSlots[] =
				{
					"Cassette"
				};
			};
			class mebradsattachments
			{
				name = "Underglow and Plate";
				description = "";
				icon = "cat_vehicle_chassis";
				aattachmentSlots[] =
				{
					"underglow01",
					"aplate1"
				};
			};
		};
	};
	class m4w_black: m4w
	{
		hiddenSelections[] =
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo7"
		};
		hiddenSelectionsTextures[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\m4wcampremap.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\glossy.rvmat"
		};
	};
	class m4w_Blue: m4w
	{
		hiddenSelections[] =
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo7"
		};
		hiddenSelectionsTextures[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\m4wcampremap_blue.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\glossy.rvmat"
		};
	};
	class m4w_Red: m4w
	{
		hiddenSelections[] =
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo7"
		};
		hiddenSelectionsTextures[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\m4wcampremap_red.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\glossy.rvmat"
		};
	};
	class m4w_yellow: m4w
	{
		hiddenSelections[] =
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo7"
		};
		hiddenSelectionsTextures[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\m4wcampremap_yellow.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\glossy.rvmat"
		};
	};
	class m4w_white: m4w
	{
		hiddenSelections[] =
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo7"
		};
		hiddenSelectionsTextures[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\m4wcampremap_white.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\glossy.rvmat"
		};
	};
	class M4W_JSA: m4w
	{
		scope = 2;
		displayname = "M4W_JSA";
		hiddenSelections[] =
		{
			"light_1_1",
			"light_2_1",
			"light_brake_1_2",
			"light_brake_2_2",
			"light_reverse_1_2",
			"light_reverse_2_2",
			"light_1_2",
			"light_2_2",
			"light_dashboard",
			"camo7"
		};
		hiddenSelectionsTextures[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\m4wJSA.paa"
		};
		hiddenSelectionsMaterials[] =
		{
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"m4w\data\glossy.rvmat"
		};
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
	class Proxym4wWheel_offroad: ProxyVehiclePart
	{
		model = "m4w\proxy\m4wWheel_offroad.p3d";
		nventorySlot[] =
		{
			"m4wWheel_offroad_1_1",
			"m4wWheel_offroad_1_2",
			"m4wWheel_offroad_2_1",
			"m4wWheel_offroad_2_2",
			"m4wWheel_offroad_spare_1",
			"Hatchback_02_Wheel_1_1",
			"Hatchback_02_Wheel_1_2",
			"Hatchback_02_Wheel_2_1",
			"Hatchback_02_Wheel_2_2",
			"Sedan_02_Wheel_1_1",
			"Sedan_02_Wheel_1_2",
			"Sedan_02_Wheel_2_1",
			"Sedan_02_Wheel_2_2"
		};
	};
	class Proxym4wWheel_offroad_destroyed: ProxyVehiclePart
	{
		model = "m4w\proxy\m4wWheel_offroad_destroyed.p3d";
		nventorySlot[] =
		{
			"m4wWheel_offroad_1_1",
			"m4wWheel_offroad_1_2",
			"m4wWheel_offroad_2_1",
			"m4wWheel_offroad_2_2",
			"m4wWheel_offroad_spare_1",
			"Hatchback_02_Wheel_1_1",
			"Hatchback_02_Wheel_1_2",
			"Hatchback_02_Wheel_2_1",
			"Hatchback_02_Wheel_2_2",
			"Sedan_02_Wheel_1_1",
			"Sedan_02_Wheel_1_2",
			"Sedan_02_Wheel_2_1",
			"Sedan_02_Wheel_2_2"
		};
	};
	class Proxym4w_driver: ProxyVehiclePart
	{
		model = "\m4w\proxy\m4w_driver.p3d";
		inventorySlot = "m4w_driver";
	};
	class Proxym4w_codriver: ProxyVehiclePart
	{
		model = "\m4w\proxy\m4w_codriver.p3d";
		inventorySlot = "m4w_codriver";
	};
	class Proxym4w_hood: ProxyVehiclePart
	{
		model = "\m4w\proxy\m4w_hood.p3d";
		inventorySlot = "m4w_hood";
	};
	class Proxym4w_trunk: ProxyVehiclePart
	{
		model = "\m4w\proxy\m4w_trunk.p3d";
		inventorySlot = "m4w_trunk";
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
		[] +=
		{
		};
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