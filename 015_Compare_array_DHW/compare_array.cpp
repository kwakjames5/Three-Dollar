/*
source array = {'a','p','r','u','o','t','c','e','w','z'};
copied array = {'a','t','c','e','p','u','o','w','z'};
when
find missed character(s).
hint keyword: sum, ascii code
8:04
some characters are missed during copy, find missed characters in copied array by comparing source array.

Runtime: 2(n)

while(){
	while(){
}
}

Look @ two sum
Sort, re arrange, etc
*/

#include <bits/stdc++.h>

int main()
{
	std::ofstream ofile("output.txt", std::ofstream::out);

	char sourceArray[] = {'a','p','r','u','o','t','c','e','w','z'};
	char copiedArray[] = {'p','u','o','w','z'};

	int sourceSize = sizeof(sourceArray)/sizeof(char);
	int copiedSize = sizeof(copiedArray)/sizeof(char);

	for(int i = 0; i < sourceSize; i++)
	{
		for(int j = 0; j < copiedSize; j++)
		{
			if(sourceArray[i] == copiedArray[j])
			{
				break;
			}
			else if(j == copiedSize - 1)
			{
				ofile << sourceArray[i] << std::endl;
			}
		}
	}

	ofile.close();

	return 0;
}