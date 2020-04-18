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

int main()
{
	std::ofstream ofile("output.txt");

	int arr[] = {0, 0, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 5, 7, 9, 11, 11};

	int arr_size = sizeof(arr)/sizeof(int);
	int dup_flag = 0;

	ofile << "Removed Duplicates from Array where duplicates appear at most k = 2 times" << std::endl;

	for(int i = 1; i < arr_size; i++)
	{
		if(arr[i] == arr[i - 1])
		{
			dup_flag++;
		}

		if(arr[i] != arr[i + 1])
		{
			if(dup_flag <= 1)
			{
				ofile << arr[i] << std::endl;
				dup_flag = 0;
			}
			else
			{
				dup_flag = 0;
			}
		}
	}

	ofile << std::endl;
	ofile << "Removed Duplicates from Array" << std::endl;

	for(int i = 1; i <= arr_size; i++)
	{
		if(arr[i] != arr[i - 1])
		{
			ofile << arr[i - 1] << std::endl;
		}
	}

	ofile.close();

	return 0;
}