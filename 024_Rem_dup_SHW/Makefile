all: rem_dup rem_dup_lib.o

rem_dup: rem_dup.cpp rem_dup_lib.o
	g++ -g -Wall -std=c++11 rem_dup.cpp rem_dup_lib.o -o rem_dup

rem_dup_lib.o: rem_dup_lib.h rem_dup_lib.cpp
	g++ -g -Wall -std=c++11 -c rem_dup_lib.cpp -o rem_dup_lib.o

clean:
	rm rem_dup
	rm rem_dup_lib.o
	rm output.txt