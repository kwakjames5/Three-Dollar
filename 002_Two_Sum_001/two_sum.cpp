///////////////////////////////////////////////////////////////////////////////////

// Function: Two sum

// Description : Parses through an array and looks for exactly one pair of elements that add up to a given target

// Date : 03/16/2020

// input: [2, 7, 11, 15]

// output: [0, 1]


#include <iostream>


// vector<int>
void twoSum(int nums[], int target, int size) 
{	
	// Flag to check completion status
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
					std::cout << "[" << i << ", " << j << "]" << std::endl;
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


int main()
{
	int inputArray[] = {2, 7, 11, 15};
	int target = 9;
	int arraySize = sizeof(inputArray)/sizeof(int);

	twoSum(inputArray, target, arraySize);

	return 0;
}