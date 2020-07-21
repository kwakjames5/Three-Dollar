#include "decompress_rle_list.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/decompress-run-length-encoded-list/

// date: 7/20/2020

// description: We are given a list nums of integers representing a list compressed with run-length encoding.

//Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val concatenated in a sublist. 
//Concatenate all the sublists from left to right to generate the decompressed list.

//Return the decompressed list.

std::vector<int> Solution::decompressRLElist(std::vector<int>& nums) 
{
    std::vector<int> return_list;
    for(int i = 0; i < nums.size() - 1; i += 2)
    {
        int freq = nums[i];
        int val = nums[i + 1];
        for(int j = 0; j < freq; j++)
        {
            return_list.push_back(val);
        }
    }
        
    return return_list;
}

int main()
{
    std::vector<int> nums;
    std::cout << "Enter array size (EVEN ONLY): " << std::endl;
    int arr_size = 0;
    std::cin >> arr_size;
    std::cout << "Enter elements to decompress in order of FREQUENCY then VALUE" << std::endl;
    int input;
    for(int i = 0; i < arr_size; i++)
    {
        std::cin >> input;
        nums.push_back(input);
    }

    Solution solution;
    std::vector<int> output = solution.decompressRLElist(nums);

    std::cout << "Output: ";
    for(int j = 0; j < output.size(); j++)
    {
        std::cout << output[j] << " ";
    }

    std::cout << std::endl;

    return 0;
}