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

4/15/2020 1:41 AM EVERYTHING HAS BEEN FIXED

Here is the notes of fixes that were made:

FIXES STEP BY STEP

IMPORTANT DISTINCTION BETWEEN SIZE_T AND INT
- int is from classic C language; size_t was added with newer versions
- int does as I already know
- size_t is different b/c size_t is never negative and it maximizes performance
- it does this b/c "it is typedefed to be a unsigned integer that is just big enough to 
be able to contain the largest sized possible object on the target platform"

TAKEAWAYS:
- SINCE SIZE_T IS USED TO TRACK DYNAMIC SIZES THAT MAY BE TOO LARGE AND NOT FOR RANDOM VARIABLES:
- head_ and tail_ are now changed to int

FIXES:
1) head_ and tail_ are changed to be ints
1a) the reason for this is mostly bc of head_. head_ needs to be tracked as a potential negative at one point in push_front.
head_ and tail_ also interact a lot so standardizing them and making tail_ a int as well helps with later

2) add "this->" in front of the private variables that are being accessed to differentiate them from new ones and to prevent confusion

3) updated the Deque<T>::operator[](size_t i) functions
3a) fixed this by updating how the operator reads in the size_t i. it needed to consider the capacity_ and the circular array part of the problem

4) updated the push_back and push_front functions
4a) for both functions, the most important fixes was to set the indexes seperately as size_t objects. the indexes are updated the same way the operator[] function was changed
4b) another fix was, during the copy from data_ to new_data_, traverse not from 0 to capacity, but from head to tail.
