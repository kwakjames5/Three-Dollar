#include "odd_even_list.h"
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

ListNode* Solution::oddEvenList(ListNode* head) 
{
    if(head == NULL)
    {
        return NULL;
    }
    
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* even_head = even;
    
    while(odd->next && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
         even = even->next;
    }
    
    odd->next = even_head;
    
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
    ListNode* solution_node = solution->oddEvenList(head);

    std::cout << "Merged List: " << std::endl;
    while(solution_node)
    {
        std::cout << solution_node->val << std::endl;
        solution_node = solution_node->next;
    }

    return 0;
}