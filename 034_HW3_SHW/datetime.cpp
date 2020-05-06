#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include "datetime.h"

/**
 * Models a timestamp in format YYYY-MM-DD HH:MM:SS 
 */
// IMPORTANT FOR TwitEng::addTweet()
DateTime::DateTime()
{
}

// IMPORTANT FOR TwitEng::addTweet()
DateTime::DateTime(int hh, int mm, int ss, int year, int month, int day)
{
	hour = hh;
	min = mm;
	sec = ss;
	this->year = year;
	this->month = month;
	this->day = day;
	
	// initializes datetime with the parameters
}

/**
   * Return true if the timestamp is less-than other's
   *
   * @return result of less-than comparison of timestamp
   */
bool DateTime::operator<(const DateTime& other) const
{
	// "<" means younger
	// aka date1 < date2 means date1 happened more recently

	if(this->year < other.year) 
	{ 
		return true; 
	} 
	else if(other.year > this->year)
	{
		return false;
	}

	if(this->month < other.month)
	{
		return true;
	}
	else if(other.month < this->month)
	{
		return false;
	}

	if(this->day < other.day)
	{
		return true;
	}
	else if(other.day < this->day)
	{
		return false;
	}

	if(this->hour < other.hour)
	{
		return true;
	}
	else if(other.hour < this->hour)
	{
		return false;
	}

	if(this->min < other.min)
	{
		return true;
	}
	else if(other.min < this->min)
	{
		return false;
	}

	if(this->sec < other.sec)
	{
		return true;
	}
	else if(other.sec < this->sec)
	{
		return false;
	}

	return false;

	// compares the time in order of broadest to most exact to compare times of two different tweets
}

/**
   * Outputs the timestamp to the given ostream in format:
   *   YYYY-MM-DD HH::MM::SS
   *
   * @return the ostream passed in as an argument
   */
std::ostream& operator<<(std::ostream& os, const DateTime& other)
{
	os << other.year << "-" << other.month << "-" << other.day << " "
	<< other.hour << ":" << other.min << ":" << other.sec;
	return os;
	

	/*os << other.year << "-" << other.month << "-" << other.day << " " << 
		other.hour << ":" << other.min << ":" << other.sec;
	return os;
	*/
	// this one seems to be proper
}

/**
   * Inputs the timestamp to the given istream expecting the format:
   *   YYYY-MM-DD HH::MM::SS
   *  Returns if an error in the format with the DateTime set to the
   *   current system time/date
   *   
   *
   * @return the istream passed in as an argument
   */

// IMPORTANT FOR TwitEng::addTweet()
std::istream& operator>>(std::istream& is, DateTime& dt)
{
	std::stringstream ssline;
	std::string line; 
	getline(is, line, '-');
	ssline.str(line);
	if(ssline.fail()){

		DateTime temp;
		dt = temp;
		return is;
	}
	getline(is,line, '-');
	ssline.str(line);
	ssline >> dt.month;
	if(ssline.fail()){
		DateTime temp;
		dt = temp;
		return is;
	}
	//getline(is,line, ' ');
	is >> line;
	ssline.str(line);
	ssline >> dt.day;
	if(ssline.fail()){
		DateTime temp;
		dt = temp;
		return is;
	}
	getline(is, line, ':');
	ssline.str(line);
	ssline >> dt.hour;
	if(ssline.fail()){
		DateTime temp;
		dt = temp;
		return is;
	}
	getline(is, line, ':');
	ssline.str(line);
	ssline >> dt.min;
	if(ssline.fail()){
		DateTime temp;
		dt = temp;
		return is;
	}
	getline(is, line, ' ');
	ssline.str(line);
	ssline >> dt.sec;

	return is;
	/*
    std::string year;
	std::string month;
	std::string day;
	std::string hour;
	std::string min;
	std::string sec;

	getline(is, year, '-');
	std::stringstream year_(year);

	getline(is, month, '-');
	std::stringstream month_(month);

	getline(is, day, ' ');
	std::stringstream day_(day);

	getline(is, hour, ':');
	std::stringstream hour_(hour);

	getline(is, min, ':');
	std::stringstream min_(min);

	getline(is, sec, ' ');
	std::stringstream sec_(sec);

	year_ >> dt.year;
	month_ >> dt.month;
	day_ >> dt.day;
	hour_ >> dt.hour;
	min_ >> dt.min;
	sec_ >> dt.sec;

	// would dt.year = year work?? applies for all parts of time

	return is;
	*/
}
