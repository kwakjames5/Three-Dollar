#include "circular_deque.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/design-circular-deque/

// date: 6/5/2020

// description: design a double ended queue class

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque::MyCircularDeque(int k) {
    cap = k;
    queue = std::vector<int>(k);
    head = 0;
    tail = cap - 1;
}
    
/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool MyCircularDeque::insertFront(int value) {
    if(size == cap)
    {
        std::cout << "Deque is full" << std::endl;
        return false;
    }
    else
    {
        head = (head - 1 + cap)%cap;
        queue[head] = value;
        size++;
    }
        
    return true;
}
    
/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool MyCircularDeque::insertLast(int value) {
    if(size == cap)
    {
        std::cout << "Deque is full" << std::endl;
        return false;
    }
        
    tail = (tail + 1)%cap;
    queue[tail] = value;
    size++;
    
    return true;
}
    
/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool MyCircularDeque::deleteFront() {
    if(size == 0)
    {
        return false;
    }
        
    head = (head + 1) % cap;
    size--;
    return true;
}
    
/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool MyCircularDeque::deleteLast() {
    if(size == 0)
    {
        return false;
    }
        
    tail = (tail - 1 + cap) % cap;
    size--;
    return true;
}
    
/** Get the front item from the deque. */
int MyCircularDeque::getFront() {
    if(size == 0)
    {
        return -1;
    }
    
    return queue[head];
}
    
/** Get the last item from the deque. */
int MyCircularDeque::getRear() {
    if(size == 0)
    {
        return -1;
    }
        
    return queue[tail];
}
    
/** Checks whether the circular deque is empty or not. */
bool MyCircularDeque::isEmpty() {
    if(size == 0)
    {
        std::cout << "Is empty" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Is not empty" << std::endl;
        return false;   
    }
}
    
/** Checks whether the circular deque is full or not. */
bool MyCircularDeque::isFull() {
    if(size == cap)
    {
        std::cout << "Is full" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Is not full" << std::endl;
        return false;
    }
}

int main()
{
    MyCircularDeque deque(3);
    deque.isEmpty();

    deque.insertLast(1);
    deque.insertLast(2);
    deque.insertFront(3);
    deque.insertFront(4);

    std::cout << "Rear: " << deque.getRear() << std::endl;
    deque.isFull();
    deque.deleteLast();
    deque.insertFront(4);
    deque.isFull();
}