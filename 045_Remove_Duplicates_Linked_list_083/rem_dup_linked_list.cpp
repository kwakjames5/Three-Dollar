#include "rem_dup_linked_list.h"
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

// link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/*
    Was originally going to make this entire problem here
    was not sure how to use ListNode or set up a starting linked list

    copy paste code into leetcode solver, 100% success result
*/

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
        
    ListNode* first = head;
    ListNode* second = head->next;
        
    while(second)
    {
        if(first->val == second->val)
        {
            first->val = first->next->val;
            first->next = first->next->next;
            second = second->next;
        }
        else
        {
            first = first->next;
            second = second->next;
        }
    }
        
       return head;
}

int main()
{

}