#include "rem_dup_linked_list.h"

#include <iostream>

// link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// date: 6/19/2020

// description: given a linked list, remove all duplicates in a row and leave only 1 element of that type
// ex) Input: 1->1->2->3->3
// Output: 1->2->3

ListNode* Solution::deleteDuplicates(ListNode* head) 
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
        
    ListNode* first = head;
    ListNode* second = head->next;
        
    while(second)
    {
        if(first->val == second->val)
        {
            first->val = first->next->val;
            first->next = first->next->next;
            second = first->next;
        }
        else
        {
            first = first->next;
            second = second->next;
        }
    }
        
    return head;
}

int main()
{
	std::cout << "Enter linked list size: " << std::endl;
	int size = 0;
	std::cin >> size;

	std:: cout << "Enter elements: " << std::endl;
	int val;
	std::cin >> val;
	ListNode* head_node = new ListNode(val);
	ListNode* head_track = head_node;

	for(int i = 1; i < size; i++)
	{
		std::cin >> val;
		ListNode* new_node = new ListNode(val);
		head_track->next = new_node;
		head_track = head_track->next;
	}

	Solution solution;
	ListNode* result_list = solution.deleteDuplicates(head_node);

	std::cout << "Resulting list: " << std::endl;
	while(result_list != NULL)
	{
		std::cout << result_list->val << " ";
		result_list = result_list->next;
	}

	std::cout << std::endl;

	return 0;
}