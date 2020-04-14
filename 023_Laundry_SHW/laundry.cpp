#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "stack.h"

// input values:
// 0  0  0  -1  2  -1  2

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Please provide the input file" << std::endl;
    	return 1;
	}

	// in file
	std::ifstream ifile(argv[1]);

	if(ifile.is_open())
	{
		// outfile
		std::ofstream ofile(argv[2]);

		// two temp strings
		std::string line;
		std::string word;

		// gets the entire line given by laundry.in and sets a stringstream onto it
		getline(ifile, line);
		std::stringstream ss(line);

		// set a new store to track the kinds of towels
		Stack<std::string> store;

		// keep track of how many towels are available to grab
		int count = 0;

		// while there are towels from laundry.in
		while(ss >> word)
		{
			// pushes black or white accordingly from laundry.in, updates count
			if(stoi(word) == 0)
			{
				store.push("black");
				count++;
			}
			else if(stoi(word) == -1)
			{
				store.push("white");
				count++;
			}
			else if (stoi(word) > 0)
			{
				// for when the number of towels the employee
				// wants to grab is higher than towels available
				if(stoi(word) > count)
				{
					int permCount = count;
					for(int i = 0; i < permCount; i++)
					{
						if(store.top() == "black")
						{
							ofile << "black ";
							store.pop();
							count--;
						}
						else
						{
							ofile << "white ";
							store.pop();
							count--;
						}
					}
					ofile << std::endl;
				}
				else
				{
					// for when the employee grabs less than
					// all of the towels
					for(int i = 0; i < stoi(word); i++)
					{
						if(store.top() == "black")
						{
							ofile << "black ";
							store.pop();
							count--;
						}
						else
						{
							ofile << "white ";
							store.pop();
							count--;
						}
					}
					ofile << std::endl;
				}
			}
		}
	}
}