#define S_GUNPLAY

class CfgPatches {
	class sGunplay {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Weapons_Supports",
			"DZ_Weapons_Muzzles",
			"sFramework"
		};
	};
};

class CfgMods {
	class sGunplay {
		dir = "MyMODS/sGunplay";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "sGunplay";
		credits = "simonvic";
		author = "simonvic";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		
		dependencies[] = {
			"World",
			"Game",
			"Mission"
		};

		inputs = "MyMODS/sGunplay/scripts/data/inputs.xml";

		class defs {
			class imageSets{
				files[]={
					"MyMODS/sGunplay/GUI/imagesets/sGunplay_stats.imageset",
					"MyMODS/sGunplay/GUI/imagesets/sCrosshairs.imageset"
				};
			};
			class gameScriptModule {
				value = "";
				files[] = {
					"MyMODS/sGunplay/scripts/defines",
					"MyMODS/sGunplay/scripts/3_Game"
				};
			};
			class worldScriptModule {
				value = "";
				files[] = {
					"MyMODS/sGunplay/scripts/defines",
					"MyMODS/sGunplay/scripts/4_World"
				};
			};
			class missionScriptModule {
				value = "";
				files[] = {
					"MyMODS/sGunplay/scripts/defines",
					"MyMODS/sGunplay/scripts/5_Mission"
				};
			};
		};
	};
};

class Cfg_sUDE {
	class sGunplay {
		enabled = 1;
		/*
		class DynamicCrosshair {
			precisionMetres = 50;            // How precise the crosshair placement will be (metres)
			smoothness = 0.05;               // How smooth the crosshair movement will be
		};
		class Sway {
			amplitude[] = {1.5, 2.8};        //{X, Y} amplitude of sway with no modifiers
			frequency[] = {0.2, 1.1};        //{X, Y} frequency of sway with no modifiers
			multiplierErect = 1;             // Multiplier to be applied when the player is ERECT
			multiplierCrouched = 0.3;        // Multiplier to be applied when the player is CROUCHED
			multiplierProne = 0.1;           // Multiplier to be applied when the player is PRONE
			decreaseFocusing = 4;            // Amount of sway to reduce while holding breath
			decayPower = 8;                  // How much the percentage left of stamina will impact the sway (SWAY_DECAY_POWER ^ stamina_percentage)
			minimum = 0.2;                   // This minimum will be added during the sway multiplication (even while holding breath)
		};
		class AimingModel {
			resetSpeedInspection = 0.1;      // how fast the camera will reset from inspection angles to default.      0.1 = fast | 0.4 = slow
			resetSpeedFreelook = 0.1;        // how fast the camera will reset from freelook angles to default.        0.1 = fast | 0.4 = slow
			resetSpeedDeadzone = 0.3;        // how fast the camera will reset from deadzone angles to default.        0.1 = fast | 0.4 = slow
			class Filters {
				class AimingModelFilterBase {
					enabled = 1;
				};
				class HipfireDeadzone : AimingModelFilterBase {
					// amount of deadzone to use when hipfiring (in degrees: up, left, right, down)
					amountDegree[] = {
							25,
						-25,   25,
							-25
					};
				};
				class WeaponInertia : AimingModelFilterBase {
					velocityLimit = 250;                       // Velocity limit in inertia build up (degree per second ?)
					speedAcceleration[] = {0.5, 0.5};          // Speed of acceleration (horizontal and vertical) in inertia build up (smoothTime value)
					speedReset[] = {0.2, 0.2};                 // Speed of deceleration (horizontal and vertical) in inertia reset (smoothTime value)
					speedAccelerationHipfire[] = {0.6, 0.6};   // Speed of acceleration (horizontal and vertical) in inertia build up while hipfiring(smoothTime value)
					speedResetHipfire[] = {0.3, 0.3};          // Speed of deceleration (horizontal and vertical) in inertia reset while hipfiring (smoothTime value)
					multiplierBase = 1;                        // Base multiplier of the amount of inertia to be applied
					multiplierMinimum = 1;                     // Minimum value of inertia
					multiplierMaximum = 50;                    // Maximum value of inertia

					// Multiplier of the amount of inertia to be applied when the player is ...
					multiplierStanding = 1.0;   // ... NOT MOVING
					multiplierWalking = 1.1;    // ... WALKING
					multiplierJogging = 1.75;   // ... JOGGING
					multiplierErect = 1;        // ... ERECT
					multiplierCrouched = 0.5;   // ... CROUCHED
					multiplierProne = 0.75;     // ... PRONE
					multiplierHipfire = 1.0;    // ... in HIPFIRE
					multiplierWeaponLength = 2; // Multiplier of the amount of inertia to be applied based on weapon length
				};
				class Movement : AimingModelFilterBase {
					multiplier = 2;    // Overall strength of the movement modifier
					smoothTime = 0.4;  // Smooth time of the movement modifier
					intensity[] = {
						2.5, 2.0,   //yaw strength, yaw frequency
						3.5, 7.5    //pitch strength, pitch frequency
					};
				};
				class Injury : AimingModelFilterBase {
					intensity[] = {
						15.0, 2.0,  //yaw strength, yaw frequency
						2.0, 0.0    //pitch strength, pitch frequency
					};
				};
				class WeaponInteraction : AimingModelFilterBase {
					class Sounds {
						changeZeroing = "combinationlock_changenumber_SoundSet";  // sound to play when changing zeroing
						changeZoom = "combinationlock_changedial_SoundSet";       // sound to play when changing zoom
						//changeFiremode = "";
					};
				};
			};
		};
		class ADS {
			weaponInspectConstraintsDegree[] = {
					10,
				-35,   35,
				    -5
			};
			freelookConstraintsDegree[] = {
					45,
				-45,   45,
				   -45
			};
			timeToADS = 0.4;                        // Entering ADS
			timeFromADS = 0.3;                      // Exiting ADS
			time3rd = -0.2;                         // Summed to timeToADS
			timeBackupSight = 0.25;                 // Opting to backup sight and viceversa
			movementMisalignmentStrength = 2;       // how strong is misalignment caused by movement
			movementMisalignmentFrequency = 1.15;   // how fast is misalignment caused by movement
			movementMisalignmentSmoothness = 0.3;   // how smooth is misalignment caused by movement
			lensActivationDelayMS = -250;           // Delay in milliseconds for the optic lens (PiP) activation
			hideClothingDelayMS = -200;             // Delay in milliseconds to hide the clothing
			lensStrengthConstraints[] = {0, 4};     // A zoom boost too high can cause pixellated image and wrong reticles (boost < 3 is recommended)
			fovReductionOptics = 3;                 // FoV reduction when in optics
		};
		class Focus {
			// Focus speed when player is ...
			speedErect = 0.6;    // ... ERECT
			speedCrouched = 0.4; // ... CROUCHED
			speedProne = 0.1;    // ... PRONE
			speedMultiplierNoMagnification = 0.70;  // Focus speed when using a non-magnifying optic
			speedMultiplierIronsight = 0.75;        // Focus speed when using ironsight
			speedReset = 0.2;                       // Focus reset speed
		};
		class Recoil {
			// Recoil control function: coefficient * arctan(recoilControl^3 * steepness)
			recoilControlCoefficient = 0.5;         // Overall impact of the recoil control. Defines the arctan function shape.
			recoilControlSteepness = 4.6;           // Overall impact of the recoil control. Defines the arctan function shape.
			recoilControlMinimum = -1;              // minimum value of recoil control. Used on arctan function.
			recoilControlMaximum = 1;               // maximum value of recoil control. Used on arctan function.
			class Modifiers {
				class RecoilControlModifierBase {
					enabled = 1;
				};
				class Strength : RecoilControlModifierBase {
					weight = 0.25;   // how much the strength (soft skill) will affect recoil control
				};
				class InventoryWeight : RecoilControlModifierBase {
					//@todo add weights
				};
				class Stance : RecoilControlModifierBase {
					// how much the recoil control will be affected when player is ...
					erect = 0.00;     // ... ERECT
					crouched = 0.70;  // ... CROUCHED
					prone = 0.80;     // ... PRONE
				};
				class Movement : RecoilControlModifierBase {
					// how much the recoil control will be affected when player is ...
					standing = 0.00;  // ... NOT MOVING
					walking = -0.30;  // ... WALKING
					jogging = -0.50;  // ... JOGGING
				};
			};
		};
		*/
	};	
};

