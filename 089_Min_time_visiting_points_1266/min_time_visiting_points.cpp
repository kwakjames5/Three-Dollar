#include "min_time_visiting_points.h"
#include <string>
#include <iostream>
#include <algorithm>

// link: https://leetcode.com/problems/minimum-time-visiting-all-points/

// date: 6/24/2020

// description: given a vector of points (which are represented by two ints in a vector), return the minimum amount of time
// it takes to travel each point given that you travel in order of the points and a horizontal, vertical or diagonal shift
// (aka x+1, y+1, or x+1 and y+1) each take 1 second each

int Solution::minTimeToVisitAllPoints(std::vector<std::vector<int> >& points) {
    int total_time = 0;
        
    for(int i = 0; i < points.size() - 1; i++)
    {
        int x_time = abs(points[i][0] - points[i + 1][0]);
        int y_time = abs(points[i][1] - points[i + 1][1]);
        if(x_time >= y_time)
        {
            total_time += x_time;
        }
        else
        {
            total_time += y_time;
        }
            
    }
        
    return total_time;
        
}

int main()
{
    std::vector<std::vector<int> > points;

    std::cout << "Enter how many points: " << std::endl;
    int point_count = 0;
    std::cin >> point_count;
    

    for(int i = 0; i < point_count; i++)
    {
        std::vector<int> temp;
        int point;
        std::cout << "Enter x and y for point " << i + 1 << std::endl;
        std::cin >> point;
        temp.push_back(point);
        std::cin >> point;
        temp.push_back(point);

        points.push_back(temp);
    }

    Solution solution;

    int min_time = solution.minTimeToVisitAllPoints(points);
    std::cout << "Min time to travel to all points: " << min_time << " seconds" << std::endl;

    return 0;
}