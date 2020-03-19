#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "rem_dup_lib.h"


void removeConsecutive(Item* head)
{
	// checks for if list is empty
	if(head == nullptr)
	{
		return; 
	} 

	// checks for when it is last node
    if(head->next == nullptr)
    {
    	return;
    } 
  
  	// checks for duplicates
    if(head->val == head->next->val) 
    { 
    	// set temp to the consecutive 
        // we are trying to get rid of
        Item* temp; 
        temp = head->next; 

        // set the consecutive we are trying 
        // to get rid of as the next consecutive
        head->next = head->next->next; 

        // DEALLOCATES the temporary 
        // consecutive we had (head->next)
        free(temp); 

        // keeps moving forward onto the 
        // next consecutive (if there is one)
        removeConsecutive(head); 
    }
    else 
    {
    	// this is to check for the next number in 
        // the case that two numbers next to eachother are different.
    	// i.e in a list of 1 1 2 2 2, this next 
        // call is to go from the second '1' to the first '2'
        removeConsecutive(head->next);
    }
}

Item* concatenate(Item* head1, Item* head2)
{
	// base case
	if(head1 == nullptr)
	{
		head1 = head2;
	}
	else
	{
		// keeps going until head1 hits nullptr, or the end.
		head1->next = concatenate(head1->next, head2);
	}

	return head1;
}