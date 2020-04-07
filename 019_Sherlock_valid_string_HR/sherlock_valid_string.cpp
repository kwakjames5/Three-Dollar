#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
	// empty vector with size 26 for each alphabet
	vector<int> abcTrack(26);
	int len = s.size();

	// cycle through string s and update each alphabet count in the vector
	// increment the alphabet's index by 1 everytime that char is found in the string
	for(int i = 0; i < len; i++)
	{
		abcTrack[s[i] - 'a']++;
	}

	// abcTrack will have a bunch of 0s since a lot of the alphabet will not be used in the string
	// since we do not want our min to be 0 ever, get rid of them

	// getting rid of the 0s from a vector was a little more complicated than thought
	// I found what's called a erase-remove idiom
	// this idiom is a commonly used combination of functions to get rid of specific elements from a collection (in this case a vector) 

	// SYNTAX: arrayname.erase(remove(arrayname.begin(), arrayname.end(), val), arrayname.end())
	abcTrack.erase(remove(abcTrack.begin(), abcTrack.end(), 0), abcTrack.end());

	// After, set the min and max values accordingly
	int min = *min_element(abcTrack.begin(), abcTrack.end());
	int max = *max_element(abcTrack.begin(), abcTrack.end());

	// If min and max are the same, it means that every alphabet that was used was used the same number of times
	// immediately pass a "YES" for this case
	if(min == max)
	{
		return "YES";
	}

	// min and max count are initialized at 0
	int minCount = 0;
	int maxCount = 0;

	// cycle through abcTrack and update min and max count by incrementing them whenever a min or max is found
	// if an index contains any 'tweeners', that automatically introduces a third number into the problem
	// this automatically implies that more than 1 character must be removed from the string to make it valid
	// this fails the test case, so return "NO" for tweeners
	for(int i = 0; i < abcTrack.size(); i++)
	{
		if(abcTrack[i] == min)
		{
			minCount++;
		} 
		else if(abcTrack[i] == max)
		{
			maxCount++;
		}
		else
		{
			return "NO";
		}
	}

	// the minimum number of alphabets was a 1 and there is only 1 of them (minCount), there is just a single stray char that can be removed
	// VALID STRING
	if(minCount == 1 && min == 1)
	{
		return "YES";
	}

	// if the max number minus the min number return anything bigger than 1, that means that more than 1 char must be deleted to make the string valid
	// example: max = 4, min = 2; does not work because if you delete a max alphabet, you are still left with 3 of these alphabets. 3 is still not the same as 2
	// INVALID STRING
	if(max - min >= 2)
	{
		return "NO";
	}

	// if max is exactly 1 above min and there is only 1 max, that max can simply be deducted by one, or removed a char, and the maxCount will go away
	// VALID STRING
	if(maxCount == 1 && max == min + 1)
	{
		return "YES";
	}

	// for any other or default cases, return "NO" as a default answer
	return "NO";
}

int main()
{
    ofstream fout("output.txt", std::ofstream::out);

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
 