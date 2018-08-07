_uavStatic = createVehicle ["tut_R22",position player,[],0,"CAN_COLLIDE"];
waitUntil {alive _uavStatic};
player removeMagazine "Black_Hornet_Nano_UAV_I";