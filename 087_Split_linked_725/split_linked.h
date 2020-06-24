#ifndef SPLIT_LINKED_H
#define SPLIT_LINKED_H
#include <vector>
#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    std::vector<ListNode*> splitListToParts(ListNode* root, int k);
};

#endif