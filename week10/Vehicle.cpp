#include "Vehicle.h"

Vehicle::Vehicle() {
	set_has_name(false);
}

Vehicle::Vehicle(int a, int b) {
	set_wheel_number(a);
	set_max_speed(b);
}

Vehicle::Vehicle(int a, int b, bool check){
	set_wheel_number(a);
	set_max_speed(b);
	set_has_name(check);
}

int Vehicle::get_wheel_number(){
	return wheel_number;
}

int Vehicle::get_max_speed(){
	return max_speed;
}

bool Vehicle::get_has_name(){
	return has_name;
}

const char* Vehicle::get_class_name(){
	return "vehicle";
}

void Vehicle::set_wheel_number(int num){
	wheel_number = num;
}

void Vehicle::set_max_speed(int speed){
	max_speed = speed;
}

void Vehicle::set_has_name(bool name){
	has_name = name;
}



