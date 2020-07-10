#include "avg_salary_no_min_max.h"
#include <vector>
#include <iostream>
#include <algorithm>

// link: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

// date: 7/9/2020

// description: Given an array of unique integers salary where salary[i] is the salary of the employee i.
// Return the average salary of employees excluding the minimum and maximum salary.

double Solution::average(std::vector<int>& salary) 
{
    double average = 0;
    std::sort(salary.begin(), salary.end());
    for(int i = 1; i < salary.size() - 1; i++)
    {
        average += (double)(salary[i]);
    }
    return (average / (double)(salary.size() - 2));
}

int main()
{
	std::cout << "How many employees? " << std::endl;
	int employee_count = 0;
	std::cin >> employee_count;
	std::cout << "Enter salaries" << std::endl;
	std::vector<int> employee_salary;
	int salary = 0;
	for(int i = 0; i < employee_count; i++)
	{
		std::cin >> salary;
		employee_salary.push_back(salary);
	}
	Solution solution;
	double average = solution.average(employee_salary);

	std::cout << "Employee salary without min and max: " << average << std::endl;

	return 0;
}
