#include "unique_email.h"
#include <iostream>
#include <vector>
#include <algorithm>

// link: https://leetcode.com/problems/unique-email-addresses/

// date: 6/2/2020

// description: given a vector of emails in form of "LOCALNAME@EMAIL.COM", return the total number of unique emails
// If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.
// If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.

// input: "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"
// output: 2

int Solution::numUniqueEmails(std::vector<std::string>& emails) 
{
    int possible_emails = 0;
    std::vector<std::string> unique_emails;
    
    for(std::vector<std::string>::iterator it = emails.begin(); it != emails.end(); it++)
    {
        std::string temp;
        std::string current = *it;
        for(int i = 0; i < current.length(); i++)
        {
            if(current[i] == '+' || current[i] == '@')
            {
                break;
            }
            else if(current[i] == '.')
            {
                continue;
            }
            else
            {
                temp += current[i];
            }
        }
        temp += current.substr(current.find('@'), current.size());
        if(std::find(unique_emails.begin(), unique_emails.end(), temp) == unique_emails.end())
        {
            unique_emails.push_back(temp);
        }
    }
        
    possible_emails = unique_emails.size();
    return possible_emails;
}

int main()
{
	std::vector<std::string> emails;
	std::cout << "Enter emails: (Enter 0 to finish)" << std::endl;
	std::string temp;
	while(std::cin >> temp)
	{
		if(temp != "0")
		{
			emails.push_back(temp);
		}
		else
		{
			break;
		}
	}

	Solution solution;
	int output = solution.numUniqueEmails(emails);

	std::cout << "Output: " << output << std::endl;

	return 0;
}