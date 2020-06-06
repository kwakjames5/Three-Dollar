#include "intersection_linked_list.h"
#include <iostream>
#include <algorithm>
#include <set>

// link: https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/

// date: 6/6/2020

// description: given two linked lists, find and return the node that the two linked lists intersect

ListNode* Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    std::set<ListNode*> visited_nodes;
    ListNode* headA_copy = headA;
    ListNode* headB_copy = headB;
        
    while(headA_copy != NULL)
    {
        visited_nodes.insert(headA_copy);
        headA_copy = headA_copy->next;
    }

    /*
    std::vector<ListNode*>::iterator it;

    for(it = visited_nodes.begin(); it != visited_nodes.end(); it++)
    {
    	std::cout << (*it)->val << std::endl;
    }
    */
    
        
    while(headB_copy != NULL)
    {	
        if(visited_nodes.find(headB_copy) != visited_nodes.end())
        {
        	/*
        	std::cout << headB_copy->val << std::endl;
        	std::cout << "FLAG x" << std::endl;
        	*/
            return headB_copy;
        }
        // std::cout << "FLAG" << std::endl;
        headB_copy = headB_copy->next;
    }

    //std::cout << "FLAG2" << std::endl;
    return NULL;
}

int main()
{
	int input;

	int listA_size;
	std::cout << "Enter size of linked list A:" << std::endl;
	std::cin >> listA_size;

	std::cout << "Enter linked list element: " << std::endl;
	std::cin >> input;
	ListNode* headA_list = new ListNode(input);

	ListNode* headA = headA_list;

	for(int i = 1; i < listA_size; i++)
	{
		std::cin >> input;
		ListNode* new_node = new ListNode(input);
		headA->next = new_node;
		headA = headA->next;
	}

	int listB_size;
	std::cout << "Enter size of linked list B:" << std::endl;
	std::cin >> listB_size;

	std::cout << "Enter linked list element: " << std::endl;
	std::cin >> input;
	ListNode* headB_list = new ListNode(input);

	ListNode* headB = headB_list;

	for(int i = 1; i < listB_size; i++)
	{
		std::cin >> input;
		ListNode* new_node = new ListNode(input);
		headB->next = new_node;
		headB = headB->next;
	}

	Solution* solution;
	ListNode* intersection = solution->getIntersectionNode(headA_list, headB_list);

	std::cout << "EXITED INTERSECTION FLAG" << std::endl;
	//std::cout << intersection->val << std::endl;
	std::cout << "END FLAG" << std::endl;

	return 0;
} 