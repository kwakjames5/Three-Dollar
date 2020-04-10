#include <set>
#include <map>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "setops.h"

int main(int argc, char* argv[])
{
	std::ifstream infile(argv[1]);
	std::ifstream cmdfile(argv[2]);
	std::ofstream ofile(argv[3]);

	// terminate messages for when infile or cmdfile are not valid
	if(infile.fail())
	{
		std::cout << "Cannot open: " << argv[1] << std::endl;
		return 0; 
	}

	if(cmdfile.fail())
	{
		std::cout << "Cannot open: " << argv[2] << std::endl;
		return 0;
	}

	// tempString is the general string that will be used for most string manipulations
	std::string tempString;

	// a map with student names (strings) as the key and a set of major names (strings) 
	std::map<std::string, std::set<std::string>> student_major_map;

	// while getline is able to be performed means that this while loop will go to the end of the infile (aka names + majors)
	// every new line is a name and a major

	while(getline(infile, tempString))
	{
		// check and make sure that there is a string in the line
		// skip over any empty lines by using this conditional

		if(tempString.length() != 0)
		{
			// set a string stream onto the line that has the name and major
			std::stringstream ss(tempString);

			// initialize a name string by getting line from ss up to the comma
			std::string name;
			std::string line_of_name;
			getline(ss, line_of_name, ',');

			// some of the names in the infile have whitespaes after the last name
			// this causes a standard read in to not work. these white spaces after the last name must be removed
			// put a stringstream on the name line since stringstreams automatically ignore white spaes
			std::stringstream name_ss(line_of_name);
			std::string part_of_name;

			// a flag to check for first name
			int first_name_flag = 0;

			// each name_ss iteration is an individual part of the person's name (first name, middle name, last name)
			while(name_ss >> part_of_name)
			{
				if(first_name_flag == 0)
				{
					// no spaces needed at the front of first names
					name += part_of_name;
					first_name_flag++;
				}
				else
				{
					// any middle names or last names need spaces between
					name += " " + part_of_name;
				}	
			}

			// initialize a major line string by getting the rest of the line from ss after the comma from the first getline right above
			//  this getline will store every major that this name has (could be more than one)
			std::string line_of_major;
			getline(ss, line_of_major);

			// set a stringstream onto the line of majors so we can check for each major
			std::stringstream major_ss(line_of_major);
			std::string individual_major;

			// empty set of strings to contain all majors for this specific name
			std::set<std::string> all_majors;

			// each major_ss iteration will essentially take every major and go to the next one by skipping the white space
			while(major_ss >> individual_major)
			{
				// since the infile's majors are randomly capitalized or lowercase, standardize it and make them all lowercase so it is easier to compare later
				for(unsigned int i = 0; i < individual_major.length(); i++)
				{
					individual_major[i] = tolower(individual_major[i]);
				}

				// use an iterator to check if the individual major has already been accounted for
				std::set<std::string>::iterator it = all_majors.find(individual_major);

				if(it == all_majors.end())
				{
					// if the iterator is at the end of the set of majors, that means it needs to be added as a major
					all_majors.insert(individual_major);
				}
			}
			
			// check if the student_major_map has the current name already included
			std::map<std::string, std::set<std::string>>::iterator student_major_map_it = student_major_map.find(name);

			// if the name is not in the map yet, create a new pair and initialize the name with all of his/her majors
			if(student_major_map_it == student_major_map.end())
			{
				student_major_map.insert(make_pair(name, all_majors));
			}
			else
			{
				// initialize a new tempSet that will be used to add majors to existing names
				std::set<std::string> temp_set;

				// use the set operator | to create a union of set<string> all_majors from the line and any majors that the name already had in its set<string>
				temp_set = all_majors | student_major_map_it->second;
				student_major_map_it->second = temp_set;
			}
		}
	}

	// TEST FOR PRINTING ALL NAMES AND MAJORS AFTER INFILE IS ORGANIZED
	/*
	std::map<std::string, std::set<std::string>>::iterator student_major_map_it;

	for(student_major_map_it = student_major_map.begin(); student_major_map_it != student_major_map.end(); student_major_map_it++)
	{
		std::cout << student_major_map_it->first << std::endl;

		std::set<std::string>::iterator it3;
		for(it3 = student_major_map_it->second.begin(); it3 != student_major_map_it->second.end(); it3++)
		{
			std::cout << *it3 << std::endl;
		}
	}
	*/

	// every new line that is stored into tempString is a line containing major(s) that we are interested in
	while(getline(cmdfile, tempString))
	{
		// check if the line is empty
		if(tempString.length() != 0)
		{
			// Print to outfile the target major
			ofile << tempString << std::endl;

			// put a stringstream on the line of major(s)
			std::stringstream major_ss(tempString);

			// initialize an empty string to pass each individual major to
			// target_majors is to push in the target majors into a set<string> to compare later
			std::string major_temp;
			std::set<std::string> target_majors;

			// each iteration of major_ss is each individual major being processed
			while(major_ss >> major_temp)
			{
				// change the target major we want into all lower case
				// as noted before when we made everything lowercase, this will ensure that comparing target majors and majors that are in the student_major_map is easy and not case sensitive
				for(unsigned int i = 0; i < major_temp.length(); i++)
				{
					major_temp[i] = tolower(major_temp[i]);
				}

				// find iterator
				std::set<std::string>::iterator major_find_it = target_majors.find(major_temp);

				// if the iterator is at the end of target_majors, insert it into target_majors
				if(major_find_it == target_majors.end())
				{
					target_majors.insert(major_temp);
				}
			}

			// iterate through each name of student_major_map to check their majors
			std::map<std::string, std::set<std::string>>::iterator student_major_map_it;
			for(student_major_map_it = student_major_map.begin(); student_major_map_it != student_major_map.end(); student_major_map_it++)
			{
				// initialize a temporary set that has any shared (&) majors between the interested student and the target majors
				std::set<std::string> temp_set;
				temp_set = target_majors & student_major_map_it->second;

				// initialize a check_set
				// by using the - set operator and finding the difference between target_majors and the temp_set, we are able to check by the difference whether or not the target majors are satisfied by the name
				// if this name has every major that we want from this line, push the name into the ofile
				std::set<std::string> check_set;
				check_set = target_majors - temp_set;
				if(check_set.empty())
				{
					ofile << student_major_map_it->first << std::endl;
				}
			}

			ofile << std::endl;
		}
	}

	infile.close();
	cmdfile.close();
	ofile.close();

	return 0;
}


