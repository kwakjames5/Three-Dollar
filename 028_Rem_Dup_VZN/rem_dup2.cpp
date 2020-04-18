///////////////////////////////////////////////////////////////////////////////////

// Function: Remove Duplicates from Array

// Description : Removes Duplicates from Array and Removes Duplicates from Array where duplicates appear at most k = 2 times

// Date : 04/18/2020

// input: int arr[] = {0, 0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 7, 9, 11, 11}

// output: 
// Q) Removed Duplicates from Array
// 0 1 2 3 4 5 7 9 11 
// Q) Removed Duplicates from Array where duplicates appear at most k = 2 times
// 0 2 5 7 9 11


#include <iostream>
#include <fstream>
#include <vector>

void removeDuplicatesK(std::vector<int>& arr, int k)
{
	int dup_flag = 0;

	for(unsigned int i = 1; i < arr.size(); i++)
	{
		if(arr[i] == arr[i - 1])
		{
			dup_flag++;
		}

		if(arr[i] != arr[i + 1])
		{
			if(dup_flag < k)
			{
				std::cout << arr[i] << std::endl;
				dup_flag = 0;
			}
			else
			{
				dup_flag = 0;
			}
		}
	}
}

void removeDuplicates(std::vector<int>& arr)
{
	for(unsigned int i = 1; i <= arr.size(); i++)
	{
		if(arr[i] != arr[i - 1])
		{
			std::cout << arr[i - 1] << std::endl;
		}
	}
}

int main()
{
	std::vector<int> arr = {0, 0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 7, 9, 11, 11};
	int k = 2;

	std::cout << "Removed Duplicates from Array where duplicates appear at most k = 2 times" << std::endl;
	removeDuplicatesK(arr, k);

	std::cout << std::endl;

	std::cout << "Removed Duplicates from Array" << std::endl;
	removeDuplicates(arr);
	
	return 0;
}