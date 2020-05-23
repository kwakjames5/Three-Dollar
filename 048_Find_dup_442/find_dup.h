#ifndef FIND_DUP_H
#define FIND_DUP_H

#include <iostream>
#include <vector>

// 1 ≤ a[i] ≤ n (n = size of array)
// This means that every element in the nums array is between 1 and the size of the array
// IMPORTANT ^^

// Logic: each element in nums can be used to reference a different index on nums by doing element - 1
// example: nums[3] = 5; 5 - 1 = 4 -> nums[4] = 2
// find an element in the nums array (5 in index 3). when 1 is subtracted (5 - 1 = 4), the difference
// can be used to reference the 4th index in the nums array

// since the most an element can appear in the nums array is maximum TWICE, we can keep track of if a element
// in the nums array has already been checked by modifying the element that is being referenced by the difference
//example: nums[3] = 5; 5 - 1 = 4 -> nums[4] = 2 * -1 = -2
// now, the next time a nums[i] has a 5, we can check if the element at the index it is referring to has already been
// modified
// if it has, push it into the output_array

class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int>& nums);
};

#endif