#include "partition_list.h"
#include <iostream>

// link: https://leetcode.com/problems/partition-list/

// date: 7/10/2020

// description: Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
// You should preserve the original relative order of the nodes in each of the two partitions.

ListNode* Solution::partition(ListNode* head, int x) {
    // before x
    ListNode* before_head = new ListNode(0);
    ListNode* before = before_head;
        
    // after x
    ListNode* after_head = new ListNode(0);
    ListNode* after = after_head;
    while(head != NULL)
    {
       // create a before list and a after list
        if(head->val < x)
        {
            before->next = head;
            before = before->next;
        }
        else
        {
            after->next = head;
            after = after->next;
        }
        
        // progress head after
        head = head->next;
    }
        
     // end the after list
     after->next = NULL;
    // before connects to after here, after_head is not directly used because of how it was declared
    before->next = after_head->next;

    return before_head->next;
        
}

int main()
{
    std::cout << "Enter list size and the number you want to split the list at: " << std::endl;
    int list_size, x;
    std::cin >> list_size >> x;
    std::cout << "Enter values for the list" << std::endl;
    int value;
    std::cin >> value;
    ListNode* head = new ListNode(value);
    ListNode* head_track = head;
    for(int i = 1; i < list_size; i++)
    {
        std::cin >> value;
        ListNode* new_node = new ListNode(value);
        head_track->next = new_node;
        head_track = head_track->next;
    }

    Solution solution;
    ListNode* parted_list = solution.partition(head, x);
    std::cout << "Parted list: " << std::endl;
    while(parted_list != NULL)
    {
        std::cout << parted_list->val << " ";
        parted_list = parted_list->next;
    }
    std::cout << std::endl;
    return 0;
}