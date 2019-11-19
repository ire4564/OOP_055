.SUFFIXES: .cpp .o
OBJECTS = shared_ref.o weak_pointer.o human.o smart_obj.o student.o
TEST_FILE = test.o $(OBJECTS)
CXX = g++
TEST = test

$(TEST) : $(TEST_FILE)
	$(CXX) -o $(TEST) $(TEST_FILE)
clean : 
	rm -rf $(TEST) $(TEST_FILE)

test.o : test.cpp
shared_ref.o : shared_ref.cpp
weak_pointer.o : weak_pointer.cpp
human.o : human.cpp
smart_obj.o : smart_obj.cpp
student.o : student.cpp
