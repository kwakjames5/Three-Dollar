#include "remove_nth_node_end.h"
#include <iostream>

// link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// date: 6/25/2020

// description: given a linked list, remove the nth node from the end and return the list

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) 
{
    ListNode* head_counter = head;
    int list_size = 0;
        
    ListNode* remove_node = head;
    ListNode* temp = NULL;
        
    while(head_counter != NULL)
    {
        list_size++;
        head_counter = head_counter->next;
    }
        
    if(list_size < n)
    {
        return NULL;
    }
    else if(list_size == n)
    {
        return head->next;
    }
    else
    {
        for(int i = 0; i < list_size - n; i++)
        {
            temp = remove_node;
            remove_node = remove_node->next;
        }
        temp->next = remove_node->next;
        return head;
    }
}

int main()
{
    std::cout << "How many linked list elements?" << std::endl;
    int list_count = 0;
    std::cin >> list_count;

    std::cout << "Enter elements:" << std::endl;
    int val;
    std::cin >> val;

    ListNode* head = new ListNode(val);
    ListNode* head_track = head;

    for(int i = 1; i < list_count; i++)
    {
        std::cin >> val;
        ListNode* new_node = new ListNode(val);
        head_track->next = new_node;
        head_track = head_track->next;
    }

    std::cout << "How many elements from the back do you want to go to remove?" << std::endl;
    int n;
    std::cin >> n;

    Solution solution;
    ListNode* result_list = solution.removeNthFromEnd(head, n);

    std::cout << "Resulting list:" << std::endl;
    while(result_list != NULL)
    {
        std::cout << result_list->val << " " << std::endl;
        result_list = result_list->next;
    }

    return 0;
}