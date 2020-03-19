#include <iostream>
#include <ostream>
#include "deque.h"
using namespace std;

int main()
{
	Deque<int> test;

	cout << "size:" << test.size() << endl;

	for(int i = 10; i > 5; i--)
	{
		test.push_front(i);
	}

	for(unsigned int i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl;
	}

	cout << "size:" << test.size() << endl;
	
	for(unsigned int i = 5; i > 0; i--)
	{
		test.push_front(i);
	}
	

	for(unsigned int i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl;
	}

	cout << "size:" << test.size() << endl;

	return 0;
}