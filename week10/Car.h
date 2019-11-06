#ifndef CAR
#define CAR
#include "Vehicle.h"

class Car : public Vehicle
{
private:
	char* car_name;
public:
	Car();
	Car(int, int);
	Car(int, int, char*);
	Car(int, int, char*, bool);
	
	char * get_car_name();
	const char* get_class_name();

	void set_car_name(char*);
};

#endif
