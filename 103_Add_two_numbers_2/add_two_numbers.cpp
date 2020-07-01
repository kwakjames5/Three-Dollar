#include "add_two_numbers.h"
#include <iostream>

// link: https://leetcode.com/problems/add-two-numbers/

// date: 6/30/2020

// description: given two reverse digit numbers represented through linked lists, return the sum in reverse

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result_head = new ListNode(-1);
    ListNode* result_track = result_head;
    int ones, carry, total, val1, val2;
    carry = 0;
        
    while(l1 != NULL || l2 != NULL)
    {
        if(l1 != NULL)
        {
            val1 = l1->val;
            l1 = l1->next;
        }
        else
        {
            val1 = 0;
        }
            
        if(l2 != NULL)
        {
            val2 = l2->val;
            l2 = l2->next;
        }
        else
        {
            val2 = 0;
        }
            
        total = val1 + val2 + carry;
           
        carry = total/10;
        ones = total%10;
            
        ListNode* new_digit = new ListNode(ones);
        result_track->next = new_digit;
        result_track = result_track->next;            
    }
       
    if(carry != 0)
    {
        ListNode* new_digit = new ListNode(carry);
        result_track->next = new_digit;
    }
        
    carry = 0;
      
    return result_head->next;
        
        /*string num_1_str, num_2_str;
        ListNode* l1_track = l1;
        ListNode* l2_track = l2;
        
        while(l1_track != NULL)
        {
            num_1_str.insert(0, 1, l1_track->val + '0');
            l1_track = l1_track->next;
        }
        
        while(l2_track != NULL)
        {
            num_2_str.insert(0, 1, l2_track->val + '0');
            l2_track = l2_track->next;
        }
        
        cout << stoll(num_1_str) << endl;
        cout << stoll(num_2_str) << endl;
        long long sum = stol(num_1_str) + stol(num_2_str);
        
        long long ones_place = sum % 10;
        sum /= 10;
        
        
        ListNode* sum_head = new ListNode(ones_place);
        ListNode* sum_track = sum_head;
        
        while(sum > 0)
        {
            ListNode* new_digit = new ListNode(sum % 10);
            sum_track->next = new_digit;
            sum_track = sum_track->next;
            sum /= 10;
        }
        
        while(sum_head != NULL)
        {
            cout << sum_head->val;
            sum_head = sum_head->next;
        }
        
        return sum_head;
        */
}

int main()
{
	int num_1_size;
	std::cout << "Enter length of first number" << std::endl;
	std::cin >> num_1_size;

	std::cout << "Enter the first number in reverse digit order (ex. 102 will be inputted as 2 -> 0 -> 1)" << std::endl;
	int value;
	std::cin >> value;
	ListNode* head_node_1 = new ListNode(value);
	ListNode* head_track_1 = head_node_1;
	for(int i = 1; i < num_1_size; i++)
	{
		std::cin >> value;
		ListNode* new_node = new ListNode(value);
		head_track_1->next = new_node;
		head_track_1 = head_track_1->next;
	}

	int num_2_size;
	std::cout << "Enter length of second number" << std::endl;
	std::cin >> num_2_size;

	std::cout << "Enter the second number in reverse digit order (ex. 102 will be inputted as 2 -> 0 -> 1)" << std::endl;
	std::cin >> value;
	ListNode* head_node_2 = new ListNode(value);
	ListNode* head_track_2 = head_node_2;
	for(int j = 1; j < num_2_size; j++)
	{
		std::cin >> value;
		ListNode* new_node = new ListNode(value);
		head_track_2->next = new_node;
		head_track_2 = head_track_2->next;
	}

	Solution solution;
	ListNode* sum = solution.addTwoNumbers(head_node_1, head_node_2);

	std::cout << "Sum (reverse digit order): ";
	while(sum != NULL)
	{
		std::cout << sum->val;
		sum = sum->next;
	}

	std::cout << std::endl;

	return 0;

}