/*
	std::map<std::string, std::set<std::string> > smap;
	std::map<std::string, std::set<std::string> > mmap;

	std::map<std::string, std::set<std::string> >::iterator a;
	std::map<std::string, std::set<std::string> >::iterator b;

	std::set<std::string>::iterator set;

	if (MyFile1.is_open())
	{
		std::string names, m;

		while (getline(MyFile1, names, ',') && getline(MyFile1, m))
		{
			std::stringstream ss1(names);
			std::stringstream ss2(m);
			std::string name;
			std::string storage;

			while (ss1 >> storage)
			{
				name += storage + ' ';
			}

			a = smap.find(name);

			if(a != smap.end())
			{
				std::string temp;
				while(ss2 >> temp)
				{
					a->second.insert(temp);
				}
			}
			else
			{
				std::string temp;
				std::set<std::string> m;
				while(ss2 >> temp)
				{
					m.insert(temp);
				}
				smap[names] = m;
			}
		}

	}
	else
		{
			return -1;
		}

	MyFile1.close();
	MyFile1.clear();

	if (MyFile2.is_open())
	{
		std::set<std::string> majors;
		std::set<std::string>::iterator it_majors = majors.begin();
		std::string temp;

		while (getline(MyFile2,temp))
		{
			majors.insert(temp);
		}

		std::set<std::string> i;

		for (a = smap.begin(); a != smap.end(); a++)
		{
			i = a->second & majors;
			if (i.size() == 1)
			{
				b = mmap.find(*i.begin());
				if(b != mmap.end())
				{
					b->second.insert(a->first);
				}
				else
				{
					std::set<std::string> s;
					s.insert(a->first);
					mmap[*i.begin()] = s;
				}
			}
			else if(i.size() > 0)
			{
				for (set = i.begin(); set != i.end(); set++)
				{
					b = mmap.find(*set);
					if(b != mmap.end())
					{
						b->second.insert(a->first);
					}
					else
					{
						std::set<std::string> s;
						s.insert(a->first);
						mmap[*set] = s;
					}
				}
			}
		}
	}
	else
		{
			return -1;
		}

	for (a = mmap.begin(); a != mmap.end(); a++)
	{
		MyFile3 << a->first << "\n";
		for (set = a->second.begin(); set != a->second.end(); set++)
		{
			MyFile3 << *set << "\n";
		}
		MyFile3 << "\n";
	}
	
	return 0;	
}
*/