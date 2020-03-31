#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) 
{
    int size = s.size();
    int count = 0;

    for(int i = 1; i < size; i++)
    {
        if(s[i] == s[i - 1])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    ofstream fout("output.txt", std::ofstream::out);
    ifstream ifile("input.txt", std::ifstream::in);

    int q;
    ifile >> q;

    for (int q_itr = 0; q_itr <= q; q_itr++) 
    {
        string s;
        getline(ifile, s);

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
