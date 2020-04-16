#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "rem_dup_lib.h"


void removeConsecutive(Item* head)
{
    // checks for if list is empty
    // when head is nullptr, it means the list that removeConsecutive is acting on is empty
    if(head == nullptr)
    {
        return; 
    } 

    // checks for when it is last node
    // when head->next is nullptr, it means that the head removeConsecutive is on now is the last node
    if(head->next == nullptr)
    {
        return;
    } 
  
    // checks for duplicates
    // in english: current head's val compared to next head's value
    if(head->val == head->next->val) 
    { 
        // set temp to the consecutive 
        // we are trying to get rid of
        // this is done so that later, temp (head->next aka the duplicate) can be freed
        Item* temp; 
        temp = head->next; 

        // set the consecutive head to the head after it
        // this gets rid of the consecutive head and shifts the list to replace the removed consecutive head
        head->next = head->next->next; 

        // DEALLOCATES the temporary 
        // consecutive we had (head->next)

        // this is where the temp from earlier is freed
        // the space that head->next (which was removed in the above operations) had is now freed
        free(temp); 

        // keeps moving forward onto the 
        // next consecutive (if there is one)

        // call the function again recursively to act on the current head to check for potential more duplicates
        removeConsecutive(head); 
    }
    else 
    {
        // this is to check for the next number in 
        // the case that two numbers next to eachother are different.
        // i.e in a list of 1 1 2 2 2, this next 
        // call is to go from the second '1' to the first '2'

        // this is the recursive call for when the value of next exists but is not a duplicate
        // when the next node is not a duplicate, recursively act on the next head
        // this will move the removeConsecutive function further down the list it is acting on
        removeConsecutive(head->next);
    }
}

// purpose of concatenate is to combine two linked lists with head1 and head2
// it must recursively iterate through every node in the first linked list with head1
// once it is at the end of the first linked list (or when head1 finally reaches null), it can combine with head2, which is the start of the second linked list
// the second linked list does not have to be iterated through since it is simply being attached to the end of the first list
Item* concatenate(Item* head1, Item* head2)
{
    // base case
    if(head1 == nullptr)
    {
        // this is what happens when you either hit the end of the first linked list or when the first linked list was empty
        head1 = head2;
    }
    else
    {
        // keeps going until head1 hits nullptr, or the end.
        head1->next = concatenate(head1->next, head2);
    }

    // return head1 after it has been concatenated and has the head2 linked list attached
    return head1;
}