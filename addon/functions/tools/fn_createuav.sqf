_uavStatic = createVehicle ["tut_R22", player modelToWorld [0,1.5,0],[],0,"CAN_COLLIDE"]; 
    _pickup = 
	[
        "pickup_uav",
        "Pick up Uav",
        "\A3\ui_f\data\igui\cfg\actions\repair_ca.paa",
        {
            // ace progressbar for picking up
            [
                3,
                [_target],
                {
                    _target = tut_R22;
                    player playAction "medicStop";
                    _target call TFR_Hornet_fnc_pickupuav;
                },
                {player playAction "medicStop";},
                "Picking Up"
            ] call ace_common_fnc_progressBar;
            player playAction "medicStart";
        },
    ] call ace_interact_menu_fnc_createAction;
 
    // add action to all units
    ["tut_R22", 0, ["ACE_MainActions"], _pickup, true] call ace_interact_menu_fnc_addActionToClass;
waitUntil {alive _uavStatic};  
player removeMagazine "tut_R22_item";
