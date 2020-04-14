deque_test can be run after make all
deque_test contains a deque of ints which uses different functions defined in deque.h
this test is used to check which parts of deque.h work

stack.h is a type of deque that has overloaded functions
stack.h doesn't really serve any real purpose other than to test
whether of not stack.h properly inherits private functions of deque.h
based on how this is set up, I am presuming that part of this summer assignment
must have been to implement the inheritence properly so that stack.h works

laundry.cpp works fine as it is
it only accesses the parts of deque.h that work at the moment
in order to run it, in the terminal type this:

./laundry laundryin.txt

deque.h has been fixed and re annotated
one function was left completely broken from the summer and I am working on fixing it

pop_front() as of 4/14/2020 1:16 AM is not fixed