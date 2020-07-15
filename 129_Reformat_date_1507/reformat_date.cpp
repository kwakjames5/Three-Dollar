#include "reformat_date.h"
#include <iostream>
#include <string>
#include <sstream>

// link: https://leetcode.com/problems/reformat-date/

// date: 7/14/2020

// description: Convert the date string to the format YYYY-MM-DD, where:
// YYYY denotes the 4 digit year.
// MM denotes the 2 digit month.
// DD denotes the 2 digit day.

std::string Solution::reformatDate(std::string date) {
    std::string year, month, day;
    std::stringstream ss(date);
    std::string temp;
    int track = 0;
    while(ss >> temp)
    {
        if(track == 0)
        {
            for(int i = 0; i < temp.size(); i++)
            {
                if(temp[i] >= 48 && temp[i] <= 57)
                {
                    day += temp[i];
                }
            }
            track++;
        }
        else if(track == 1)
        {
            for(int i = 0; i < temp.size(); i++)
            {
                month += temp[i];
            }
            
            track++;
        }
        else if(track == 2)
        {
            for(int i = 0; i < temp.size(); i++)
            {
                year += temp[i];
            }
            
            track++;
        }
    }
        
    std::string reformatted_date;
    reformatted_date = year + "-";
        
    if(month == "Jan")
    {
        reformatted_date += "01-";
    }
    if(month == "Feb")
    {
        reformatted_date += "02-";
    }
    if(month == "Mar")
    {
        reformatted_date += "03-";
    }
    if(month == "Apr")
    {
        reformatted_date += "04-";
    }
    if(month == "May")
    {
        reformatted_date += "05-";
    }
    if(month == "Jun")
    {
        reformatted_date += "06-";
    }
    if(month == "Jul")
    {
        reformatted_date += "07-";
    }
    if(month == "Aug")
    {
        reformatted_date += "08-";
    }
    if(month == "Sep")
    {
        reformatted_date += "09-";
    }
    if(month == "Oct")
    {
        reformatted_date += "10-";
    }
    if(month == "Nov")
    {
        reformatted_date += "11-";
    }
    if(month == "Dec")
    {
        reformatted_date += "12-";
    }
        
    if(day.size() == 1)
    {
        std::string temp1 = "0" + day;
        reformatted_date += temp1;
    }
    else
    {
        reformatted_date += day;
    }
        
    return reformatted_date;
}

int main()
{
    std::cout << "Enter date in this format CASE SENSITIVE: ex) 20th Oct 1984 AKA ##th Mon YEAR" << std::endl;
    std::string date;
    getline(std::cin, date);
    Solution solution;
    std::string new_date = solution.reformatDate(date);
    std::cout << "Formatted date: " << new_date << std::endl;

    return 0;

}