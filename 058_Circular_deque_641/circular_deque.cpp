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
        std::cout << "Deque is full" << std::endl << std::endl;
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
        std::cout << "Deque is full" << std::endl << std::endl;
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
    std::cout << std::endl;
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
    std::cout << std::endl;
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
        std::cout << "Is empty" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Is not empty" << std::endl << std::endl;
        return false;   
    }
}
    
/** Checks whether the circular deque is full or not. */
bool MyCircularDeque::isFull() {
    if(size == cap)
    {
        std::cout << "Is full" << std::endl << std::endl;
        return true;
    }
    else
    {
        std::cout << "Is not full" << std::endl << std::endl;
        return false;
    }
}

int main()
{
    std::cout << "Enter capacity: " << std::endl;
    int cap;
    std::cin >> cap;
    MyCircularDeque deque(cap);

    int exit_flag = -1;

    while(exit_flag == -1)
    {
        std::cout << "OPTIONS: " << std::endl;
        std::cout << "1: insertFront(num)" << std::endl;
        std::cout << "2: insertLast(num)" << std::endl;
        std::cout << "3: deleteFront()" << std::endl;
        std::cout << "4: deleteLast()" << std::endl;
        std::cout << "5: getFront()" << std::endl;
        std::cout << "6: getRear()" << std::endl;
        std::cout << "7: isEmpty()" << std::endl;
        std::cout << "8: isFull()" << std::endl;
        std::cout << "9: QUIT" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter: " << std::endl;
        int option;
        std::cin >> option;

        if(option == 1)
        {
            std::cout << std::endl;
            std::cout << "Enter num to add: " << std::endl;
            int input;
            std::cin >> input;
            deque.insertFront(input);
        }

        if(option == 2)
        {
            std::cout << std::endl;
            std::cout << "Enter num to add: " << std::endl;
            int input;
            std::cin >> input;
            deque.insertLast(input);
        }

        if(option == 3)
        {
            deque.deleteFront();
        }

        if(option == 4)
        {
            deque.deleteLast();
        }

        if(option == 5)
        {
            std::cout << "Front: " << deque.getFront() << std::endl << std::endl;
        }

        if(option == 6)
        {
            std::cout << "Rear: " << deque.getRear() << std::endl << std::endl;
        }

        if(option == 7)
        {
            deque.isEmpty();
            std::cout << std::endl;
        }

        if(option == 8)
        {
            deque.isFull();
            std::cout << std::endl;
        }

        if(option == 9)
        {
            exit_flag = 1;
            break;
        }
    }

}