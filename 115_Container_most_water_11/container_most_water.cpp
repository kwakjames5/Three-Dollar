#include "container_most_water.h"
#include <vector>
#include <algorithm>
#include <iostream>

// link: https://leetcode.com/problems/container-with-most-water/

// date: 7/7/2020

// description: Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
// Find two lines, which together with x-axis forms a container, such that the container contains the most water.

int Solution::maxArea(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int left_max = 0;
    int right_max = 0;
    int total = 0;
        
    while(left < right)
    {
        left_max = std::max(left_max, height[left]);
        right_max = std::max(right_max, height[right]);
        if(left_max > right_max)
        {
            total = std::max(total, right_max * (right - left));
            right--;
        }
        else
        {
            total = std::max(total, left_max * (right - left));
            left++;
        }
    }
        
    return total;
}

int main()
{
    std::vector<int> height;
    std::cout << "Enter vector size" << std::endl;
    int vec_size;
    std::cin >> vec_size;
    int input;
    std::cout << "Enter heights" << std::endl;
    for(int i = 0; i < vec_size; i++)
    {
        std::cin >> input;
        height.push_back(input);
    }

    Solution solution;
    int max_area = solution.maxArea(height);

    std::cout << "Max area: " << max_area << std::endl;

    return 0;
}