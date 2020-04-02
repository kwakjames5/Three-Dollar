#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException
{
public:
	// constructor sets the num
	BadLengthException(int errorNum)
	{
		num = errorNum;
	};

	// this is the function that was called when BadLengthException object needs to return the length of the error
	int what()
	{
		return num;
	};

	// stores the number that was thrown
	int num;
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		// try-exception block
		// does what's inside of the bracket, but if a function within throws an error that the catch recognizes, it will move down to display an error message
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		// lines 37 and 38 imply that 'BadLengthException' is a class. 
		//'what()' is a function within the class BadLengthException as can be seen by this function being called through a dot operator with the object 'e'
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}