#include "hash.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

unsigned int calculateHash(string mystring)
{
  /* add your code here */
	unsigned long long pw = 0;

  	for(int i = 0; i < mystring.size(); i++)
  	{
  		unsigned long long constant = 1;

    	for(int j = 1; j < i + 1; j++)
    	{
      		constant *= 128;
    	}

    	pw += (constant * mystring[mystring.size() - 1 - i]);

    	constant = 1;
  	}
  
  	unsigned int arr[4];

  	for(int i = 0; i < 4; i++)
  	{
    	arr[i] = 0;
  	}

  	for(int i = 3; i >= 0; i--)
  	{
    	if(pw == 0)
    	{
      		break;
    	}

    	arr[i] = static_cast<unsigned int>(pw % 65521);
    
    	pw = pw/65521;
  	}

  	unsigned long long npw;
  	npw = ((45912 * arr[0]) + (35511 * arr[1]) + (65169 * arr[2]) + (4625 * arr[3])) % 65521;
  	
  	return npw;
}
