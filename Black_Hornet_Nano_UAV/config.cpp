class CfgPatches {
    class tut_helo {
     units[] = {};
     weapons[] = {};
     //requiredVersion = 0.100000;
     //requiredAddons[] = {"A3_Air_F"};
    };
   };
   class cfgFunctions 
   {
       class TFR_Hornet
       {
               class tools
               {
                       file = "black_hornet_nano_uav\functions\tools";
                   class createuav {};
                   class pickupuav {};
               };
       };
   };
   class CfgSkeletons
   {
    class tut_helo_Skeleton
    {
     isDiscrete = 1;
     skeletonInherit = "";
     skeletonBones[]=
     {
      "mainrotor", "",
      "tailrotor", ""
     }; 
    };
   };
   
   class CfgModels
   {
    class Default{
     isDiscrete = 1;
     sectionsInherit = "tut_helo";
     sections[] = {};
    };
   
    class R22 {
     isDiscrete = 1;
     sectionsInherit = "";
     sections[] = 
     {
      "mainrotor","tailrotor"
     }; 
   
     skeletonName="tut_helo_Skeleton";
     class Animations
     {
      class damageHide
      {
       type = "hide";
       source = "damage";
       selection = "damageHide";
      };
      class HideVblades: damageHide
      {
       selection = "tailrotor";
      };
      class HideHblades: damageHide
      {
       selection = "mainrotor";
      };
      class HRotor
      {
       type = "rotationY";
       source = "rotorH";
       selection = "mainrotor";
       axis = "mainrotor osa";
       memory = 1;
       sourceAddress = "loop";
       minValue = 0;
       maxValue = 1;
       angle0 = 0;
       angle1 = "rad +360";
      };
      class VRotor
      {
       type = "rotationX";
       source = "rotorV";
       selection = "tailrotor";
       axis = "tailrotor osa";
       memory = 1;
       sourceAddress = "loop";
       minValue = 0;
       maxValue = 1;
       angle0 = 0;
       angle1 = "rad +360";
      };
     }; 
    };
   };
   
   class CfgVehicles {
   
    /* extern */ class B_UAV_01_F;
    class tut_R22: B_UAV_01_F {
     crew = "B_UAV_AI";
     vehicleClass = "Autonomous";
     faction = "BLU_F";
     side = 1;
     scope = 2;
     author = "Aran Anderson";
     _generalMacro = "B_UAV_01_F";
     displayname = "Black Hornet Nano UAV";
     model = "\Black_Hornet_Nano_UAV\r22.p3d";
     
   mainRotorSpeed = -7;	// mainRotorSpeed = -7;
   backRotorSpeed = 7;	// backRotorSpeed = 7;
   minMainRotorDive = -7;	// minMainRotorDive = -7;
   maxMainRotorDive = 70;  // maxMainRotorDive = 70;
   neutralMainRotorDive = 0; // neutralMainRotorDive = 0;
   minBackRotorDive = 0; // minBackRotorDive = 0;
   maxBackRotorDive = 0; // maxBackRotorDive = 0;
   neutralBackRotorDive = 0; // neutralBackRotorDive = 0;
   fuelConsumptionRate="0.20f";
   
   maxSpeed = 100; // maxSpeed = 100;
   liftForceCoef = 1; // liftForceCoef = 1;
   backRotorForceCoef = 5; // backRotorForceCoef = 5;
   cyclicAsideForceCoef = 0.6; // cyclicAsideForceCoef = 2;
   cyclicForwardForceCoef = 0.3; // cyclicForwardForceCoef = 1.2;
       
     extCameraPosition[] = {0,0.25,-0.7}; //{0,1.5,-5};
     //picture = "\A3\Drones_F\Air_F_Gamma\UAV_01\Data\UI\UAV_01_CA.paa";
     icon =  "\Black_Hornet_Nano_UAV\icon.paa";
     hiddenselectionstextures[] = {"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_CO.paa"};
     class Library {
      libTextDesc = "TODO";
     };
     class assembleInfo
     {
         primary=1;
         base="";
         assembleTo="";
         displayName="";
         dissasembleTo[] =
         {
         };
     };
    };
	class Man;
	class CAManBase: Man 
	{
		class ACE_SelfActions 
		{
			class ACE_Equipment
			{
				class black_hornet_place
				{
					displayName="Place UAV";
					condition="'tut_R22_item' in magazines player";
					statement="call TFR_Hornet_fnc_createuav";
					icon="\black_hornet_nano_uav\icon.paa";
					exceptions[]=
					{
						"isNotInside",
						"isNotSitting"
					};
				};
			};
		};
	};
};
   class CfgMagazines {
	class Default;
	class CA_magazine: Default {};
	class TFR_backwardsCompatMagazineBase_FR: CA_magazine {};
	class tut_R22_item: TFR_backwardsCompatMagazineBase_FR {
		scope = 2;
		value = 1;
		count = 1;
		type = 16;
		displayName = "Black Hornet Nano UAV";
		picture = "\black_hornet_nano_uav\icon.paa";
		model = "black_hornet_nano_uav\r22.p3d";
		descriptionShort = "Black Hornet UAV";
		mass = 5;
	   };
};