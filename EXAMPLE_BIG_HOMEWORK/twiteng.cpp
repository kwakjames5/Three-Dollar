#include <map>
#include <string>
#include <set>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "user.h"
#include "tweet.h"
#include "util.h"
#include "tagdata.h"
#include "heap.h"
#include "hash.h"
#include "twiteng.h"
#include "datetime.h"

TwitEng::TwitEng(): trending_(2)
{
	currStatus_ = false;
}

TwitEng::~TwitEng()
{
    for(std::map<std::string, User*>::iterator it = masterUsers_.begin();
     it != masterUsers_.end(); it++)
    {
    	delete it->second;
    }
}

bool TwitEng::parse(char* filename)
{
  std::ifstream ifile(filename);
  std::ofstream ofile;
  int userCount;

  if(!ifile.fail())
  {
    ifile >> userCount;

    std::string lines, username;
    std::stringstream ss;
    getline(ifile, lines);

    for(int i = 0; i < userCount; i ++)
    {
      if(!(getline(ifile, lines)))
      { 
        return true;
      }

      ss << lines;

      while(ss >> username)
      {
        if(masterUsers_.find(username) == masterUsers_.end())
        {
          User* temp = new User(username);
          masterUsers_[username] = temp;
        }
      }
      ss.clear();
    }
    ss.clear();

  std::string lines2, username2, name;
  int pass;

  std::ifstream ifile2(filename);
  getline(ifile2, lines2);

  for(int i = 0; i < userCount; i++)
  {
    if((!getline(ifile2, lines2)))
    {
      return true;
    }

    ss << lines2;
    ss >> name >> pass;
    
    // set the password
    std::map<std::string, User*>::iterator tempIt = masterUsers_.find(name);
    tempIt->second->setPass(pass);
 
    // update following / followers
    while(ss >> username2)
    {
      std::map<std::string, User*>::iterator it = masterUsers_.find(username2);
      std::map<std::string, User*>::iterator it1 = masterUsers_.find(name);
      (it->second)->addFollower( it1->second);

      it = masterUsers_.find(name);
      it1 = masterUsers_.find(username2);
      (it->second)->addFollowing(it1->second);
    }
    ss.clear();
  }

  std::string lines3, hashtagCheck, noHashTag, username3;
  DateTime time;
  
  while(getline(ifile, lines))
  {
    if(lines == "")
    {
      continue;
    }

    ss << lines; 
    ss >> time >> username3;

    if(!(getline(ss, lines3)))
    {
      return true;
    }

    lines3.erase(0,1);

    std::map<std::string, User*>::iterator userIt = masterUsers_.find(username3);
    Tweet* newTweet = new Tweet(userIt->second, time, lines3);
    userIt->second->addTweet(newTweet);

    ss.clear();
    ss << lines3;

    while(ss >> hashtagCheck)
    {
      std::set<Tweet*> store;

      if(hashtagCheck[0] == '#')
      {   
        noHashTag = hashtagCheck.substr(1, hashtagCheck.length());
        convUpper(noHashTag);

          if(masterHashtags_.find(noHashTag) == masterHashtags_.end())
          { 
            std::map<std::string, User*>:: iterator it3 = masterUsers_.find(username);
            store.insert(newTweet);
            masterHashtags_[noHashTag] = store;
          }
          else
          {
            std::map<std::string, std::set<Tweet*> >::iterator it2 = masterHashtags_.find(noHashTag);
            (it2->second).insert(newTweet);
          }
        }
      }
      ss.clear();
    }

    std::map<std::string, std::set<Tweet*>>::iterator hashtagIt;
    for(hashtagIt = masterHashtags_.begin(); hashtagIt != masterHashtags_.end(); ++hashtagIt)
    {
      TagData temp(hashtagIt->first, (int)hashtagIt->second.size());
      trending_.push(temp);
    }
    return false;
  }
  else
  {
    std::cout << "Could not parse \n";
  }

  return 0;
}

void TwitEng::addTweet(const std::string& username, const DateTime& time, const std::string& text)
{
  std::map<std::string, User*>::iterator it = masterUsers_.find(username);
  if(it == masterUsers_.end())
  {
    throw std::out_of_range("Username not found");
  }

  Tweet* newTweet = new Tweet(it->second, time, text);
  (it->second)->addTweet(newTweet);

  std::stringstream ss(text);
  std::string word, key;

  while(ss >> word)
  {

    if(word[0] == '#')
    {
      key = word.substr(1);
      convUpper(key);

      if(masterHashtags_.find(key) == masterHashtags_.end())
      {
        std::set<Tweet*> tweetStore;
        tweetStore.insert(newTweet);
        masterHashtags_[key] = tweetStore;
        TagData temp(key, 1);
        trending_.push(temp);
      }
      else
      {
        std::map< std::string, std::set<Tweet*> >::iterator mapIt = masterHashtags_.find(key);
        mapIt->second.insert(newTweet);

        std::map<std::string, std::set<Tweet*>>::iterator masterHashtagsIt = masterHashtags_.find(key);

        int size = (int)masterHashtagsIt->second.size();
        TagData temp(key, size - 1);
        TagData val(key, size);

        trending_.decreaseKey(temp, val);
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

void TwitEng::trending(int num)
{
  std::vector<TagData> temp;

  for(int i = 0; i < num; i++)
  {
    if(trending_.empty() != true)
    {
      // get most popular trending word
      TagData trendWords = trending_.top();

      // pop the trending and push into temp
      temp.push_back(trendWords);
      trending_.pop();
      std::string temp = trendWords.tag;

      convLower(temp);
      std::cout << temp << " : " << trendWords.num << std::endl;
    }
    else
    {
      break;
    }
  }

  for(unsigned int i = 0; i < temp.size(); i++)
  {
    trending_.push(temp[i]);
  }
}

bool TwitEng::login(std::string username, std::string pw)
{
  bool loginStatus = true;
  currStatus_ = true;

  unsigned int temp = calculateHash(pw);
  std::map<std::string, User*>::iterator user_it = masterUsers_.find(username);

  if(temp != user_it->second->getPass())
  {
    loginStatus = false;
  }
  else
  {
    currUser_ = user_it->second;
    loginStatus = true;
  }

  return loginStatus;
}

std::string TwitEng::currUser()
{
  std::string name;  
  name = currUser_->name();
  return name;
}

void TwitEng::logout(User* logOut)
{
  currUser_ = logOut;
}

bool TwitEng::currStatus()
{
  return currStatus_;
}

void TwitEng::changeStatus(bool status)
{
  currStatus_ = status;
}