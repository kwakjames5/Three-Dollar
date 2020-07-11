#include "defang_ip.h"
#include <string>
#include <iostream>

// link: https://leetcode.com/problems/defanging-an-ip-address/

// date: 7/10/2020

// description: Given a valid (IPv4) IP address, return a defanged version of that IP address.
// A defanged IP address replaces every period "." with "[.]".

std::string Solution::defangIPaddr(std::string address) 
{
    std::string return_string;
    for(int i = 0; i < address.size(); i++)
    {
        if(address[i] == '.')
        {
            return_string += "[.]";
        }
        else
        {
            return_string += address[i];
        }
    }
        
    return return_string;
}

int main()
{
    std::cout << "Enter IP address to be defanged (Integers and periods [.]): " << std::endl;
    std::string address;
    std::cin >> address;
    Solution solution;
    std::string defanged_ip = solution.defangIPaddr(address);

    std::cout << "Defanged IP Address: " << defanged_ip << std::endl;

    return 0;
}