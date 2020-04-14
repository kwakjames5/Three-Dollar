#include <iostream>
#include <ostream>
#include "deque.h"
using namespace std;

int main()
{
	Deque<int> test;

	cout << "size:" << test.size() << endl;

	for(int i = 1; i < 6; i++)
	{
		test.push_back(i);
	}

	for(unsigned int i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl;
	}

	cout << "size:" << test.size() << endl;
	
	for(int i = 5; i > 0; i--)
	{
		test.push_back(i);
	}
	

	for(unsigned int i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl;
	}

	cout << "size:" << test.size() << endl;

	for(int i = 0; i < 4; i++)
	{
		test.pop_front();
	}

	for(unsigned int i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl;
	}

	cout << "size:" << test.size() << endl;

	for(int i = 0; i < 3; i++)
	{
		test.pop_back();
	}

	for(unsigned int i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl;
	}

	cout << "size:" << test.size() << endl;


	return 0;
}