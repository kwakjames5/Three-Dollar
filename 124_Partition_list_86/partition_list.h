#ifndef PARTITION_LIST_H
#define PARTITION_LIST_H
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* partition(ListNode* head, int x);
};

#endif