class cfgVehicles{
	
	class ItemOptics;

	class ACOGOptic: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 0.314, 0.01};
			PPLensProperties[] = {0.314, 0.0, 0.0, 0.2};
		};
	};
	
	class ACOGOptic_6x: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 0.2, 0.01};
			PPLensProperties[] = {0.5, 0.0, 0.0, 0.0};
		};
	};
	

	class PUScopeOptic: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 0.42, 0.007};
			PPLensProperties[] = {0.5, 0.0, 0.0, 0.2};
		};
	};

	class KashtanOptic: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 0.5, 0.05};
			PPLensProperties[] = {0.5, 0.0, 0.0, 0.2};
		};
	};

	class HuntingOptic: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 0.7, 0.05};
			PPLensProperties[] = {0.3, 0.0, 0.0, 0.3};
		};
	};

	class PistolOptic: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 0.47, 0.005};
			PPLensProperties[] = {0.5, 0.0, 0.0, 0.0};
		};
	};

	class PSO1Optic: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 0.34, 0.005};
			PPLensProperties[] = {0.314, 0.0, 0.0, 0.2};
		};
	};

	class PSO11Optic: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 0.34, 0.005};
			PPLensProperties[] = {0.314, 0.0, 0.0, 0.2};
		};
	};

	class KazuarOptic: ItemOptics{
		class OpticsInfo{
			PPMaskProperties[] = {0.0, 0.0, 2.0, 0.05};
			PPLensProperties[] = {-1.0, 0.0, 0.0, 0.0};
		};
	};

	class AugOptic : ItemOptics {
		class OpticsInfo {
			PPMaskProperties[] = {0.0, 0.0, 0.6, 0.01};
			PPLensProperties[] = {0.25, 0.0, 0.0, 0.1};
		};
	};

	class Static;
	class Inventory_Base : Static {
		s_mouse[] = {0.0, 0.0};
		s_hands[] = {0.0, 0.0};
		s_misalignment[] = {0.0, 0.0};
		s_kick = 0.0;
	};
	class M4_OEBttstck : Inventory_Base {
		s_hands[] = {0.45, 0.45};
		s_misalignment[] = {0.15, 0.25};
		s_kick = 0.70;
	};
	class M4_MPBttstck : Inventory_Base {
		s_hands[] = {0.50, 0.50};
		s_misalignment[] = {0.20, 0.30};
		s_kick = 0.72;
	};
	class M4_CQBBttstck : Inventory_Base {
		s_hands[] = {0.45, 0.45};
		s_misalignment[] = {0.25, 0.35};
		s_kick = 0.75;
	};
	class M4_PlasticHndgrd : Inventory_Base {
		s_hands[] = {0.15, 0.15};
		s_misalignment[] = {0.55, 0.50};
	};
	class M4_RISHndgrd : Inventory_Base {
		s_hands[] = {0.20, 0.20};
		s_misalignment[] = {0.55, 0.50};
	};
	class M4_MPHndgrd : Inventory_Base {
		s_hands[] = {0.25, 0.25};
		s_misalignment[] = {0.60, 0.55};
	};
	class AK_WoodBttstck : Inventory_Base {
		s_hands[] = {0.25, 0.25};
		s_misalignment[] = {0.0, 0.25};
		s_kick = 0.75;
	};
	class AK_PlasticBttstck : Inventory_Base {
		s_hands[] = {0.25, 0.25};
		s_misalignment[] = {0.0, 0.25};
		s_kick = 0.75;
	};
	class AK_FoldingBttstck : Inventory_Base {
		s_hands[] = {0.25, 0.25};
		s_misalignment[] = {0.0, 0.25};
		s_kick = 0.75;
	};
	class AK_WoodHndgrd : Inventory_Base {
		s_hands[] = {0.25, 0.10};
		s_misalignment[] = {0.50, 0.50};
	};
	class AK_RailHndgrd : Inventory_Base {
		s_hands[] = {0.25, 0.10};
		s_misalignment[] = {0.50, 0.50};
	};
	class AK_PlasticHndgrd : Inventory_Base {
		s_hands[] = {0.25, 0.10};
		s_misalignment[] = {0.50, 0.50};
	};
	class AK74_WoodBttstck : Inventory_Base {
		s_hands[] = {0.25, 0.25};
		s_misalignment[] = {0.0, 0.25};
		s_kick = 0.75;
	};
	class AK74_Hndgrd : Inventory_Base {
		s_hands[] = {0.25, 0.10};
		s_misalignment[] = {0.50, 0.50};
	};
	class AKS74U_Bttstck : Inventory_Base {
		s_hands[] = {0.50, 0.50};
		s_misalignment[] = {0.20, 0.20};
		s_kick = 0.75;
	};
	class MP5k_StockBttstck : Inventory_Base {
		s_hands[] = {0.50, 0.50};
		s_misalignment[] = {0.0, 0.25};
		s_kick = 0.75;
	};
	class MP5_PlasticHndgrd : Inventory_Base {
		s_hands[] = {0.20, 0.20};
		s_misalignment[] = {0.50, 0.50};
	};
	class MP5_RailHndgrd : Inventory_Base {
		s_hands[] = {0.20, 0.20};
		s_misalignment[] = {0.50, 0.50};
	};
	class MP5_Compensator : Inventory_Base {
		s_misalignment[] = {0.45, 0.05};
	};
	class Mosin_Compensator : Inventory_Base {
		s_hands[] = {0.50, 0.30};
		s_misalignment[] = {0.50, 0.50};
	};
	class PP19_Bttstck : Inventory_Base {
		s_hands[] = {0.25, 0.25};
		s_misalignment[] = {0.0, 0.50};
		s_kick = 0.50;
	};
	class Saiga_Bttstck : Inventory_Base {
		s_hands[] = {0.30, 0.30};
		s_misalignment[] = {0.30, 0.30};
		s_kick = 0.75;
	};
	class Fal_OeBttstck : Inventory_Base {
		s_hands[] = {0.10, 0.50};
		s_misalignment[] = {0.50, 0.50};
		s_kick = 0.75;
	};
	class Fal_FoldingBttstck : Inventory_Base {
		s_hands[] = {0.00, 0.50};
		s_misalignment[] = {0.50, 0.50};
		s_kick = 0.75;
	};
	
};
