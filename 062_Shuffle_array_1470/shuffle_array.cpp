#include "shuffle_array.h"

std::vector<int> Solution::shuffle(std::vector<int>& nums, int n) 
{
    std::vector<int> output;
    for(int i = 0; i < n; i++)
    {
        output.push_back(nums[i]);
        output.push_back(nums[i + n]);
    }
       
    return output;
}

int main()
{
	std::vector<int> nums;
	int n;
	int size;

	std::cout << "Enter vector size:" << std::endl;
	std::cin >> size;

	std::cout << "Enter vector elements:" << std::endl;
	for(int i = 0; i < size; i++)
	{
		int temp;
		std::cin >> temp;

		nums.push_back(temp);
	}

	std::cout << "Enter length of half of the array: " << std::endl;
	std::cin >> n;

	Solution solution;
	std::vector<int> output = solution.shuffle(nums, n);

	std::cout << "Shuffled array: [";
	std::vector<int>::iterator it;
	for(it = output.begin(); it != output.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl;

	return 0;
}