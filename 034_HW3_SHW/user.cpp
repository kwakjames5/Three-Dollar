#include <string>
#include <set>
#include <list>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include "tweet.h"
#include "user.h"

User::User(std::string name)
{
	// sets username

	name_ = name;
}

User::~User()
{
	// deletes any tweets made by this user when user is deleted

    for(std::list<Tweet*>::iterator it = tweets_.begin(); it != tweets_.end(); it++)
    {
    	delete *it;
    }
}

std::string User::name() const
{
	// returns username

	return name_;
}

std::set<User*> User::followers() const
{
	// returns followers

	return followers_;
}

std::set<User*> User::following() const
{
	// returns following

	return following_;
}

std::list<Tweet*> User::tweets() const
{
	// returns tweets

	return tweets_;
}

void User::addFollower(User* u)
{
	// addes the User* u into the followers set of users
	followers_.insert(u);
}

void User::addFollowing(User* u)
{
	// addes the User* u into the following set of users
	following_.insert(u);
}

void User::addTweet(Tweet* t)
{
	// pushes back whatever tweet we want into the user's tweet set
	tweets_.push_back(t);
}

std::vector<Tweet*> User::getFeed()
{
	// supposed to get any given user's feed given their own tweets (?) and their following's tweets

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

	// basically, this iterates through the user's following list
	// for each following user, the second forloop iterates through this user's tweets and pushes them into the feed that will be returned
	for(it1 = following_.begin(); it1 != following_.end(); it1++)
	{
		for(it2 = (*it1)->tweets_.begin(); it2 != (*it1)->tweets_.end(); it2++)
		{
			feed.push_back(*it2);
		}
	}

	// the feed is then sorted based on the TweetComp() comparator, which rearranges the tweets in chronological order
	sort(feed.begin(), feed.end(), TweetComp());

	return feed;
}