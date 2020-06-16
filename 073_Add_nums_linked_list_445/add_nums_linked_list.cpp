#include "add_nums_linked_list.h"
#include <iostream>
#include <stack>

// link: https://leetcode.com/problems/add-two-numbers-ii/

// date: 6/15/2020

// description: given two linked list numbers, add them and return a Linked list head that reads the sum of the two numbers

// ex) size 4; 7->2->4->3 (7243)
//     size 3; 5->6->4 (564)
//     result: 7243 + 564 = 7807
//     result linked list: 7->8->0->7

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    // use stacks in this problem
    // stacks are LIFO (last in first out)
    // this means that if a linked list is put in order into a stack
    // the stack will read it out as the reverse
    // aka linked list: 1->2->3->4 (1234)
    // goes into stack like: 1, 2, 3, 4; 4 is the first number to
    // come out when the stack's top() or pop() is called
        
        
    // two stacks to keep track of both l1 and l2
    std::stack<int> stack1;
    std::stack<int> stack2;
        
    // while the list exists, push the element into the stack, then increment
    while(l1 != NULL)
    {
        stack1.push(l1->val);
        l1 = l1->next;
    }
        
    while(l2 != NULL)
    {
        stack2.push(l2->val);
        l2 = l2->next;
    }
        
    // root will be used to keep track of the most recent digit that was accessed
    // temp will be used to store new ListNodes for new digits
    // carry is used to keep track of any carrying during addition
    ListNode* root = NULL;
    ListNode* temp = NULL;
    int carry = 0;
        
    // continue the sum operations as long as either of the
    // numbers are still not fully done or there is still something left in carry
    while(!stack1.empty() || !stack2.empty() || carry > 0)
    {
        // initial sum for new digit
        int sum = 0;
       
        // adds the last element from the stack AKA the one closest to the ones digit
        // after adding to sum, pop the digit from the stack
        if(!stack2.empty())
        {
            sum += stack2.top();
            stack2.pop();
        }
            
        if(!stack1.empty())
        {
            sum += stack1.top();
            stack1.pop();
        }
            
        // add carry to the sum
        // sum is now done, so a new digit ListNode must be made
        sum += carry;
            
        // set temp to a new ListNode with value of the remainder of sum/10
        temp = new ListNode(sum%10);
        // since the linked list must read from left to right
        // aka 1234 reads like 1->2->3->4
        // the newest digit wants to be in front of the last digit
        // so, set the newest digit's (temp) next to the root
        // for every iteration, the root is updated to be temp
        // this way, the next iteration, when temp is overwritten,
        // that new temp's next will be the last iteration's temp
        // leading to the left to right reading linked list
        temp->next = root;
        root = temp;
            
        // since the ones place of the sum was used for the last digit,
        // any tens place remainders must be stored in carry for the next digit
        // ex) sum = 12; 12%10 = 2; 12/10 = 1; carry = 1; temp->val = 2
        carry = sum/10;
    }
      
    return root;
}

int main()
{
    std::cout << "Enter size of number 1: " << std::endl;
    int size1 = 0;
    std::cin >> size1;

    std::cout << "Enter the number you want digit by digit (ex. 1999 goes in like 1 9 9 9 in that order): " << std::endl;
    int val = 0;
    std::cin >> val;

    ListNode* head_node_1 = new ListNode(val);
    ListNode* head_track_1 = head_node_1;

    for(int i = 1; i < size1; i++)
    {
        std::cin >> val;
        ListNode* new_node = new ListNode(val);
        head_track_1->next = new_node;
        head_track_1 = head_track_1->next;
    }

    std::cout << "Enter size of number 2: " << std::endl;
    int size2 = 0;
    std::cin >> size2;

    std::cout << "Enter the number you want digit by digit (ex. 1999 goes in like 1 9 9 9 in that order): " << std::endl;
    std::cin >> val;

    ListNode* head_node_2 = new ListNode(val);
    ListNode* head_track_2 = head_node_2;

    for(int i = 1; i < size2; i++)
    {
        std::cin >> val;
        ListNode* new_node = new ListNode(val);
        head_track_2->next = new_node;
        head_track_2 = head_track_2->next;
    }

    Solution solution;
    ListNode* result = solution.addTwoNumbers(head_node_1, head_node_2);

    std::cout << "Sum:  " << std::endl;
    while(result != NULL)
    {
        std::cout << result->val;
        result = result->next;
    }

    std::cout << std::endl;

    return 0;
}