///////////////////////////////////////////////////////////////////////////////////

// Function: Row and Col One

// Description : Find ‘1’ first and make ‘1’ for row and column which includes ‘1’

// Date : 04/17/2020

// input
// 2-D array
// int[][] myArray = {  {0, 1, 2, 3},
//						{3, 2, 1, 0},
//						{3, 5, 6, 8},
//						{3, 8, 3, 4}  };

// output 
// int[][] myArray = {  {1, 1, 1, 1},
//						{1, 1, 1, 1},
//						{3, 1, 1, 8},
//                      {3, 1, 1, 4}  };


#include <iostream>

int main()
{
	int myArray[4][4] = {{0, 1, 2, 3}, {3, 2, 1, 0}, {3, 5, 6, 8}, {3, 8, 3, 4}};

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(myArray[i][j] == 1)
			{
				for(int k = 0; k < 4; k++)
				{
					if(myArray[i][k] != 1)
					{
						myArray[i][k] = -1;
					}
				}

				for(int l = 0; l < 4; l++)
				{
					if(myArray[l][j] != 1)
					{
						myArray[l][j] = -1;
					}
				}
			}
		}
	}

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(myArray[i][j] == -1)
			{
				myArray[i][j] = 1;
			}
		}
	}

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			std::cout << myArray[i][j] << " ";
		}

		std::cout << std::endl;
	}



	return 0;
}