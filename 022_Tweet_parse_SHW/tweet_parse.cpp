#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main(int argc, char* argv[])
{
	//initialize infile
	std::ifstream myfile ("tweets.txt");

	// only run if infile exists
	if(myfile.is_open())
	{
		// each vector here contains strings, as can be told by the syntax
		// each vector's strings correspond to their names (tweets, users, hashtags)
		// since this program wants to keep track of unique users, hashtags and number of tweets
		// we track all of these things separately using these three vectors
		std::vector<std::string> tweets;
		std::vector<std::string> users;
		std::vector<std::string> hashtags;

		// a temp string to store stuff into
		std::string temp;

		//pushes tweets into tweets vector when a tweet exists on a line in the infile
		while(getline(myfile, temp))
		{
			// if the line in the infile is empty, skip it
			// if it has something in it, there is a tweet on that line
			// push it into the vector
			if(!temp.empty())
			{
				tweets.push_back(temp);
			}
		}

		// iterate through the vector of tweets since we want to now get the unique users and hashtags in all the tweets from the infile
		for(unsigned int i = 0; i < tweets.size(); i++)
		{
			// initialize stringstream onto the tweet line that we are on right now
			std::stringstream ss(tweets[i]);

			// here is a empty string to store each word of the tweet
			std::string storage;

			// each iteration of ss is a word from the tweet we are on going into storage
			while(ss >> storage)
			{
				// checks for unique users
				// does this by first checking for the first index of the storage string
				// if it is a '@', that means this current word is a user
				if(storage.at(0) == '@')
				{
					// set a new bool for found and set it to false
					bool found = false;

					// iterate through the users vector
					for(unsigned int j = 0; j < users.size(); j++)
					{
						// check if the user we are iterating on in the vector is the same as the stored user
						// if this is the case, then this user is not a unique one and does not have to be accounted for
						if(users[j].compare(storage) == 0)
						{
							found = true;
							break;
						}
					}

					// in the case that the flag was untouched, that means the user we are on is unique in the user vector
					if(!found)
					{
						// push the stored user into the users vector
						users.push_back(storage);
					}
				}
				// checks for unique hashtags
				// does this by first checking for the first index of the storage string
				// if it is a '#', that means this current word is a hashtag
				else if(storage.at(0) == '#')
				{
					// set a new bool for found and set it to false
					bool found = false;

					// iterate through the hashtags vector
					for(unsigned int k = 0; k < hashtags.size(); k++)
					{
						// check if the hashtag we are iterating on in the vector is the same as the stored hashtag
						// if this is the case, then this hashtag is not a unique one and does not have to be accounted for
						if(hashtags[k].compare(storage) == 0)
						{
							found = true;
							break;
						}
					}

					// in the case that the flag was untouched, that means the hashtag we are on is unique in the hashtag vector
					if(!found)
					{
						// push the stored hashtag into the hashtags vector
						hashtags.push_back(storage);
					}
				}
			}
		}

		// output message
		std::cout << "1. Number of tweets=" << tweets.size() << std::endl;
		std::cout << "2. Unique users" << std::endl;

		for(unsigned int i = 0; i < users.size(); i++)
		{
			std::cout << users[i].substr(1) << std::endl;
		}

		std::cout << "3. Unique hashtags" << std::endl;

		for(unsigned int i = 0; i < hashtags.size(); i++)
		{
			std::cout << hashtags[i].substr(1) << std::endl;
		}
	}
	else
	{
		// fail case
		std::cout << "File does not open." << std::endl;
		return 0;
	}

	return 0;
}