if (player canAdd "tut_R22_item") then {
   player addMagazine "tut_R22_item";
   deleteVehicle _uavStatic;
} else {
   hint "Not enough space to pickup ";
};
waitUntil {!alive _uavStatic};
	hint "Mini Drone added to inventory";