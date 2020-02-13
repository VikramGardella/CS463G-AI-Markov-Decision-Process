SOURCES = main.cpp
OBJECTS = main.o

MDP: main.cpp
	g++ -o MDP main.cpp


CXXFLAGS = -std=c++11 -D_GNU_SOURCE -Wall
