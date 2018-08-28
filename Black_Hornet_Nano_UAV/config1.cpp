class CfgPatches
{
	class tut_helo
	{
		units[]={};
		weapons[]={};
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
		isDiscrete=1;
		skeletonInherit="";
		skeletonBones[]=
		{
			"mainrotor","",
			"tailrotor",""
		};
	};
};
class CfgModels
{
	class Default
	{
		isDiscrete=1;
		sectionsInherit="tut_helo";
		sections[]={};
	};
	class R22
	{
		isDiscrete=1;
		sectionsInherit="";
		sections[]=
		{
			"mainrotor",
			"tailrotor"
		};
		skeletonName="tut_helo_Skeleton";
		class Animations
		{
			class damageHide
			{
				type="hide";
				source="damage";
				selection="damageHide";
			};
			class HideVblades: damageHide
			{
				selection="tailrotor";
			};
			class HideHblades: damageHide
			{
				selection="mainrotor";
			};
			class HRotor
			{
				type="rotationY";
				source="rotorH";
				selection="mainrotor";
				axis="mainrotor osa";
				memory=1;
				sourceAddress="loop";
				minValue=0;
				maxValue=1;
				angle0=0;
				angle1="rad +360";
			};
			class VRotor
			{
				type="rotationX";
				source="rotorV";
				selection="tailrotor";
				axis="tailrotor osa";
				memory=1;
				sourceAddress="loop";
				minValue=0;
				maxValue=1;
				angle0=0;
				angle1="rad +360";
			};
		};
	};
};
class CfgVehicles
{
	class B_UAV_01_F;
	class tut_R22: B_UAV_01_F
	{
		crew="B_UAV_AI";
		vehicleClass="Autonomous";
		faction="BLU_F";
		side=1;
		scope=2;
		author="Aran Anderson";
		authorUrl="http://arananderson.com";
		_generalMacro="B_UAV_01_F";
		displayname="Black Hornet Nano UAV";
		model="\black_hornet_nano_uav\r22.p3d";
		mainRotorSpeed=-7;
		backRotorSpeed=7;
		minMainRotorDive=-7;
		maxMainRotorDive=70;
		neutralMainRotorDive=0;
		minBackRotorDive=0;
		maxBackRotorDive=0;
		neutralBackRotorDive=0;
		fuelCapacity=100;
		fuelConsumptionRate="0.50f";
		maxSpeed=100;
		liftForceCoef=1;
		backRotorForceCoef=5;
		cyclicAsideForceCoef=0.60000002;
		cyclicForwardForceCoef=0.30000001;
		enableGPS=1;
		extCameraPosition[]={0,0.25,-0.69999999};
		icon="\black_hornet_nano_uav\icon.paa";
		hiddenselectionstextures[]=
		{
			"A3\Drones_F\Air_F_Gamma\UAV_01\Data\UAV_01_CO.paa"
		};
		class assembleInfo
		{
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
class cfgMods
{
	author="76561198001087581";
	timepacked="1426995201";
};
