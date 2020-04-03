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
	char copiedArray[] = {'a','r','u','p','z','t','e','w'};

	int sourceSize = sizeof(sourceArray)/sizeof(char);
	int copiedSize = sizeof(copiedArray)/sizeof(char);

	int sourceAscii = 0;
	int copiedAscii = 0;

	for(int i = 0; i < sourceSize; i++)
	{
		sourceAscii += sourceArray[i];
	}

	for(int i = 0; i < copiedSize; i++)
	{
		copiedAscii += copiedArray[i];
	}

	int asciiDiff = sourceAscii - copiedAscii;

	if(asciiDiff > 122)
	{
		std::sort(sourceArray, sourceArray + sourceSize);

		int start = 0;
		int end = sourceSize - 1;

		while(start < sourceSize/2 || end > sourceSize/2)
		{
			int startAscii = int(sourceArray[start]);
			int endAscii = int(sourceArray[end]);

			if(startAscii + endAscii < asciiDiff)
			{
				start++;
			}

			if(startAscii + endAscii > asciiDiff)
			{
				end--;
			}


			if(startAscii + endAscii == asciiDiff)
			{
				ofile << "Missing letters: " << char(startAscii) << " " << char(endAscii);

				ofile.close();

				break;
			}
		}
	}
	else
	{
		ofile << (char)(asciiDiff);

		ofile.close();
	}


	return 0;
}

/*for(int j = 0; j < copiedSize; j++)
		{
			if(sourceArray[i] == copiedArray[j])
			{
				break;
			}
			else if(j == copiedSize - 1)
			{
				ofile << sourceArray[i] << std::endl;
			}
		}*/