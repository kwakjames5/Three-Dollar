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

  //implements adler 32 checksum hash algorithm
  // pn + (128^1 * pn-1) + (128^2 * pn-2) + ... + (128^n-1 * p1)
  // aka pn + 128 * (pn-1 + 128*(pn-2 + 128*(pn-3 + ...)))
  
  for(unsigned int i = 0; i < mystring.length() - 1; i++)
  {
    unsigned long long constant = 1;

    for(unsigned int j = 1; j < mystring.length() - i; j++)
    {
      constant *= 128;
    }

    pw += (constant * (int)mystring[i]);
  }

  pw += mystring[mystring.length() - 1];

  unsigned int pw_arr[4];
  pw_arr[3] = pw % 65521;
  pw /= 65521;

  pw_arr[2] = pw % 65521;
  pw /= 65521;
  
  pw_arr[1] = pw % 65521;

  if(pw > 1)
  {
    pw /= 65521;
    pw_arr[0] = pw % 65521;
  }
  else
  {
    pw_arr[0] = 0;
  }

  unsigned int encrypted_pw = (45912 * pw_arr[0] + 35511 * pw_arr[1] + 65169 * pw_arr[2] + 4625 * pw_arr[3]) % 65521;

  return encrypted_pw;
}
