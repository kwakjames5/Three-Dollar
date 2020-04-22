#include <map>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "user.h"
#include "tweet.h"
#include "twiteng.h"
#include "datetime.h"

TwitEng::TwitEng()
{
}

TwitEng::~TwitEng()
{
	// iterates through the map of users and deletes every user
	
    for(std::map<std::string, User*>::iterator it = masterUsers_.begin();
     it != masterUsers_.end(); it++)
    {
    	delete it->second;
    }
}

bool TwitEng::parse(char* filename)
{
	std::ifstream ifile(filename);
	if(ifile.fail())
	{
		std::cout << "Could not read file." << std::endl;
		return 0;
	}

	// initial userCount
	int userCount = 0;

	// check for garbage; when the userCount is correct in ifile, let the parse run
	std::string garbage;
	getline(ifile, garbage);
  	std::stringstream temp(garbage);
  	temp >> userCount;
  	if(temp.fail())
  	{
    	return true;
  	}

  	for(int i = 0; i < userCount; i++)
  	{
    	std::string temp;
    	getline(ifile, temp);
    	std::stringstream ss(temp);

    	std::string mainUser;
    	std::string password;
    	ss >> mainUser;
    	ss >> password;

    	if(ss.fail())
    	{
      		return true;
    	}

    	User* curr;
    	std::map<std::string, std::string>::iterator it;
    	it = logins_.find(mainUser);
    	if(it != logins_.end())
    	{
      		password = it->second;
    	}
    	else
    	{
      		logins_.insert(std::pair<std::string, std::string>(mainUser, password));
    	}

    	std::map<std::string,User*>::iterator it1;
    	it1 = masterUsers_.find(mainUser);

    	if(it1 != masterUsers_.end()){
      		curr = it1->second;
    	}
    	else
    	{
      		curr = new User(mainUser);
      		masterUsers_.insert(std::pair<std::string, User*>(mainUser, curr));
    	}

    	while(!ss.eof())
    	{
      		std::string nextuser;
      		ss >> nextuser;
      		if(nextuser.find_first_not_of(' ') != std::string::npos)
      		{
        		std::map<std::string, User*>::iterator it1;
        		it1 = masterUsers_.find(nextuser);
        		if(it1!=masterUsers_.end())
        		{
          			curr->addFollowing(masterUsers_.find(nextuser)->second);
          			masterUsers_.find(nextuser)->second->addFollower(curr);
        		}
        		else
        		{
          			User *next = new User(nextuser);
          			masterUsers_.insert(std::pair<std::string, User*>(nextuser, next));
          			curr->addFollowing(next);
          			next->addFollower(curr);  
        		}
      		} 
    	}
	}

    while(!ifile.eof())
    {
    	std::string line;
      	getline(ifile, line);
      	if(line.empty())
      	{
        
      	}
      	else
      	{
        	std::stringstream ss1(line);
        
       		DateTime dt;
        	std::string text;
        	std::string user;

        	ss1 >> dt;
        	if(ss1.fail()){
          		return true;
        	}

        	ss1 >> user;
        	if(ss1.fail()){
          		return true;
        	}
        	getline(ss1, text);
        	addTweet(user, dt, text);
    	}
  	}   
  	return false;
}

void TwitEng::addTweet(const std::string& username, const DateTime& time, const std::string& text)
{
	// username + tweet
	std::map<std::string, User*>::iterator it;
  	it = masterUsers_.find(username);
  	if(it==masterUsers_.end())
  	{
    	throw std::out_of_range("Username not found");
  	}
  	
  	User *newUser = masterUsers_.find(username)->second;
  	Tweet *newTweet = new Tweet(newUser, time, text);

  	std::set<std::string> temp = newTweet->hashTags();
  	for(std::set<std::string>::iterator it = temp.begin();
  		it != temp.end();
  		it++)
  	{
  		std::map<std::string, std::set<Tweet*>>::iterator it1;
  		it1 = masterHashtags_.find(*it);
  		if(it1 != masterHashtags_.end())
  		{
  			it1->second.insert(newTweet);
  		}
  		else
  		{
  			std::set<Tweet*> temp1;
  			temp1.insert(newTweet);
  			masterHashtags_.insert(std::pair<std::string, std::set<Tweet*>>(*it, temp1));
  		}
  	}

  	newUser->addTweet(newTweet);
	
	// hashtags
	for(int i = 0; (unsigned) i < masterUsers_.size(); i++)
	{
		for(std::map<std::string, User*>::iterator it = masterUsers_.begin();
		it != masterUsers_.end(); it++)
		{
			if(username == it->first)
			{
				Tweet* ntweet = new Tweet(it->second, time, text);
				it->second->addTweet(ntweet);
				std::set<std::string> tweetHashes = ntweet->hashTags();

				for(std::set<std::string>::iterator it1 = tweetHashes.begin(); 
				it1 != tweetHashes.end(); it1++)
				{
					if(!(masterHashtags_.find(*it1) == masterHashtags_.end()))
					{
						masterHashtags_.find(*it1)->second.insert(ntweet);
					} 
					else
					{
						std::set<Tweet*> nset;
						nset.insert(ntweet);
						masterHashtags_[*it1] = nset;
					}
				}
			}
		}
	}


}

