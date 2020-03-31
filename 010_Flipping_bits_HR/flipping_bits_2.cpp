#include <bits/stdc++.h>

using namespace std;

// Complete the flippingBits function below.
long flippingBits(long n) 
{
    unsigned int store = ~n;
    return store;
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
