#include "convert_binary_linked_list.h"
#include <iostream>
#include <algorithm>
#include <cmath>

// link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

// date: 6/16/2020

// description: given a linked list containing a binary number, convert it to a decimal value

int Solution::getDecimalValue(ListNode* head) 
{
    int output = 0;
        
    ListNode* head_track = head;
    int list_size = 0;
    while(head_track != NULL)
    {
        list_size++;
        head_track = head_track->next;
    }
        
    while(head != NULL)
    {
        output += head->val * pow(2, list_size - 1);
        list_size--;
        head = head->next;
    }
    return output;
}

int main()
{
    std::cout << "Enter size of binary number: " << std::endl;
    int size = 0;
    std::cin >> size;

    std::cout << "Enter binary number digit by digit" << std::endl;
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
    int decimal_val = solution.getDecimalValue(head_node);

    std::cout << "Decimal value: " << decimal_val << std::endl;

    return 0;


}