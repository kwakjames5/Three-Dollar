#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <cctype>
#include "tweet.h"
#include "datetime.h"
#include "user.h"
#include "util.h"

Tweet::Tweet()
{
}

Tweet::Tweet(User* user, const DateTime& time, const std::string& text)
{
	// creates a tweet object given the user, datetime and also parses through the text's words and checks for hashtags
	// if a hashtag is in the text, it pushes that hashtag withouth the # into hashtags_
	user_ = user;
	time_.year = time.year;
    time_.month = time.month;
    time_.day = time.day;
    time_.hour = time.hour;
    time_.min = time.min;
    time_.sec = time.sec;
	text_ = text;

	std::string temp;
    std::stringstream ss(text);
    while (ss >> temp)
    {
      if (temp.at(0) == '#')
      {
        temp.erase(temp.begin());
        convLower(temp);
        hashtags_.insert(temp);
      }
    }
}

DateTime const & Tweet::time() const
{
	// returns datetime

	return time_;
}

std::string const & Tweet::text() const
{
	// returns the text string

	return text_;
}

std::set<std::string> Tweet::hashTags() const
{
	// returns the set of hashtags

	return hashtags_;
}

bool Tweet::operator<(const Tweet& other) const
{
	// compares the time of the two tweets to see which is newer
	// newer = true
	// older = false

	if(this->time_ < other.time_)
	{
		return true;
	} 
	else if(other.time_ < this->time_)
	{
		return false;
	}

	return true;
}
  
std::ostream& operator<<(std::ostream& os, const Tweet& t)
{
	// pushes into the oufile the date, time, username and text of the tweet
	os << t.time_ << t.user_ << t.text_;
	return os;
}

User* Tweet::user() const
{
	//returns user 

	return user_;
}