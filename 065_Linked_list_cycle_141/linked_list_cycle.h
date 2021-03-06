#ifndef LINKED_LIST_CYCLE_H
#define LINKED_LIST_CYCLE_H
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head);
};

#endif