/*
    n = 9875
    k = 4

    superDigit(p) = superDigit(9875987598759875)
                  5+7+8+9+5+7+8+9+5+7+8+9+5+7+8+9 = 116
    superDigit(p) = superDigit(116)
                  1+1+6 = 8
    superDigit(p) = superDigit(8)
*/

// link: https://www.hackerrank.com/challenges/recursive-digit-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the superDigit function below.
int superDigit(string n, int k) 
{
    // not sure why this is unsigned long long
    // three test cases fail on website if this is int
    // found this hint on discussion section
    unsigned long long sum = 0;

    // this adds up the individual numbers in the string into sum
    // ex)
    // 1234 -> 1 + 2 + 3 + 4 = 10
    for(unsigned int i = 0; i < n.size(); i++)
    {
        sum += n[i] - 48;
    }

    // multiplies the sum by the number of iterations k
    sum *= k;

    // now do recursion to get the super digit
    // base case is for when sum is single digit; simply return the digit
    if(sum < 10)
    {
        return sum;
    }
    else
    {
        // when the sum is more than one digit, we know to add up all the digits
        // until the parameter string n is a single digit number
        // since superDigit already adds up n k times, recursively check superDigit(sum, 1)
        return superDigit(to_string(sum), 1);
    }
}

int main()
{
    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    // string n is just the string representation of the first number
    string n = nk[0];

    // int k is the number of iterations
    int k = stoi(nk[1]);

    int result = superDigit(n, k);

    cout << result << "\n";

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
