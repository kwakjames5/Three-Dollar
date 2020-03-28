#include <iostream>
#include "two_sum_class.h"

Solution::Solution() 
{
}

// void Solution::twoSum(Two_sum* two_sum_object)
void Solution::twoSum(int nums[], int target, int size)
{
	int start = 0;
	int end = size;

	//while((start < size/2) || (end > size/2))
	while(start < end )
	{
		if(nums[start] + nums[end] > target)
		{
			end--;
		}

		if(nums[start] + nums[end] < target)
		{
			start++;
		}

		if(nums[start] + nums[end] == target)
		{
			this->output1 = start;
			this->output2 = end;
			
			break;
		}
	}
}

/*
void Solution::twoSum(int nums[], int target, int size)
{	
	bool completeFlag = false;

	for(int i = 0; i < size; i++)
	{
		int diff = target - nums[i];

		// When the array's element is larger than the target,
		if(diff < 0) 
		{
			// Disregard this element since it cannot be added to anything to get a smaller target
			continue; 
		}
		else
		{
			for(int j = 0; j < size; j++)
			{
				// Check for the difference to find the complement element for the target
				if(nums[j] == diff)
				{
					this->output1 = i;
					this->output2 = j;
					completeFlag = true;
				}
			}	
		}

		// Since there is only one viable pair per array given, break the 'i' for loop once the specific pair is found.
		if(completeFlag == true)
		{
			break;
		}
	}
}
*/

int main()
{
	Solution* item = new Solution();

	int inputArray[] = {2, 7, 11, 15};
	int targetNum = 9;
	int arraySize = sizeof(inputArray)/sizeof(int);	

	item->twoSum(inputArray, targetNum, arraySize);

	std::cout << "{" << item->output1  << ", " << item->output2 << "}" << std::endl;

	return 0;
}

/*

with a sorted array, you can do this with a while loop. under the while loop, run it until youre done essentially
start with a start and end indexes at 0 and arraysize respectively. add array[0] and array[array.size()] and check if the
sum is greater or less than the target. if it is more than the target, the array.size() index is too big, so move the index down by 1
and the while loop will keep be going since the flag is not off. keep going untli you either exhaust options or find the complementary index.
vice versa, if the sum is less than the target, the array[0] number may be too small. move that index up and try with a bigger number
potentially at array[1], array[2], etc....
as this keeps going, eventually itll even out and find the pair you want as you either become smaller or bigger

*/