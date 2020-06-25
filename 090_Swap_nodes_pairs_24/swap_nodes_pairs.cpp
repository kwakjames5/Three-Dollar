#include "swap_nodes_pairs.h"
#include <iostream>

// link: https://leetcode.com/problems/swap-nodes-in-pairs/

// date: 6/24/2020

// description: given a linked list, return a linked list in which every two nodes are swapped
// ex) list: [1, 2, 3, 4, 5, 6]
// output: [2, 1, 4, 3, 6, 5]

ListNode* Solution::swapPairs(ListNode* head) {
        
    ListNode* new_head = new ListNode(0);
    new_head->next = head;
        
    ListNode* list_track = new_head;
    
    while(list_track->next != NULL && list_track->next->next != NULL)
    {
        ListNode* swap_node_1 = list_track->next;
        ListNode* swap_node_2 = list_track->next->next;
        swap_node_1->next = swap_node_2->next;
        list_track->next = swap_node_2;
        list_track->next->next = swap_node_1;
        list_track = list_track->next->next;
    }
        
    return new_head->next;
}

int main()
{
	std::cout << "How many elements in the linked list?: " << std::endl;
	int list_size = 0;
	std::cin >> list_size; 
	std::cout << "Enter elements: " << std::endl;
	int val;
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
	ListNode* result_list = solution.swapPairs(head);

	std::cout << "Resulting list: " << std::endl;
	while(result_list != NULL)
	{
		std::cout << result_list->val << " ";
		result_list = result_list->next;
	}

	std::cout << std::endl;

	return 0;
}