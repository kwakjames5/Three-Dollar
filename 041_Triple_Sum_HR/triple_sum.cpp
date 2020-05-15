#include <bits/stdc++.h>

using namespace std;

// link: https://www.hackerrank.com/challenges/triple-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search

// date: 5/15/2020

// description:

// find every unique (p, q ,r) such that p is from a, q is from b and r is from c

// p and r are both less than or equal to q

// return total number of unique (p, q, r) found like this

vector<string> split_string(string);

// Complete the triplets function below.
long triplets(vector<int> a, vector<int> b, vector<int> c) {
    // sort the arrays, the remove any unique numbers in them
    // this makes them easy to handle for this function

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    c.erase(unique(c.begin(), c.end()), c.end());

    // this count will be incremented up per unique (p, q, r) availabe
    long count = 0;
    
    // counters for vector a and c
    // these are defined out here since the arrays are already sorted
    // this makes it so that when the for loop later increments these, the counts can stay raised since the count ultimately just keeps up with the for loop if there are elements in a and c less than the one in b
    int a_count = 0;
    int c_count = 0;

    // iterate for size of vector b since we want to find p's and r's compared to q's
    // for every unique integer in b
    for(int i = 0; i < b.size(); i++)
    {
        // checks from vector a and c if the value at the current counter is less than or equal to the currently checked b
        // if it is, raise the counter up by one since that integer can be used and the next one should be checked
        while(a[a_count] <= b[i] && a_count < a.size())
        {
            a_count++;
        }

        while(c[c_count] <= b[i] && c_count < c.size())
        {
            c_count++;
        }

        // add to the count the total number of unique (p, q, r) available for this current b element
        count += (long)a_count * c_count;
    }

    return count;
}

int main()
{
    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long ans = triplets(arra, arrb, arrc);

    cout << ans << "\n";

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
