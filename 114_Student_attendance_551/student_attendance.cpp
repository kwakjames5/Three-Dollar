#include "student_attendance.h"
#include <string>
#include <iostream>
#include <map>

// link: https://leetcode.com/problems/student-attendance-record-i/

// date: 7/7/2020

// description: You are given a string representing an attendance record for a student. The record only contains the following three characters:
// 'A' : Absent.
// 'L' : Late.
// 'P' : Present.
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

// You need to return whether the student could be rewarded according to his attendance record.


bool Solution::checkRecord(std::string s) {
    std::map<char, int> attendance_check;
    int late_track = 0;
    int max_late = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'L')
        {
            late_track++;
            if(i == s.size() - 1)
            {
                if(late_track > max_late)
                {
                    max_late = late_track;
                }
            }
        }
        else
        {
            if(late_track > max_late)
            {
                max_late = late_track;
            }
            late_track = 0;
        }
        attendance_check[s[i]]++;
    }
        
    if(attendance_check['A'] <= 1 && max_late <= 2)
    {
        return true;
    }
        
    return false;
}

int main()
{
    std::cout << "Enter string for attendance (L = Late, A = Absent, P = Present)" << std::endl;
    std::string input;
    std::cin >> input;
    Solution solution;
    bool check_prize = solution.checkRecord(input);

    if(check_prize)
    {
        std::cout << "Student is eligible for the reward" << std::endl;
    }
    else
    {
        std::cout << "Student's attendance is not eligible for the reward" << std::endl;
    }

    return 0;
}