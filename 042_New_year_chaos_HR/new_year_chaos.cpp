#include <bits/stdc++.h>

using namespace std;

// link: https://www.hackerrank.com/challenges/new-year-chaos/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

// date: 5/16/2020

/*
The first line contains an integer t, the number of test cases.

Each of the next t pairs of lines are as follows:
- The first line contains an integer n, the number of people in the queue
- The second line has n space-separated integers describing the final state of the queue.
*/

/*
    ex)
    2
    5
    2 1 5 3 4
    5
    2 5 1 3 4

    3 (1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4)
    Too chaotic

    Return too chaotic if more than two bribes need to be made
    otherwise return minimum number of bribes to achieve the inputted queue
*/

/*
    a number in a spot cannot be more than 2 difference
    ex)
    5 1 2 3 4 is clearly too chaotic

    q[0] currently has 5
    5 - (0 + 1) is higher than 2

    on the other hand, 1 2 5 3 4 is possible
    q[2] currently has 5
    5 - (2 + 1) is 2, so this works

    since the numbers start from 1 instead of 0, the index that is being tracked must have a 1 added to match the numbers in the queue
*/

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) 
{
    int total_bribes = 0;

    // check each element in q going backwards
    for(int i = q.size() - 1; i >= 0; i--)
    {   
        // if the element being checked is more than 2 away from their original spots, cout Too chaotic and return
        if(q[i] - (i + 1) > 2)
        {
            cout << "Too chaotic" << endl;
            return;
        }

        // now the function must check how many bribes the element at q[i] made to get to the spot it is at right now
        // run a new for loop from 2 potential bribes/spots away from the current q[i]
        // from there, check every element up to q[i]

        // since q[i] - 2 can also become a negative number (which cannot be used), use max(0, q[i] - 2) so that when q[i] - 2 is negative, 0 is used instead
        for(int j = max(0, q[i] - 2); j < i; j++)
        {
            // if the element that is in a spot lower than q[i] has a element higher in value than q[i], that means a bribe was made
            // increment up total_bribe for each bribe made
            if(q[j] > q[i])
            {
                total_bribes++;
            }
        }
    }

    cout << total_bribes << endl;

    /*
    for(int i = 0; i < q.size() - 1; i++)
    {
        // if the element being checked is more than 2 away from their original spots, cout Too chaotic and return
        if(q[i] - (i + 1) > 2)
        {
            cout << "Too chaotic" << endl;
            return;
        }
    }
    */

}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
