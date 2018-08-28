if (player canAdd "tut_R22_item") then {
   player addMagazine "tut_R22_item";
    ["tut_R22", 0, ["ACE_MainActions"], pickup, true] call ace_interact_menu_fnc_removeActionFromClass;
    ["tut_R22", 0, ["ACE_MainActions"], Recharge, true] call ace_interact_menu_fnc_removeActionFromClass;
   deleteVehicle uavStatic;
} else {
   hint "Not enough space to pickup ";
};
waitUntil {!alive uavStatic};
	hint "Mini Drone added to inventory";