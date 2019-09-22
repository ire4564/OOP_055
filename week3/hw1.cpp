#include <iostream>
 
int code() {
	return 0;
}

int bss;

int main() {
	
	int stack = 100;
	
	static int data = 5678;
	int * heap = new int[2];

	std::cout << "code\t" << (void*) code << std::endl;
	std::cout << "Rodata\t" << (void*)"test" << std::endl;
	std::cout << "BSS\t" << &bss << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "HEAP\t" << heap << std::endl;
	std::cout << "Stack\t" << &stack << std::endl;
}

