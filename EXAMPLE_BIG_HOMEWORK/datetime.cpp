#include <iostream>
#include <cctype>
#include <sstream>
#include <string>
#include "datetime.h"

/**
 * Models a timestamp in format YYYY-MM-DD HH:MM:SS 
 */
DateTime::DateTime()
{
  time_t time0 = time(nullptr);
  tm* time = localtime(&time0);

  this->year = time->tm_year + 1900;
  this->month = time->tm_mon + 1;
  this->day = time->tm_mday;
  this->hour = time->tm_hour;
  this->min = time->tm_min;
  this->sec = time->tm_sec;
}

DateTime::DateTime(int hh, int mm, int ss, int year, int month, int day)
{
	hour = hh;
	min = mm;
	sec = ss;
	this->year = year;
	this->month = month;
	this->day = day;
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
}

/**
   * Outputs the timestamp to the given ostream in format:
   *   YYYY-MM-DD HH::MM::SS
   *
   * @return the ostream passed in as an argument
   */
std::ostream& operator<<(std::ostream& os, const DateTime& other)
{
	os << other.year << "-";
    
    if(other.month == 0 || other.month < 10)
    {
      os << 0 << other.month << "-";
    }
    else
    {
      os << other.month << "-";
    }

    if(other.day == 0 || other.day < 10)
    {
      os << 0 << other.day << " ";
    }
    else
    {
      os << other.day << " ";
    }

    if(other.hour == 0 || other.hour < 10)
    {
  		os << 0 << other.hour << ":";
  	}
    else
    {
      os << other.hour << ":";
    }

    if(other.min == 0 || other.min < 10)
    {
      os << 0 << other.min << ":";
    }
    else
    {
      os << other.min << ":";
    }

    if(other.sec == 0 || other.sec < 10)
    {
      os << 0 << other.sec;
    }
    else
    {
  	 os << other.sec;
    }
    
  	return os;
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
std::istream& operator>>(std::istream& is, DateTime& dt)
{
	char space;

	std::string date_;
	is >> date_;
	std::stringstream ss(date_);

	std::string time_;
	is >> time_;
	std::stringstream ss1(time_);

    
    if(ss.fail())
    {
    	return is;
    }
    
    if(ss1.fail())
    {
    	return is;
    }
    
    if(date_[4] != '-' || date_[7] != '-')
    {
    	return is;
    }

    if(time_[2]!=':' || time_[5]!=':')
    {
    	return is;
    }

    if(date_.length()!=10)
    {
    	return is;
    }

    if(time_.length()!=8)
    {
    	return is;
    }

  	ss >> dt.year >> space >> dt.month >> space >> dt.day;
  	ss1 >> dt.hour >> space >> dt.min >> space >> dt.sec;
    
  	return is;
}
