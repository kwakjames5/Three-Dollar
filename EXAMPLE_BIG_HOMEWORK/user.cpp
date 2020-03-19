#include <string>
#include <set>
#include <list>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "tweet.h"
#include "user.h"

using namespace std;

User::User(std::string name)
{
	name_ = name;
}

User::~User()
{
    for(std::list<Tweet*>::iterator it = tweets_.begin(); it != tweets_.end(); it++)
    {
    	delete *it;
    }
}

std::string User::name() const
{
	return name_;
}

std::set<User*> User::followers() const
{
	return followers_;
}

std::set<User*> User::following() const
{
	return following_;
}

std::list<Tweet*> User::tweets() const
{
	return tweets_;
}

void User::addFollower(User* u)
{
	followers_.insert(u);
}

void User::addFollowing(User* u)
{
	following_.insert(u);
}

void User::addTweet(Tweet* t)
{
	tweets_.push_back(t);
}

std::vector<Tweet*> User::getFeed()
{	
	std::vector<Tweet*> feed;
	std::list<Tweet*>::iterator it;
	std::set<User*>::iterator it1;
	std::list<Tweet*>::iterator it2;

	// pushes my tweets into feed first
	for(it = tweets_.begin(); it != tweets_.end(); it++)
	{
		feed.push_back(*it);
	}

	// two iterators; it1 for followers, it2 for tweets
	// loop1: goes through set of user* following
	// loop2: dereferences it1 (changes from set to user*) and goes through 
	// each following user's tweets and pushes them.
	for(it1 = following_.begin(); it1 != following_.end(); it1++)
	{
		for(it2 = (*it1)->tweets_.begin(); it2 != (*it1)->tweets_.end(); it2++)
		{
			feed.push_back(*it2);
		}
	}

	sort(feed.begin(), feed.end(), TweetComp());

	return feed;
}

unsigned long long User::getPass()
{
    return pass_;
}

void User::setPass(int pass)
{
    pass_ = pass;
    return;
}