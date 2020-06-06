#ifndef INTERSECTION_LINKED_LIST_H
#define INTERSECTION_LINKED_LIST_H
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};

#endif