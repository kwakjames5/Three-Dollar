#include <bits/stdc++.h>

using namespace std;

// link: https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

// date: 5/16/2020

/*  
    The first line contains two space-separated integers n and d, the size of a and the number of left rotations you must perform.
    The second line contains n space-separated integers a[i].

    5 4
    1 2 3 4 5

    5 1 2 3 4
*/

vector<string> split_string(string);

// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) 
{
    // d number of rotations
    for(int i = 0; i < d; i++)
    {
        // temp is to keep store of the first element of a
        // this first element gets overwritten on the rotation, so keep track of it so it can be used to set the last int
        int temp = a[0];

        // rotate and set each element to its right neighbor until the last element
        // the last element does not have a right neighbor, so do not act on this one within this for loop
        for(int j = 0; j < a.size() - 1; j++)
        {
            a[j] = a[j + 1];
        }

        // once the for loop has been executed, finally change the last element in a @ a.size() - 1 to the temp that was stored earlier
        a[a.size() - 1] = temp;
    }

    // return the fully rotated a
    return a;
}

int main()
{
    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> result = rotLeft(a, d);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";

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
