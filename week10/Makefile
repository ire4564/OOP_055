.SUFFIXES: .cpp .o

OBJECTS = Vehicle.o Bike.o Car.o

TEST_FILE = main.o $(OBJECTS)

CXX = g++

TEST = test

$(TEST) : $(TEST_FILE)
	$(CXX) -o $(TEST) $(TEST_FILE)

clean: 
	rm -rf $(TEST) $(TEST_FILE)

main.o: main.cpp

Vehicle.o: Vehicle.cpp

Bike.o: Bike.cpp

Car.o: Car.cpp
