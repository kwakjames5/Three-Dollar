#include "height_checker.h"
#include <vector>
#include <algorithm>

// link: https://leetcode.com/problems/height-checker/

// date: 7/8/2020

// description: Students are asked to stand in non-decreasing order of heights for an annual photo.
// Return the minimum number of students that must move in order for all students to be standing in non-decreasing order of height.

int Solution::heightChecker(std::vector<int>& heights) 
{
    std::vector<int> sorted_heights = heights;
    std::sort(sorted_heights.begin(), sorted_heights.end());
    int move_count = 0;
    for(int i = 0; i < heights.size(); i++)
    {
        if(sorted_heights[i] != heights[i])
        {
            move_count++;
        }
    }
        
    return move_count;
}

int main()
{
    std::vector<int> heights;
    std::cout << "How many heights?" << std::endl;
    int height_count = 0;
    std::cin >> height_count;
    std::cout << "Enter heights" << std::endl;
    int input;
    for(int i = 0; i < height_count; i++)
    {
        std::cin >> input;
        heights.push_back(input);
    }

    Solution solution;
    int move = solution.heightChecker(heights);

    std::cout << "Moves needed to organize the heights: " << move << std::endl;

    return 0; 
}