#include "palindrome_linked_list.h"
#include <iostream>

// link: https://leetcode.com/problems/palindrome-linked-list/

// date: 6/12/2020

// description: given a linked list head, determine if it is a palindrome or not (palindrome is a number that reads the same forwards as backwards)

// ex) 112233332211 is a palindrome because it is the same forwards and backwards

bool Solution::isPalindrome(ListNode* head) 
{
    std::string store = "";
    ListNode* head_track = head;
        
    while(head_track != NULL)
    {
        store += head_track->val;
        head_track = head_track->next;
    }
       
    int string_size = store.size();
    std::string compare = "";
    for(int i = string_size - 1; i >= 0; i--)
    {
        compare += store[i];
    }
        
    if(store == compare)
    {
        return true;
    }
    else
    {
        return false;
    }
        
        
        /*
        while(head != NULL)
        {
            if(head->val == '-')
            {
                head = head->next;
                i++;
            }
            else
            {
                if(head->val != store[string_size - 1 - i])
                {
                    return false;
                }
                head = head->next;
                i++;
            }
        }
        
        return true;
        */
}

int main()
{
	int size = 0;
	int val = 0;

	std::cout << "Enter size of linked list: " << std::endl;
	std::cin >> size;

	std::cout << "Enter linked list elements: " << std::endl;
	std::cin >> val;

	ListNode* head = new ListNode(val);
	ListNode* head_track = head;

	for(int i = 1; i < size; i++)
	{
		std::cin >> val;
		ListNode* new_node = new ListNode(val);
		head_track->next = new_node;
		head_track = head_track->next;
	}

	Solution solution;
	if(solution.isPalindrome(head))
	{
		std::cout << "Is palindrome" << std::endl;
	}
	else
	{
		std::cout << "Is not palindrome" << std::endl;
	}

	return 0;
}