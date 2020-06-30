#include "sort_linked_list.h"
#include <iostream>

// link: https://leetcode.com/problems/sort-list/

// date: 6/29/2020

// description: given a list, sort it to be in order

ListNode* Solution::merge(ListNode* l, ListNode* r)
{
    // return node will be used to return the merged list
    ListNode* return_node = new ListNode(0);
      
    // curr is used to traverse through the merged list as we make it
    ListNode* curr = return_node;
        
    // while both of the lists still have nodes
    while(l != NULL && r != NULL)
    {
        // add to the return_node list by adding the smaller values first to create a sorted list
        if(l->val < r->val)
        {
            curr->next = l;
            l = l->next;
        }
        else
        {
            curr->next = r;
            r = r->next;
        }
        
        // traverse curr as well
        curr = curr->next;
    }

    // for leftover node values   
    if(l != NULL)
    {
        curr->next = l;
        l = l->next;
    }
        
    if(r != NULL)
    {
        curr->next = r;
        r = r->next;
    }
        
    return return_node->next;
}
   
ListNode* Solution::sortList(ListNode* head) 
{
    // if the list does not exist or cannot be sorted
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
      
    ListNode* temp = head;
    ListNode* slow = head;
    ListNode* fast = head;
        
    // head is the head of the first half of the list
    // temp is the end of the first half of the list
    // slow is the head of the second half of the list
    // fast is the end of the second half of the list
    while(fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
        
    // since temp is now the end of the first half of the list,
    // it should no longer have a node after it
   
    temp->next = NULL;
     
    ListNode* left = sortList(head);
    ListNode* right = sortList(slow);
       
    return merge(left, right);
}

int main()
{
	std::cout << "How many linked list elements?" << std::endl;
	int list_size = 0;
	std::cin >> list_size;
	std::cout << "Enter elements: " << std::endl;
	int val = 0;
	std::cin >> val;
	ListNode* head = new ListNode(val);
	ListNode* head_track = head;

	for(int i = 1; i < list_size; i++)
	{
		std::cin >> val;
		ListNode* new_node = new ListNode(val);
		head_track->next = new_node;
		head_track = head_track->next;
	}

	Solution solution;
	ListNode* sorted_list = solution.sortList(head);

	std::cout << "The sorted list: " << std::endl;
	while(sorted_list != NULL)
	{
		std::cout << sorted_list->val << std::endl;
		sorted_list = sorted_list->next;
	}

	return 0;
}