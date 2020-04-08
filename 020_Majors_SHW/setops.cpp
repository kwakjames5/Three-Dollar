#include <iostream>
#include <set>
#include <string>
#include "setops.h"

// Computes the intersection of s1 and s2
// aka the string that is returned should be whichever chars are shared
// ex) s1 = "ABCD" s2 = "ABCF"; s1 & s2 = "ABC"
std::set<std::string> operator&(const std::set<std::string>& s1, 
                                const std::set<std::string>& s2)
{
	// empty temp set of strings that will be modified and returned
	std::set<std::string> temp;
	// an iterator for s1
	std::set<std::string>::iterator it1;
	
	// use the s1 iterator to iterate through s1
	for(it1 = s1.begin(); it1 != s1.end(); ++it1)
	{
		// set a new iterator using the algorithm library's find() function
		// find() can take in a value that needs to be found and will return a iterator to the location if it exists
		// if it does not exist, it returns end
		// for every iteration of the s1 loop, set a new itFind iterator to check if the string in set s1 exists in set s2
		std::set<std::string>::iterator itFind = s2.find(*it1);

		// if itFind returns an iterator, it implies that the string that ifFind was on exists in both set s1 and set s2
		//  since this is a intersection operator, insert any strings/elements that are similar
		if(itFind != s2.end())
		{
			temp.insert(*itFind);
		}
		
	}

	// return the set that has now been fully set
	return temp;
}

// Computes the union of s1 and s2
// | is for or, so you just take s1 and put it onto s2
// ex) s1 = "ABCD" s2 = "ABCF"; s1 | s2 = "ABCDABCF"
std::set<std::string> operator|(const std::set<std::string>& s1, 
                                const std::set<std::string>& s2)
{
	// empty temp set of strings that will be modified and returned
	std::set<std::string> temp;

	// two iterators for two sets of strings
	std::set<std::string>::iterator it1;
	std::set<std::string>::iterator it2;
	
	// iterate through set 1 and just insert every string in the set
	// since this is union, we just want a temp set that has everything between the two sets
	for(it1 = s1.begin(); it1 != s1.end(); ++it1)
	{
		temp.insert(*it1);
	}

	// repeat for set 2
	for(it2 = s2.begin(); it2 != s2.end(); ++it2)
	{
		temp.insert(*it2);
	}

	return temp;
}

// Computes the difference of s1 and s2
// - is for subtraction
// essentially, will return the letters that are different between s1 and s2
// ex) s1 = "ABCD" s2 = "ABCF"; s1 - s2 = "D"
std::set<std::string> operator-(const std::set<std::string>& s1,
                                const std::set<std::string>& s2)
{
	// empty temp set of strings that will be modified and returned
	std::set<std::string> temp;

	// iterator for set 1
	std::set<std::string>::iterator it1;

	// run through set 1
	for(it1 = s1.begin(); it1 != s1.end(); ++it1)
	{	
		// do the same as the & operator, but reversed
		std::set<std::string>::iterator itFind = s2.find(*it1);
		// when itFind 
		if(itFind == s2.end())
		{
			temp.insert(*itFind);
		}
	}
	

	return temp;
}