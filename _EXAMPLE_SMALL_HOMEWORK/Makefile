all: rem_dup laundry deque_test

rem_dup: rem_dup.cpp rem_dup_lib.o
	g++ -g -Wall -std=c++11 rem_dup.cpp rem_dup_lib.o -o rem_dup

rem_dup_lib.o: rem_dup_lib.h rem_dup_lib.cpp
	g++ -g -Wall -std=c++11 -c rem_dup_lib.cpp -o rem_dup_lib.o

deque_test: deque_test.cpp deque.o
	g++ -g -Wall -std=c++11 deque_test.cpp -o deque_test

laundry: laundry.cpp
	g++ -g -Wall -std=c++11 laundry.cpp -o laundry