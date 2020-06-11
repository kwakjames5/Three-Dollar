#include "remove_linked_list_element.h"

// link: https://leetcode.com/problems/remove-linked-list-elements/

// date: 6/10/2020

// description: given a linked list and a value to remove, remove every node with val == to value

ListNode* Solution::removeElements(ListNode* head, int val) 
{
    ListNode* head_track = head;
    
    if(head == NULL)
    {
        return NULL;
    }
        
    while(head != NULL && head->val == val)
    {
        head = head->next;
    }
        
    while(head_track->next != NULL)
    {
        if(head_track->next->val == val)
        {
            head_track->next = head_track->next->next;
            //head_track = head_track->next;
        }
        else
        {
            head_track = head_track->next;
        }
    }
        
    return head;
}

int main()
{
	int count = 0;
	int node_value = 0;
	int remove_val = 0;

	std::cout << "How many linked list elements?: " << std::endl;
	std::cin >> count;

	std::cout << "Enter remove value: " << std::endl;
	std::cin >> remove_val;

	std::cout << "Enter values for the linked list nodes: " << std::endl;
	std::cin >> node_value;

	ListNode* head = new ListNode(node_value);
	ListNode* head_track = head;

	for(int i = 1; i < count; i++)
	{
		std::cin >> node_value;
		ListNode* new_node = new ListNode(node_value);
		head_track->next = new_node;
		head_track = head_track->next;
	}

	Solution solution;
	ListNode* output = solution.removeElements(head, remove_val);

	std::cout << "Linked list after removing " << remove_val << ": " << std::endl;

	while(output != NULL)
	{
		std::cout << output->val << std::endl;
		output = output->next;
	}

	return 0;
}