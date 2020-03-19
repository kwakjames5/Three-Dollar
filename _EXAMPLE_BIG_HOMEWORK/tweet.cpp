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

using namespace std;

Tweet::Tweet()
{
}

Tweet::Tweet(User* user, const DateTime& time, const std::string& text)
{
	user_ = user;
	time_ = time;
	text_ = text;
}

DateTime const & Tweet::time() const
{
	return time_;
}

std::string const & Tweet::text() const
{
	return text_;
}

std::set<std::string> Tweet::hashTags() const
{
	set<string> words;
    string temp;
    stringstream ss;
    ss << text_;

    while(ss >> temp)
    {
        if(temp[0] == '#')
        {
            temp = temp.substr(1, temp.length());
            words.insert(temp);
        }
    }

    return words;
}

bool Tweet::operator<(const Tweet& other) const
{
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
	os << t.time() << " " << t.user_->name() << " " << t.text_;
	return os;
}

User* Tweet::user() const
{
	return user_;
}