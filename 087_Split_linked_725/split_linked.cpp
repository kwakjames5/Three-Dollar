#include "split_linked.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/split-linked-list-in-parts/

// date: 6/23/2020

// description: given a linked list and a value, split the linked list into equal parts of size of value

std::vector<ListNode*> Solution::splitListToParts(ListNode* root, int k) 
{
    std::vector<ListNode*> return_list;
        
    ListNode* list_size_track = root;
    int list_size = 0;
    while(list_size_track != NULL)
    {
        list_size++;
        list_size_track = list_size_track->next;
    }
        
    int part_size = list_size / k;
    int remainder = list_size % k;
        
    ListNode* list_track = root;
        
    for(int i = 0; i < k; i++)
    {
        return_list.push_back(list_track);
         
        if(remainder > 0)
        {
            for(int i = 1; i < part_size + 1; i++)
            {
                list_track = list_track->next;
            }
        }
        else
        {
            for(int i = 1; i < part_size; i++)
            {
                list_track = list_track->next;
            }
        }
          
        if(list_track != NULL)
        {
            ListNode* temp = list_track->next;
            list_track->next = NULL;
            list_track = temp;
        }
            
        remainder--;
    }
        
    return return_list;
}

int main()
{
	std::cout << "How many elements in the linked list?: " << std::endl;
	int linked_list_size;
	std::cin >> linked_list_size;

	std::cout << "Enter elements: " << std::endl;
	int val;
	std::cin >> val;

	ListNode* head = new ListNode(val);
	ListNode* head_track = head;

	for(int i = 1; i < linked_list_size; i++)
	{
		std::cin >> val;
		ListNode* new_node = new ListNode(val);
		head_track->next = new_node;
		head_track = head_track->next;
	}

	std::cout << "How many parts do you want to split it into?: " << std::endl;
	int split;
	std::cin >> split;

	Solution solution;
	std::vector<ListNode*> split_list = solution.splitListToParts(head, split);

	std::cout << "Resulting lists:" << std::endl;

	for(int i = 0; i < split_list.size(); i++)
	{
		std::cout << "List " << i + 1 << ": ";
		ListNode* temp_node = split_list[i];

		while(temp_node != NULL)
		{
			std::cout << temp_node->val << " ";
			temp_node = temp_node->next;
		}

		std::cout << std::endl;
	}

	return 0;
}