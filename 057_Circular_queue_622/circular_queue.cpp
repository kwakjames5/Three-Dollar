#include "circular_queue.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/design-circular-queue/

// date: 6/5/2020

// description: design a circular one ended queue class

/** Initialize your data structure here. Set the cap of the queue to be k. */
MyCircularQueue::MyCircularQueue(int k) {
    queue = std::vector<int>(k);
    cap = k;
}
   
/** Insert an element into the circular queue. Return true if the operation is successful. */
bool MyCircularQueue::enQueue(int value) {
    if(head == -1)
    {
        queue[0] = value;
        tail = 1%cap;
        head = 0;
    }
    else if(head == tail)
    {
    	std::cout << "Cannot add, queue full" << std::endl << std::endl;
        return false;
    }
    else
    {
        queue[tail] = value;
        tail = (tail + 1)%cap;
    }
        
    return true;
}
    
/** Delete an element from the circular queue. Return true if the operation is successful. */
bool MyCircularQueue::deQueue() {
    if(head == -1)
    {
        return false;
    }
        
    // since circular queues are FIFO, this is a pop_front function
    // by moving the head 1 forward and modulo for cap
    // head is now on the next element with the previous first being removed
    head = (head + 1)%cap;
        
    if(head == tail)
    {
        head = -1;
        tail = -1;
    }
        
    return true;
}
    
/** Get the front item from the queue. */
int MyCircularQueue::Front() {
    if(head == -1)
    {
        return -1;
    }
        
    return queue[head];
}
    
/** Get the last item from the queue. */
int MyCircularQueue::Rear() {
    if(head == -1)
    {
        return -1;
    }
    else if(tail > 0)
    {
        return queue[tail - 1];
    }
    else
    {
        return queue.back();
    }

}
    
/** Checks whether the circular queue is empty or not. */
bool MyCircularQueue::isEmpty() {
    if(head == -1)
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
    
/** Checks whether the circular queue is full or not. */
bool MyCircularQueue::isFull() {
    if(head != -1 && head == tail)
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
	MyCircularQueue queue(cap);

	int exit_flag = -1;

	while(exit_flag == -1)
	{
		std::cout << "OPTIONS: " << std::endl;
		std::cout << "1: enQueue(num)" << std::endl;
		std::cout << "2: deQueue()" << std::endl;
		std::cout << "3: Front()" << std::endl;
		std::cout << "4: Rear()" << std::endl;
		std::cout << "5: isEmpty()" << std::endl;
		std::cout << "6: isFull()" << std::endl;
		std::cout << "7: QUIT" << std::endl;
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
			queue.enQueue(input);
			std::cout << std::endl;
		}

		if(option == 2)
		{
			queue.deQueue();
		}

		if(option == 3)
		{
			std::cout << "Front: " << queue.Front() << std::endl;
		}

		if(option == 4)
		{
			std::cout << "Rear: " << queue.Rear() << std::endl;
		}

		if(option == 5)
		{
			queue.isEmpty();
		}

		if(option == 6)
		{
			queue.isFull();
		}

		if(option == 7)
		{
			exit_flag = 1;
			break;
		}
	}

}
