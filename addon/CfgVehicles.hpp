class CfgVehicles
{
    class ACE_Actions
    class ACE_MainActions
    class tut_R22
    {
        class ACE_Actions: ACE_Actions
	    {
		    class ACE_MainActions: ACE_MainActions
		    {
                class black_hornet_pickup
			    {
				    displayName="Pickup";
				    statement="call TFR_Hornet_fnc_pickupuav";
				    icon="\black_hornet_nano_uav\icon.paa";
			    };
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