uavStatic = createVehicle ["tut_R22", player modelToWorld [0,1.5,0],[],0,"CAN_COLLIDE"];
    pickup = ["Pick_up", "Pick Up Drone", "\A3\ui_f\data\igui\cfg\actions\repair_ca.paa", {call TFR_Hornet_fnc_pickupuav;}, {true}] call ace_interact_menu_fnc_createAction;
    ["tut_R22", 0, ["ACE_MainActions"], pickup, true] call ace_interact_menu_fnc_addActionToClass;
    Recharge = ["Recharge_UAV", "Recharge UAV", "ui\UAV_battery_ca.paa", {call ace_logistics_uavbattery_fnc_RefuelUAV;}, {call ace_logistics_uavbattery_fnc_canRefuelUAV;}] call ace_interact_menu_fnc_createAction;
    ["tut_R22", 0, ["ACE_MainActions"], Recharge, true] call ace_interact_menu_fnc_addActionToClass;
waitUntil {alive uavStatic};  
player removeMagazine "tut_R22_item";
