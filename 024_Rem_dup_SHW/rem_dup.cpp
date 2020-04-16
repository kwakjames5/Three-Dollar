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
		// line is used for getline
		// word is used for storing stringstream iterations
		std::string line;
		std::string word;

		// take a line and set a string stream on the line
		getline(ifile, line);
		std::stringstream ss(line); 

		// head and tail for list 1
		// list 1 will be made from the first line in the input.txt
		Item* head = nullptr;
		Item* tail = nullptr;

		// for linked list 1
		// act for each integer on the line
		while(ss >> word)
		{
			// each integer is stored as a temporary Item*
			Item* temp = new Item(stoi(word), nullptr);

			// when head is nullptr, it means that the linked list is currently empty
			if(head == nullptr)
			{	
				// initialize the first head and tail of the linked list by setting both to the current integer
				head = temp;
				tail = temp;
			}
			else
			{
				// when a list already exists, set the next node as temp
				// this next node gets overwritten every iteration until the end
				// tail is set as temp to continue making the list
				tail->next = temp;
				tail = temp;
			}
		}

		// for linked list 2
		getline(ifile, line);
		std::stringstream ss1(line);

		// head and tail for list 2
		// list 2 will be made from the second line in the input.txt
		Item* head1 = nullptr;
		Item* tail1 = nullptr;

		// act for each integer on the line
		while(ss1 >> word)
		{
			// each integer is stored as a temporary Item*
			Item* temp1 = new Item(stoi(word), nullptr);

			// when head is nullptr, it means that the linked list is currently empty
			if(head1 == nullptr)
			{
				// initialize the first head and tail of the linked list by setting both to the current integer
				head1 = temp1;
				tail1 = temp1;
				temp1 = nullptr;
			}
			else
			{
				// when a list already exists, set the next node as temp
				// this next node gets overwritten every iteration until the end
				// tail is set as temp to continue making the list
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
		// these two will remove the consecutive nodes in the first linked list, then concatenate the entirety of the second linked list onto the new first linked list
		// finalList contains this concatenated list
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