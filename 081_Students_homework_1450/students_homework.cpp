#include "students_homework.h"
#include <vector>
#include <iostream>

// link: https://leetcode.com/problems/number-of-students-doing-homework-at-a-given-time/

// date: 6/19/2020

// description: given two vectors with start time and end time of students doing homework, return the number of students doing homework
// at the time of queryTime

// ex) startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
// output = 1; there is 1 student among the three (1-3, 2-2, 3-7) that is doing homework at 4 o clock (the third student)

int Solution::busyStudent(std::vector<int>& startTime, std::vector<int>& endTime, int queryTime) 
{
    int total_students = 0;
    for(int i = 0; i < startTime.size(); i++)
    {
        if(startTime[i] <= queryTime)
        {
            if(endTime[i] >= queryTime)
            {
                total_students++;
            }
        }
    }
        
    return total_students;
}

int main()
{
    std::cout << "How many students?: " << std::endl;
    int student_count = 0;
    std::cin >> student_count;

    std::vector<int> startTime, endTime;
    int time = 0;

    for(int i = 0; i < student_count; i++)
    {
        std::cout << "Enter start time for student " << i + 1 << ": " << std::endl;
        std::cin >> time;
        startTime.push_back(time);

        std::cout << "Enter end time for student " << i + 1 << ": " << std::endl;
        std::cin >> time;
        endTime.push_back(time);
    }

    std::cout << "Enter time to be checked: " << std::endl;
    int queryTime;
    std::cin >> queryTime;

    Solution solution;
    int busy_students = solution.busyStudent(startTime, endTime, queryTime);

    std::cout << "Total number of students working at " << queryTime << ": " << busy_students << std::endl;

    return 0;
}