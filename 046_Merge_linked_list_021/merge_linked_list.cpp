#include "merge_linked_list.h"
#include <iostream>

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    if(l1 == NULL)
    {
        return l2;
    }
        
    if(l2 == NULL)
    {
        return l1;
    }
        
    ListNode* output = NULL;
        
    if(l1->val < l2->val)
    {
        ListNode* temp = new ListNode(l1->val);
        output = temp;
        l1 = l1->next;
    }
    else
    {
        ListNode* temp = new ListNode(l2->val);
        output = temp;
        l2 = l2->next;
    }
        
    ListNode* temp_output = output;
        
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            ListNode* temp = new ListNode(l1->val);
            temp_output->next = temp;
            l1 = l1->next;
        }
        else
        {
            ListNode* temp = new ListNode(l2->val);
            temp_output->next = temp;
            l2 = l2->next;
        }
            
        temp_output= temp_output->next;
    }
        
    while(l1 != NULL)
    {
        ListNode* temp = new ListNode(l1->val);
        temp_output->next = temp;
        l1 = l1->next;
        temp_output= temp_output->next;
    }
        
    while(l2 != NULL)
    {
        ListNode* temp = new ListNode(l2->val);
        temp_output->next = temp;
        l2 = l2->next;
        temp_output= temp_output->next;
    }
    
    return output;
}

int main()
{
	int list_length;
    std::cout << "Enter length of list 1: " << std::endl;
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

    int list_length_2;
    std::cout << "Enter length of list 2: " << std::endl;
    std::cin >> list_length_2;

    int input_2;
    std::cout << "Enter elements: " << std::endl;
    std::cin >> input_2;
    ListNode* head_2 = new ListNode(input_2);

    ListNode* temp_2 = head_2;
    for(int i = 1; i < list_length_2; i++)
    {
        std::cin >> input_2;
        ListNode* temp2 = new ListNode(input_2);
        temp_2->next = temp2;
        temp_2 = temp_2->next;
    }

    Solution* solution;
    ListNode* solution_node = solution->mergeTwoLists(head, head_2);

    std::cout << "Merged List: " << std::endl;
    while(solution_node)
    {
        std::cout << solution_node->val << std::endl;
        solution_node = solution_node->next;
    }

    return 0;
}