#ifndef NEXT_GREATER_NODE_H
#define NEXT_GREATER_NODE_H
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

class Solution {
public:
    std::vector<int> nextLargerNodes(ListNode* head);
};

#endif