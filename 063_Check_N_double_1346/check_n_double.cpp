#include "check_n_double.h"
#include <vector>
#include <set>
#include <iostream>

bool Solution::checkIfExist(std::vector<int>& arr) 
{
    std::set<int> check_set;
    for(int i = 0; i < arr.size(); i++)
    {
        if(check_set.find(arr[i] * 2) != check_set.end() || 
           check_set.find(arr[i] / 2) != check_set.end() && arr[i]%2 == 0)
        {
            return true;
        }
        check_set.insert(arr[i]);
    }
        
    return false;
}

int main()
{
    std::vector<int> arr;

    std::cout << "Enter array size: " << std::endl;

    int size;
    std::cin >> size;

    std::cout << "Enter array elements: " << std::endl;

    for(int i = 0; i < size; i++)
    {
        int temp;
        std::cin >> temp;

        arr.push_back(temp);
    }

    Solution solution;
    bool double_check = solution.checkIfExist(arr);

    std::cout << "Does array have N and its double: ";

    if(double_check == 0)
    {
        std::cout << "FALSE" << std::endl;
    }
    else if(double_check == 1)
    {
        std::cout << "TRUE" << std::endl;
    }

    return 0;

}