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

// IMPORTANT FOR TwitEng::addTweet()
TwitEng::~TwitEng()
{
	// iterates through the map of users and deletes every user
	
    for(std::map<std::string, User*>::iterator it = master_users.begin();
     it != master_users.end(); it++)
    {
    	delete it->second;
    }
}

/*
	INFILE FORMAT:
	Number of users
	Followed by names (Same number as number of users from first line)
		First name is unique user
		Following names are following users
		this means the first named user is following the users named afterwards
		ex) James Joe Bob
		James is the first user
		Joe and Bob are the users that James follows
		Joe and Bob are followed by James
	Actual Tweets (YYYY-MM-DD HH:MM:SS Username Tweet) (Tweets may contain @ and #)
*/

// IMPORTANT FOR TwitEng::addTweet()
bool TwitEng::parse(char* filename)
{
	std::ifstream ifile(filename);
	if(ifile.fail())
	{
		std::cout << "Could not read file." << std::endl;
		return 0;
	}

	// first thing in the in file is the user count
	// store it
	int user_count;
	ifile >> user_count;

	// line is for each individual line of names
	std::string line;

	// iterate for number of users
	for(int i = 0; i <= user_count; i++)
	{
		// get the line of names and put string stream to go through it
		getline(ifile, line);
		std::stringstream ss(line);

		// string for first user name
		std::string new_user;
		ss >> new_user;

		// if the user is not yet registered
		if(master_users.find(new_user) == master_users.end())
		{
			// create a new user with username as the name
			User* user = new User(new_user);

			// insert a pair of username and the newly created user into the master_users map
			master_users.insert(std::pair<std::string, User*>(new_user, user));
		}

		// string for following names after the first user name
		std::string following;

		// run string stream to the end, meaning cover every following name after the first name
		while(ss >> following)
		{
			// we must check if any of the following names are unique
			// if the following name has already been registered, no need to register a new user
			if(master_users.find(following) != master_users.end())
			{
				// add a following to new_user in map master_users
				// this following must be another user in the map
				// find the following user in the master_users map
				// ->second is to make sure to add the actual User* in the map
				// and not the username string from the map, which would be ->first
				master_users[new_user]->addFollowing(master_users.find(following)->second);
			}
			else
			{
				// for when the following names have not been registered yet
				// create a new user and insert it into the master_users map
				// then, add a follow from first user to this newest user
				User* new_following = new User(following);
				master_users.insert(std::pair<std::string, User*>(following, new_following));
				master_users[new_user]->addFollowing(new_following);
			}
		}

	}

	// user and tweet strings that will be used to store user and tweet strings in the tweet lines
	std::string user;
	std::string tweet;

	// run until the end of the infile now that all of the users have been registered and followed
	// only the tweet lines remain
	// Actual Tweets (YYYY-MM-DD HH:MM:SS Username Tweet) (Tweets may contain @ and #)
	while(!ifile.eof())
	{
		// temporary storage string
		std::string temp;

		int yr, mon, day, hr, min, sec;

		// read up to the YYYY
		getline(ifile, temp, '-');
		std::stringstream ss(temp);
		ss >> yr;

		std::cout << yr << std::endl;

		// read up to the MM
		getline(ifile, temp, '-');
		std::stringstream st(temp);
		st >> mon;

		std::cout << mon << std::endl;

		// read up to the DD
		getline(ifile, temp, ' ');
		std::stringstream su(temp);
		su >> day;

		std::cout << day << std::endl;

		// read up to the HH
		getline(ifile, temp, ':');
		std::stringstream sv(temp);
		sv >> hr;

		std::cout << hr << std::endl;

		// read up to the MM
		getline(ifile, temp, ':');
		std::stringstream sw(temp);
		sw >> min;

		std::cout << min << std::endl;

		// read up to the SS
		getline(ifile, temp, ' ');
		std::stringstream sx(temp);
		sx >> sec;

		std::cout << sec << std::endl;

		DateTime dt(hr, min, sec, yr, mon, day);

		//original:
		//ifile >> user;
		
		getline(ifile, user, ' ');
		
		getline(ifile, tweet);

		// TEST LINE TO CHECK TWEETS WHEN THEY ARE BEING PARSED
		//std::cout << tweet << std::endl;

		// TEST LINE TO CHECK real_tweet
		//std::string real_tweet = tweet.substr(1);
		//std::cout << real_tweet << std::endl;

		addTweet(user, dt, tweet);

		// addTweet has a segmentation fault
		// that needs to be fixed for this parse function to be complete
		// once all of the users have been registered and followed accordingly
		// the function parses through the tweet lines individually
		// stores the datetime, username and tweet
		// and uses these stores to addTweet, which is supposed to be the function
		// which literally adds the tweet to tweets_
		
	}
	

	

	return false;
	/*
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
  	*/
}

