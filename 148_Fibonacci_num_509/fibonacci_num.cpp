#include "fibonacci_num.h"
#include <iostream>

// link: https://leetcode.com/problems/fibonacci-number/

// date: 7/28/2020

// description: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), for N > 1.
// Given N, calculate F(N).

int Solution::fib(int N) {
    if(N == 0 || N == 1)
    {
        return N;
    }
        
    int a = 0;
    int b = 1;
    int fib = 0;
        
    for(int i = 2; i <= N; i++)
    {
        fib = a + b;
        a = b;
        b = fib;
    }
        
    return fib;
}

int main()
{
    std::cout << "Calculate fibonacci up to which number?" << std::endl;
    int N;
    std::cin >> N;

    Solution solution;
    int fib = solution.fib(N);

    std::cout << "Fibonacci up to " << N << ": " << fib << std::endl;

    return 0;
}