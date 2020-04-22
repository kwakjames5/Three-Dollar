
///////////////////////////////////////////////////////////////////////////////////

// Function: Two sum

// Description : Implement function how many binary ‘1’ in decimal number=156

// Date : 04/21/2020

#include <iostream>

int one_count(int num)
{
	int bit_store[8];
	int i = 0;

	int one_count = 0; 

	while(num > 0)
	{
		bit_store[i] = num%2;
		num = num/2;
		i++;
	}

	for(int i = 0; i < 8; i++)
	{
		if(bit_store[i] == 1)
		{
			one_count++;
		}
	}

	return one_count;
}

int main()
{
	int num = 156;

	int count = one_count(num);

	std::cout << count << std::endl;

	return 0;
}