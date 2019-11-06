#include "Bike.h"

Bike::Bike() : Vehicle() {
}

//w = wheel_number, s = max_speed, b = bike_name, 
//num = bike_num, check= has_name

Bike::Bike(int w, int s, char* b){
        set_wheel_number(w);
        set_max_speed(s);
        set_bike_name(b);

}

Bike::Bike(int w, int s, char* b, int num){
        set_wheel_number(w);
        set_max_speed(s);
        set_bike_name(b);
        set_bike_number(num);

}

Bike::Bike(int w, int s, char* b, int num, bool check){
	set_wheel_number(w);
	set_max_speed(s);
	set_bike_name(b);
	set_bike_number(num);
	set_has_name(check);
}

int Bike::get_bike_number(){
	return bike_number;
}

char* Bike::get_bike_name(){
	return bike_name;
}

const char* Bike::get_class_name(){
	return "bike";
}

void Bike::set_bike_name(char* name){
	bike_name = name;
}

void Bike::set_bike_number(int num){
	bike_number = num;
}
