///////////////////////////////////////////////////////////////////////////////////

// Function: Common and Different elements of two sorted arrays

// Description : Given two sorted arrays, find common and different elements

// Date : 04/16/2020

/*
there are two sorted integer arrays,

input
a = {1, 3, 4, 6, 8, 12, 86}
b = {1, 5, 8, 10, 12}

output 
# find different elements
{3,4,5,6,10,86}

# find common elements
{1,8,12}
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

int main()
{
	std::ofstream ofile("output.txt");

	int arr1[] = {1, 5, 8, 10, 12};
	int arr2[] = {1, 3, 4, 6, 8, 12, 86};

	int arr1_size = sizeof(arr1)/sizeof(int);
	int arr2_size = sizeof(arr2)/sizeof(int);

	int i = 0, j = 0;

	ofile << "Commmon elements:" << std::endl;

	while(i < arr1_size && j < arr2_size)
	{
		if(arr1[i] == arr2[j])
		{
			ofile << arr1[i] << std::endl;
			i++;
			j++;
		}
		else if(arr1[i] < arr2[j])
		{
			i++;
		}
		else if(arr2[j] < arr1[i])
		{
			j++;
		}
	}

	ofile << std::endl;

	i = 0, j = 0;

	ofile << "Different elements:" << std::endl;

	while(i < arr1_size && j < arr2_size)
	{
		if(arr1[i] < arr2[j])
		{
			ofile << arr1[i] << std::endl;
			i++;
		}
		else if(arr1[i] > arr2[j])
		{
			ofile << arr2[j] << std::endl;
			j++;
		}
		else
		{
			i++;
			j++;
		}
	}

	std::cout << i << " " << j << std::endl;

	while(i < arr1_size && arr1[i] != arr2[j])
	{
		ofile << arr1[i] << std::endl;
		i++;
	}

	while(j < arr2_size && arr2[j] != arr1[i])
	{
		ofile << arr2[j] << std::endl;
		j++;
	}

	ofile.close();

	return 0;
}