#include "reveal_cards.h"
#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>

// link: https://leetcode.com/problems/reveal-cards-in-increasing-order/

// date: 7/8/2020

// description: In a deck of cards, every card has a unique integer.  You can order the deck in any order you want.
// Initially, all the cards start face down (unrevealed) in one deck.
// Now, you do the following steps repeatedly, until all cards are revealed:
// Take the top card of the deck, reveal it, and take it out of the deck.
// If there are still cards in the deck, put the next top card of the deck at the bottom of the deck.
// If there are still unrevealed cards, go back to step 1.  Otherwise, stop.
// Return an ordering of the deck that would reveal the cards in increasing order.
// The first entry in the answer is considered to be the top of the deck.

// Input: [17,13,11,2,3,5,7]
// Output: [2,13,3,11,5,17,7]

std::vector<int> Solution::deckRevealedIncreasing(std::vector<int>& deck) {
    // sort the deck in reverse order by using rbegin and rend (reverse begin and reverse end)
    std::sort(deck.rbegin(), deck.rend());
        
    // use deque bc we need front and back for this one
    std::deque<int> new_deck;
    // start the new deck by pushing the first element (aka the largest) of the deck
    new_deck.push_back(deck[0]);
        
    for(int i = 1; i < deck.size(); i++)
    {
        // store the last element in the deck so far
        int temp = new_deck.back();
        
        // this is the pattern that happens every iteration of revealing the deck cards
        // the last element is removed, then it is pushed to the front, followed by the next card in the deck
        // which should be the next largest number
        // continue for all numbers
        new_deck.pop_back();
        new_deck.push_front(temp);
        new_deck.push_front(deck[i]);
    }
        
    std::vector<int> return_deck;
    std::deque<int>::iterator deque_it;
    for(deque_it = new_deck.begin(); deque_it != new_deck.end(); deque_it++)
    {
        return_deck.push_back(*deque_it);
    }
    return return_deck;
}

int main()
{
    std::vector<int> deck;
    std::cout << "How many cards?" << std::endl;
    int deck_count;
    std::cin >> deck_count;
    std::cout << "Enter value of cards" << std::endl;
    int input;
    for(int i = 0; i < deck_count; i++)
    {
        std::cin >> input;
        deck.push_back(input);
    }
    Solution solution;

    std::vector<int> new_deck = solution.deckRevealedIncreasing(deck);

    std::cout << "New deck:" << std::endl;
    for(int j = 0; j < deck_count; j++)
    {
        std::cout << new_deck[j] << " ";
    }

    std::cout << std::endl;

    return 0;
}