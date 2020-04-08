all: majors

majors: majors.cpp setops.o
	g++ -g -Wall -std=c++11 majors.cpp setops.o -o majors

setops.o: setops.h setops.cpp
	g++ -g -Wall -std=c++11 -c setops.cpp -o setops.o


remove:
	rm majors
	rm setops.o