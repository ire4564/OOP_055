#include "Car.h"

Car::Car() : Vehicle() {

}

Car::Car(int a, int b){
	set_wheel_number(a);
	set_max_speed(b);
}

Car::Car(int a, int b, char* c) {
        set_wheel_number(a);
        set_max_speed(b);
        set_car_name(c);
}


Car::Car(int a, int b, char* c, bool check) {
	set_wheel_number(a);
	set_max_speed(b);
	set_car_name(c);
	set_has_name(check);
}

char* Car::get_car_name() {
	return car_name;	
}

void Car::set_car_name(char* name){
	car_name = name;
}

const char* Car::get_class_name(){
	return "Car";
}
