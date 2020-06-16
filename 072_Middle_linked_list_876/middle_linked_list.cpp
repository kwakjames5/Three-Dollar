#include "middle_linked_list.h"
#include <iostream>

// link: https://leetcode.com/problems/middle-of-the-linked-list/

// date: 6/15/2020

// description: given a linked list, return its middle element

ListNode* Solution::middleNode(ListNode* head) 
{
    ListNode* head_track = head;
    int list_size = 0;
        
    while(head_track != NULL)
    {
        list_size++;
        head_track = head_track->next;
    }
        
    for(int i = 0; i < list_size/2; i++)
    {
        head = head->next;
    }
        
    return head;
}

int main()
{
    std::cout << "Enter linked list size:" << std::endl;
    int size = 0;
    std::cin >> size;

    std::cout << "Enter elements:" << std::endl;
    int val = 0;
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
    ListNode* middle_node = solution.middleNode(head_node);

    std::cout << "Middle element: " << middle_node->val << std::endl;
    
    return 0;
}