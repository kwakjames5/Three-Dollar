#include "robot_origin.h"
#include <iostream>
#include <string>

// link: https://leetcode.com/problems/robot-return-to-origin/

// date: 7/13/2020

// description: There is a robot starting at position (0, 0), the origin, on a 2D plane. Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
// The move sequence is represented by a string, and the character moves[i] represents its ith move. Valid moves are R (right), L (left), U (up), and D (down). 
// If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.

bool Solution::judgeCircle(std::string moves) 
{
    int horizontal = 0;
    int vertical = 0;
    for(int i = 0; i < moves.size(); i++)
    {
        if(moves[i] == 'U')
        {
            vertical++;
        }
        if(moves[i] == 'D')
        {
            vertical--;
        }
        if(moves[i] == 'L')
        {
            horizontal++;
        }
        if(moves[i] == 'R')
        {
            horizontal--;
        }
    }
        
    if(horizontal == 0 && vertical == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    std::string moves;
    std::cout << "Enter a string composed of D, U, L, R for down, up, left, right (CASE SENSITIVE, USE UPPER CASE): " << std::endl;
    std::cin >> moves;
    Solution solution;
    bool judge_circle = solution.judgeCircle(moves);

    if(judge_circle)
    {
        std::cout << "Robot returned to origin!" << std::endl;
    }
    else
    {
        std::cout << "Robot did not return to origin! Oh NO!!" << std::endl;
    }

    return 0;
}