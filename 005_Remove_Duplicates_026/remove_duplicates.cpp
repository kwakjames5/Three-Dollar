///////////////////////////////////////////////////////////////////////////////////

// Function: Remove Duplicates from Sorted Array

// Description : Given a sorted array nums, remove the duplicates such that each element appear only once and return the new length.

// Date : 03/17/2020

// input: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

// output: 0 1 2 3 4
//         Length = 5

#include <iostream>
#include <vector>

int removeDuplicates(int nums[], int size, std::vector<int>& updatedNums)
{
	// Also keeps track of position
	int length = 0;

	for(int i = 0; i < size; i++)
	{	
		// The first element and any number which is different from the previous element in the array
		if(i == 0 || nums[i] != nums[i - 1])
		{
			updatedNums.push_back(nums[i]);
			length++;
		}
	}

	return length;
}

int main()
{
	int inputArray[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	int arraySize = sizeof(inputArray)/sizeof(int);
	std::vector<int> outputArray;
	int length = removeDuplicates(inputArray, arraySize, outputArray);

	for(int i = 0; i < outputArray.size(); i++)
	{
		std::cout << outputArray[i] << " ";
	}

	std::cout << std::endl << "Length: " << length << std::endl;

	return 0;
}