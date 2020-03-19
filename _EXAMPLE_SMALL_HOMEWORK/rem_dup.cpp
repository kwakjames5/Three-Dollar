#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "rem_dup_lib.h"

// VALGRIND COMMAND:
// valgrind --tool=memcheck --leak-check=yes 
// --show-reachable=yes --num-callers=20 --track-fds=yes ./rem_dup input.txt

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Please provide the input file" << std::endl;
    	return 1;
	}

	// in file
	std::ifstream ifile(argv[1]);
	
	// take file contents and turn them 
	// into singly linked list using Item* notation
	if(ifile.is_open())
	{
		// two temp strings
		std::string line;
		std::string word;

		// take a line and set a string stream
		getline(ifile, line);
		std::stringstream ss(line); 

		// head and tail for list 1
		Item* head = nullptr;
		Item* tail = nullptr;

		// for linked list 1
		while(ss >> word)
		{
			Item* temp = new Item(stoi(word), nullptr);

			if(head == nullptr)
			{
				head = temp;
				tail = temp;
				temp = nullptr;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
		}

		// for linked list 2
		getline(ifile, line);
		std::stringstream ss1(line);

		// head and tail for list 2
		Item* head1 = nullptr;
		Item* tail1 = nullptr;

		while(ss1 >> word)
		{
			Item* temp1 = new Item(stoi(word), nullptr);

			if(head1 == nullptr)
			{
				head1 = temp1;
				tail1 = temp1;
				temp1 = nullptr;
			}
			else
			{
				tail1->next = temp1;
				tail1 = temp1;
			}
		}
    	// I now have two lists, one 
    	// starting with head and one with head1.

		// an empty linked list into 
		// which I will store my result
		Item* finalList;
		
		// run the functions
		removeConsecutive(head);
		finalList = concatenate(head, head1);


		// out file
		std::ofstream ofile(argv[2]);

		// set up temporary head at final list
		Item* temp;
   	 	temp = finalList;

   	 	// while there are elements 
   	 	// to use from final list,
   	 	// keep going and output 
   	 	// the numbers in order.
   	 	while(temp != nullptr)
    	{
      		ofile << temp->val << " ";
      		temp = temp->next;
    	}

    	// close the in file.
		ifile.close();
	}
	else
	{
		// error message
		std::cout << "Error opening file." << std::endl;
	}

	return 0;
}