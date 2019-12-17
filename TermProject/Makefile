.SUFFIXES: .cpp .o
#목적 파일 쓰기
OBJECTS = Block.o Manager.o Operate.o
TEST_FILE = main.o $(OBJECTS)
CXX = g++
TEST = main

$(TEST) : $(TEST_FILE)
	$(CXX) -o $(TEST) $(TEST_FILE)
clean :
	rm -rf $(TEST) $(TEST_FILE)

main.o : main.cpp
Block.o : Block.cpp
Check.o : Check.cpp
Manager.o : Manager.cpp
Operate.o : Operate.cpp

#다른 파일들 Complext.o : Complex.cpp 처럼 쓰기

