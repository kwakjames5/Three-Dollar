#include "reverse_linked_list.h"
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// link: https://leetcode.com/problems/reverse-linked-list/

/*
	Was originally going to make this entire problem here
	was not sure how to use ListNode or set up a starting linked list

	copy paste code into leetcode solver, 100% success result
*/

ListNode* Solution::reverseList(ListNode* head)
{
	ListNode* prev = NULL;

	while(head != NULL)
	{	
		// store head->next
		ListNode* next = head->next;

		// make the current node go opposite direction
		head->next = prev;

		// move previous to current head and head to next
		// then continue with while loop 
		prev = head;
		head = next;
	}

	// change the ListNode to prev
	// prev is now the start of the reversed linked list
	head = prev;

	return head;
}

int main()
{
	int list_length;
	std::cout << "Enter length of list: " << std::endl;
	std::cin >> list_length;

	int input;
	std::cout << "Enter elements: " << std::endl;
	std::cin >> input;
	ListNode* head = new ListNode(input);

	ListNode* temp = head;
	for(int i = 1; i < list_length; i++)
	{
		std::cin >> input;
		ListNode* temp2 = new ListNode(input);
		temp->next = temp2;
		temp = temp->next;
	}

	Solution* solution;
	ListNode* solution_node = solution->reverseList(head);

	std::cout << "Reverse: " << std::endl;
	while(solution_node)
	{
		std::cout << solution_node->val << std::endl;
		solution_node = solution_node->next;

	}

	return 0;
}