#include <iostream>

int main() {
	char target[] = "Kim DoHee";
	long b[55];
	int a = 18;
	int i = 471;
	int *c = new int[802];
	char * copy = "is no no";
	char name = 'a';
/*
	std::cout <<"target : " <<&target << std::endl;	
	std::cout << "b[0] : " << &b[0] << std::endl;
	std::cout << "b[55] : " << &b[55] << std::endl;
	std::cout << "a : " << &a << std::endl;
	std::cout << "i : " << &i << std::endl;
	std::cout << "c : " << &c << std::endl;
	std::cout << "copy : " << &copy << std::endl;
	std::cout << "name : " << &name << std::endl;
*/

	std:: cout <<  &name+i << std::endl;
}
