#ifndef SWAP_NODES_PAIRS_H
#define SWAP_NODES_PAIRS_H
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head);
};

#endif