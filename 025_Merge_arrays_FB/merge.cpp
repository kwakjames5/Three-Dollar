///////////////////////////////////////////////////////////////////////////////////

// Function: Merge

// Description : Merges two sorted arrays

// Date : 04/16/2020

// output: 
// 1
// 3
// 4
// 5
// 6
// 8
// 10
// 12
// 86

//PROBLEM:
/*
There are two sorted integer arrays, merge two array
input
a = {1, 3, 4, 6, 8, 12, 86}
b = {5, 10}
output 
{1, 3, 4, 5, 6, 8, 10, 12, 86}
*/

#include <iostream>

int main()
{
	int arr1[] = {1, 3, 4, 6, 8, 12, 86};
	int arr2[] = {5, 10};

	int arr1size = sizeof(arr1)/sizeof(int);
	int arr2size = sizeof(arr2)/sizeof(int);

	int arr3[arr1size + arr2size];

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	while(count1 < arr1size && count2 < arr2size)
	{
		if(arr1[count1] < arr2[count2])
		{
			arr3[count3] = arr1[count1];
			count3++;
			count1++;
		}
		else
		{
			arr3[count3] = arr2[count2];
			count3++;
			count2++;
		}
	}

	while(count1 < arr1size)
	{
		arr3[count3] = arr1[count1];
		count3++;
		count1++;
	}

	while(count2 < arr2size)
	{
		arr3[count3] = arr2[count2];
		count3++;
		count2++;
	}

	int arr3size = sizeof(arr3)/sizeof(int);

	for(int i = 0; i < arr3size; i++)
	{
		std::cout << arr3[i] << std::endl;
	}

	return 0;
}