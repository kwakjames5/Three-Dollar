#include <iostream>
#include <fstream>


/*
int main(int argc, char** argv)
{
	char* filename = argv[1]; 
	char* outFile = argv[2];

	// initialize infile 
	std::ifstream myfile (filename); 

	// only run if infile exists
	if(myfile.is_open()) 
	{
		// initialize outfile
		std::ofstream out (outFile); 
		int size;
		myfile >> size;

		// fail case
		if(myfile.fail() || size == 0) 
		{
			out << 0 << std::endl;
			return 0;
		}

		// dynamically allocate new array
		int* array = new int[size];

		// set the array
		for(int i = 0; i < size; i++) 
		{
			int temp;
			myfile >> temp;
			array[i] = temp;
		}

		// use the array and put into outfile
		for(int i = 0; i < ((size + 1)/2); i++) 
		{
			out << (array[i] + array[size - 1 - i]) << std::endl;
		}

		myfile.close();
		delete [] array;
	}

	return 0;
}

*/

int main(int argc, char* argv[])
{
	// initialize input and output file based on terminal parameters
	std::ifstream ifile(argv[1]);
	std::ofstream ofile(argv[2]);

	// check that the in file opens
	if(ifile.is_open())
	{
		int size;

		// the first line in the infile is expected to be the size, or number of integers that will be operated on in this program
		ifile >> size;

		if(size == 0)
		{
			std::cout << "No integers provided." << std::endl;
			return 0;
		}

		// dynamically allocate a new array of integers
		int* integerArray = new int[size];

		// initialize the array
		for(int i = 0; i < size; i++)
		{
			// initialize a temp integer and store the next number that needs to be stored
			int temp;
			ifile >> temp;
			integerArray[i] = temp;
		}

		// MAIN PART OF THE PROGRAM
		// this is a fairly simple program that does as the name implies: it adds up pairs of numbers
		// the program will add the first integer in the array with the last one and continue this binary search way of array traversal
		// until every number in this array has been added with its respetive pair
		// each sum is pushed into the ofile

		for(int i = 0; i < size/2; i++)
		{
			ofile << integerArray[i] + integerArray[size - i - 1] << std::endl;
		}

		delete [] integerArray;
	}

	ifile.close();
	ofile.close();

	return 0;
}