std::vector<Tweet*> TwitEng::search(std::vector<std::string>& terms, int strategy)
{
	std::vector<Tweet*> trueVector;
	std::set<Tweet*> temp;


	if(strategy == 0) // AND // NOT WORKING
	{
		temp = masterHashtags_[terms[0]];
		std::set<Tweet*> store;

		for(int i = 1; (unsigned) i < terms.size(); i++)
		{
			for(std::set<Tweet*>::iterator it = temp.begin(); 
			it != temp.end(); it++)
			{
    			if(!(masterHashtags_[terms[i]].find(*it) == masterHashtags_[terms[i]].end()))
    			{
      				store.insert(*it);
    			}
  			}
		}

		for(std::set<Tweet*>::iterator it2 = store.begin(); it2 != store.end(); it2++)
		{
			trueVector.push_back(*it2);
		}
	}
	else if(strategy == 1) // OR
	{
		for(std::vector<std::string>::iterator it = terms.begin(); 
		it != terms.end(); it++)
		{
			if(!(masterHashtags_.find(*it) == masterHashtags_.end()))
			{
				for(std::set<Tweet*>::iterator it1 = masterHashtags_.find(*it)->second.begin();
				it1 != masterHashtags_.find(*it)->second.end(); it1++)
				{
					trueVector.push_back(*it1);
				}
			}
		}
	}

	return trueVector;
}

void TwitEng::dumpFeeds()
{
	for(std::map<std::string, User*>::iterator it = masterUsers_.begin(); 
	it != masterUsers_.end(); it++)
	{
		std::ofstream ofile;
		std::string name = it->first;
		name += ".feed";
		
		ofile.open(name.c_str());
		
		std::vector<Tweet*> feed(it->second->getFeed());
		for(unsigned int i = 0; i < feed.size();
			i++)
		{
			ofile << *(feed.at(i)) << std::endl;
		}
	}
}

void TwitEng::addFollowing(std::string name_of_follower, std::string name_to_follow)
{
	// iterator for follower
	std::map<std::string, User*>::iterator followerit;
	followerit = masterUsers_.find(name_of_follower);

	// iterator for name to follow
	std::map<std::string, User*>::iterator followingit;
	followingit = masterUsers_.find(name_to_follow);

	// when both names exist, update follower and following for both
	if(followerit != masterUsers_.end() && followingit != masterUsers_.end())
	{
		followerit->second->addFollowing(followingit->second);
		followingit->second->addFollower(followerit->second);
	}

	// error messages for when either (or both) of the names
	// do not exist in master user map
	if(masterUsers_.find(name_of_follower) == masterUsers_.end())
	{
    	std::cout << name_of_follower << " is not a current user" << std::endl;
    	return;
    }
    else if(masterUsers_.find(name_to_follow) == masterUsers_.end())
	{
		std::cout << name_to_follow << " is not a current user" << std::endl;
    	return;
    }
    else if(masterUsers_.find(name_to_follow) == masterUsers_.end() 
    	&& masterUsers_.find(name_of_follower) == masterUsers_.end())
    {
    	std::cout << name_to_follow << " and " << name_of_follower << " are not current users" << std::endl;
    	return;
    }
}

void TwitEng::create_save_db(std::string filename)
{
	std::ofstream ofile(filename.c_str());

	// prints users and their following
	for(std::map<std::string, User*>::iterator it = masterUsers_.begin();
		it != masterUsers_.end();
		it++)
	{
		// prints name of a main user
		ofile << it->first << " ";

		// access main user's list of following
		std::set<User*> following = it->second->following();

		// runs through the list of followings
		// and prints them out next to main user
		for(std::set<User*>::iterator it1 = following.begin();
			it1 != following.end();
			it1++)
		{
			ofile << (*it1)->name() << " ";
		}

		// new line
		ofile << std::endl;
	}

	for(std::map<std::string, User*>::iterator it2 = masterUsers_.begin();
		it2 != masterUsers_.end();
		it2++)
	{
		// access each user's tweet(s)
		std::list<Tweet*> tweets = it2->second->tweets();

		for(std::list<Tweet*>::iterator it3 = tweets.begin();
			it3 != tweets.end();
			it3++)
		{
			// dereferenced twice to get back to
			// tweets, then the actual tweet itself
			// and outputs this tweet in ofile
			ofile << **it3 << std::endl;
		}
	}
}

void TwitEng::make_scc(std::string filename)
{
	std::cout << "Did not have time to complete" << std::endl;
}