// IMPORTANT FOR TwitEng::addTweet()
void TwitEng::addTweet(const std::string& username, const DateTime& time, const std::string& text)
{
	// tweet_user is the user object of the username that is passed in
	// tweet is a new Tweet object made using the parameters
	User* tweet_user = master_users.find(username)->second;
	Tweet* tweet =  new Tweet(tweet_user, time, text);
	tweet_user->addTweet(tweet);

	std::stringstream ss(text);
	std::string temp;

	/*while(ss >> temp)
	{
		
	}*/

	tweets_.push_back(tweet);
	std::set<std::string> hashtags = tweet->hashTags();
	for(std::set<std::string>::iterator it = hashtags.begin(); it != hashtags.end(); it++)
	{
		master_hashtags[*it].insert(tweet);
	}
	



	/*
	// username + tweet
	std::map<std::string, User*>::iterator it;
  	it = master_users.find(username);
  	if(it==master_users.end())
  	{
    	throw std::out_of_range("Username not found");
  	}
  	
  	User *newUser = master_users.find(username)->second;
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
	for(int i = 0; (unsigned) i < master_users.size(); i++)
	{
		for(std::map<std::string, User*>::iterator it = master_users.begin();
		it != master_users.end(); it++)
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
	*/

}

std::vector<Tweet*> TwitEng::search(std::vector<std::string>& terms, int strategy)
{
	std::vector<Tweet*> trueVector;
	std::set<Tweet*> temp;


	if(strategy == 0) // AND // NOT WORKING
	{
		temp = master_hashtags[terms[0]];
		std::set<Tweet*> store;

		for(int i = 1; (unsigned) i < terms.size(); i++)
		{
			for(std::set<Tweet*>::iterator it = temp.begin(); 
			it != temp.end(); it++)
			{
    			if(!(master_hashtags[terms[i]].find(*it) == master_hashtags[terms[i]].end()))
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
			if(!(master_hashtags.find(*it) == master_hashtags.end()))
			{
				for(std::set<Tweet*>::iterator it1 = master_hashtags.find(*it)->second.begin();
				it1 != master_hashtags.find(*it)->second.end(); it1++)
				{
					trueVector.push_back(*it1);
				}
			}
		}
	}

	return trueVector;
}

// this is what is called when user uses QUIT
// this function should create the outfiles for each individual users feeds
// IMPORTANT FOR TwitEng::addTweet()
void TwitEng::dumpFeeds()
{
	// iterate through the master_users map
	for(std::map<std::string, User*>::iterator it = master_users.begin(); it != master_users.end(); it++)
	{
		// feed is the current user's feed
		// get feed is all of the user tweets along with following's tweets
		std::vector<Tweet*> feed = (it->second->getFeed());

		// create the ofile for this user's feed
		std::string name = it->first + ".feed";
		std::ofstream ofile(name);

		// pushes the name of the user at the top of the feed
		ofile << it->first << "'s feed" << std::endl;

		for(unsigned int i= 0; i < feed.size(); i++)
		{
			ofile << feed[i]->time() << " " << feed[i]->user()->name() << " " << feed[i]->text() << std::endl;

			// TEST LINE TO CHECK WHAT IS IN feed[i]
			//std::cout << feed[i]->text() << "slingo" <<  std::endl; 
		}

		/*for(std::vector<Tweet*>::iterator feed_it = feed.begin(); feed_it != feed.end(); feed_it++)
		{
			ofile << (*feed_it)->time() << " " << (*feed_it)->user()->name() << " " << (*feed_it)->text() << std::endl;	
		}
		*/
	}
	/*
	for(std::map<std::string, User*>::iterator it = master_users.begin(); 
	it != master_users.end(); it++)
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
	*/
}

/*
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
*/