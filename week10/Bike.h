#ifndef BIKE
#define BIKE
#include "Vehicle.h"

class Bike : public Vehicle 
{
private:
	char *bike_name;
	int bike_number;
public:
	explicit Bike();
	explicit Bike(int, int, char*);
	explicit Bike(int, int, char*, int);
	explicit Bike(int, int, char*, int, bool);

	int get_bike_number();
	char* get_bike_name();
	const char* get_class_name();

	void set_bike_name(char*);
	void set_bike_number(int);

};

#endif
