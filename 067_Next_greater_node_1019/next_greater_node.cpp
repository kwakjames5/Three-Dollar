#include "next_greater_node.h"
#include <iostream>
#include <vector>

// link: https://leetcode.com/problems/next-greater-node-in-linked-list/

// date: 6/10/2020

// description: given a linked list, for each node, push into a vector the next closest value in the linked list which has a val larger than its current value

// ex) [2,7,4,3,5]
// output: [7,0,5,5,0]
// explanation: 7 > 2, nothing in the list after the second node has val > 7, 3 < 4 5 > 4, 5 > 3, nothing after 5

std::vector<int> Solution::nextLargerNodes(ListNode* head) 
{
    std::vector<int> return_vector;
    
    if(head == NULL)
    {
        return_vector.push_back(NULL);
        return return_vector;
    }
        
    if(head->next == NULL)
    {
        return_vector.push_back(0);
        return return_vector;
    }
        
    while(head != NULL)
    {
        int curr_num = head->val;
        ListNode* head_track = head;
        head_track = head_track->next;
        while(head_track != NULL)
        {
            if(head_track->val > curr_num)
            {
                head->val = head_track->val;
                break;
            }
            head_track = head_track->next;
        }
           
        if(head_track == NULL)
        {
            head->val = 0;
        }
            
        return_vector.push_back(head->val);
           
        head = head->next;
    }
        
    return return_vector;
}

int main()
{
    int size;
    int node_value;

    std::cout << "Enter size of linked list:" << std::endl;
    std::cin >> size;

    std::cout << "Enter values for linked list nodes: " << std::endl;
    std::cin >> node_value;

    ListNode* head = new ListNode(node_value);
    ListNode* head_track = head;

    for(int i = 1; i < size; i++)
    {
        std::cin >> node_value;
        ListNode* new_node = new ListNode(node_value);
        head_track->next = new_node;
        head_track = head_track->next;
    }

    Solution solution;
    std::vector<int> output = solution.nextLargerNodes(head);

    std::cout << "Resulting vector: " << std::endl;
    for(int i = 0; i < output.size(); i++)
    {
        std::cout << output[i] << std::endl;
    }

    return 0;
}