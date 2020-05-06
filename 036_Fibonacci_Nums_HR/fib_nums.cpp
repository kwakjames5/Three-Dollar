#include <iostream>

using namespace std;

// find the nth number in the fibonacci sequence using recursion
// f(n) = f(n - 1) + f(n - 2)
//
// ex)
// f(2) = f(1) + f(0) = 1
// f(1) = 1
// f(0) = 0

// link: https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking

int fibonacci(int n) 
{
	// Base case is when n is at 1 and 0, the cases we know
	// return the corresponding results
	if(n <= 1)
	{
		return n;
	} 
	else
	{
		// when n is bigger than 1, run fibonacci recursively to get the fibonacci number
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
}

int main() 
{
    int n;
    cout << "Enter the fibonacci index:" << endl;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}