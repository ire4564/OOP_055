#ifndef VEHICLE
#define VEHICLE

class Vehicle
{
private:
	bool has_name;
	int wheel_number;
	int max_speed;
public:
	Vehicle();
	Vehicle(int, int);
	Vehicle(int, int, bool);

	int get_wheel_number();
	int get_max_speed();
	bool get_has_name();
	const char* get_class_name();
		
	void set_wheel_number(int);
	void set_max_speed(int);
	void set_has_name(bool);

};

#endif
