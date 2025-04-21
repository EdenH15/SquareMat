CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

Main: SquareMat.cpp main.cpp
	$(CXX) $(CXXFLAGS) SquareMat.cpp main.cpp -o Main
	./Main

#test: SquareMat.cpp tests.cpp
#	$(CXX) $(CXXFLAGS) SquareMat.cpp tests.cpp -o Test
#	./Test

valgrind: Main
	valgrind --leak-check=full ./Main

clean:
	rm -f Main Test *.o
