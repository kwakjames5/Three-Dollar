#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) 
{
    long long int numArray[100], sum, bitTrack;

    bitTrack = 31;
    sum = 0;
    
    // convert the input number into binary and turn as much of it into binary as possible
    // store each individual bit into the numArray that represents the binary number
    // starts at 31st index since that is the 2^0 spot and move up
    while(n > 0)
    {
        numArray[bitTrack] = n%2;
        bitTrack--;
        n = n/2;
    }

    // when there are still bits left in the 32 bit integer, need to initialize them to zero so we can flip them 
    // when bitTrack = -1, it indicates that all 32 indexes of numArray are already filled, meaning we do not have to initalize anything
    if(bitTrack != -1)
    {
        for(int i = 0; i <= bitTrack; i++)
        {
            numArray[i] = 0;
        }
    }

    // for 32 indexes, go through each and flip them
    // after they are flipped, add the flipped bit's decimal value to the decimal sum we will return
    for(int i = 0; i < 32; i++)
    {
        if(numArray[i] == 0)
        {
            numArray[i] = 1;
        }
        else
        {
            numArray[i] = 0;
        }

        sum += numArray[i] * pow(2, 31 - i);
    }

    return sum;
}

int main()
{
    ofstream fout("output.txt", std::ofstream::out);
    ifstream ifile("input.txt", std::ifstream::in);

    int q;
    ifile >> q;
    
    for (int q_itr = 0; q_itr < q; q_itr++) {
        long n;
        ifile >> n;

        long result = flippingBits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
