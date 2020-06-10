#include "linked_list_cycle.h"
#include <iostream>

bool Solution::hasCycle(ListNode *head) 
{
    // if the linked list does not exist or is only one node
    if(head == NULL || head->next == NULL)
    {
        return false;
    }
        
    // two nodes to track a spot on the linked list
    ListNode* slow = head;
    ListNode* fast = head;
        
    // iterate while the faster moving node is still on the linked list
    while(fast && fast->next)
    {
        // since fast and slow both started on head, iterate both to the spots they want to be on
        // they will be moved every time it is available
        fast = fast->next->next;
        slow = slow->next;
            
        // if two nodes moving at a different rate on a linked list eventually equal eachother,
        // that means there is a cycle
        if(slow == fast)
        {
            return true;
        }
    }
        
    // if the loop excecutes, that means fast node reached the end without any intersection w/ the slow node
    return false;
}

int main()
{
    ListNode* head_node = new ListNode(1);
    ListNode* move_node = head_node;

    for(int i = 0; i < 5; i++)
    {
        ListNode* new_node = new ListNode(2);
        move_node->next = new_node;
        move_node = move_node->next;   
    }

    move_node->next = head_node;

    Solution solution;
    bool has_cycle = solution.hasCycle(head_node);


    // CHECKS [1] [2] [2] [2] [2] [2] Linked list that CYCLES BACK TO THE HEAD
    std::cout << "Status: ";
    if(has_cycle == 0)
    {
        std::cout << "Does not have a cycle" << std::endl;
    }
    else if(has_cycle == 1)
    {
        std::cout << "Does have a cycle" << std::endl;
    }

    ListNode* head_node_2 = new ListNode(1);
    ListNode* move_node_2 = head_node;

    for(int i = 0; i < 5; i++)
    {
        ListNode* new_node = new ListNode(2);
        move_node_2->next = new_node;
        move_node_2 = move_node_2->next;   
    }

    has_cycle = solution.hasCycle(head_node_2);


    // CHECKS [1] [2] [2] [2] [2] [2] Linked list with NO CYCLE
    std::cout << "Status: ";
    if(has_cycle == 0)
    {
        std::cout << "Does not have a cycle" << std::endl;
    }
    else if(has_cycle == 1)
    {
        std::cout << "Does have a cycle" << std::endl;
    }

    return 0;
}