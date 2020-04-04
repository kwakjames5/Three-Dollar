//g++ -g -Wall -std=c++11 str.cpp str_test.cpp -o str_test
//g++ -g -Wall -std=c++11 str.cpp

#include <iostream>
#include <stdexcept>
#include <cstring>
#include "str.h"

using namespace std;

// Add your implementations here.

Str::Str()
{
	// Default constructor
	// Initializes the size of the "" aka 0
	size_ = 0;

	// sets char* data_ as a new char array with minimum size of 1
	data_ = new char[1];

	// sets the only index in the new data_ char array to a 'end character' (\0)
	data_[size_] = '\0';
}

Str::~Str()
{
	// Descontructor needs to delete any dynamically allocated memory
	// in this string class, char* data_ is a dynamically allocated array
	// must delete the data_ information to deconstruct the string
	delete[] data_;
}

Str::Str(const char* s)
{
	// Overloaded constructor
	// This one creates a new string that has size_ and data_ of 's'

	// initialize the string's size_ to s's length
	size_ = strlen(s);

	// initialize the data_ as a char* with size of length + 1
	// this 1 is so a '\0' (end character) can be added to the end of the string
	data_ = new char[strlen(s)];

	//run a for loop for the duration of the newly initialized this's size_
	strcpy(this->data_, s);

	// set the last index in this's data_ as the end character
	//this->data_[this->size_ + 1] = '\0';
}


// NEW FUNCTION
Str::Str(const Str& s)
{
	size_ = s.size();
	data_ = new char[s.size()];
	strcpy(data_, s.data_);
}

Str& Str::operator=(const char* s)
{
	// Assignment operator
	// assigns all of this's information to be the same as char* s
	// FORMAT: this = s;

	// delete any data_ that is in this at the moment so we can reinitialize it to s's data_
	if(this->size_ > 0)
	{	
		delete [] data_;
	}

	// change the size_ of this to equal the size of 's'
	this->size_ = strlen(s);

	// newly initialize the data_ of this as a dynamically allocated char* array with size of s, which has already been stored into this->size
	this->data_ = new char[this->size_ + 1];

	// copies the string from s to char* data_ of this
	strcpy(this->data_, s);

	// CHECK THIS ONE
	// Since this operator needs to return a Str& (string address), return *this

	// My question: why is a dereferenced this string being returned?
	// is that the address of this?
	return *this;
}

// NEW FUNCTION
Str& Str::operator=(const Str& s)
{
	char* temp = new char(this->size_ + s.size());

	if(this->size_ > 0)
	{	
		delete [] data_;
	}

	this->size_ = s.size();
	strcpy(temp, s.data_);
	this->data_ = temp;

	return *this;
}


Str& Str::operator+=(const Str& s)
{
	// FORMAT: this += Str s;
	// RESULT: this = this + s

	// initialize a temporary char* array with the size of this, s and 1 for the end character
    char* temp = new char[this->size_ + s.size() + 1];

    // this is copied into the temp
    for (int i = 0; i < this->size_; i++){
    	temp[i] = this->data_[i];
    }

    // s is copied into temp starting at the size_ of this to add s to the end of this
    for (unsigned int i = 0; i < s.size(); i++){
    	temp[this->size_ + i] = s.data_[i];
    }

    // set the end character
    temp[this->size_ + s.size()] = '\0';

    // delete whatever data_ was initially in this now that we do not need it anymore
    delete [] this->data_;

    // set the now empty data_ to the char* temp that contains both this and s
    this->data_ = temp;

    // CHECK THIS ONE
    // Since this operator needs to return a Str& (string address), return *this
    return *this;   
}

Str& Str::operator+=(const char* s)
{
	// this += is for when the input is a char* array, not a Str address
	// this is handled differently

	// set a temp char* array as the data_ of this
	char* temp = this->data_;

	// change the data_ of this to be a new char* with size of the temp (holds the original data) + the size of s and 1 for the end character
	this->data_ = new char[strlen(temp) + strlen(s) + 1];

	// update the size_ accordingly
	this->size_ += strlen(s);

	// temp (original data_) and s are concatenated into this's data_
	strcat(this->data_, temp);
	strcat(this->data_, s);

	// set the end character
	this->data_[strlen(data_) + strlen(s)] = '\0';

	// delete the temp char* that was allocated to hold the original data and was concatenated into this
	delete [] temp;

	// return a dereferenced this since this function needs to return a Str& (string address)
	return *this;
}

size_t Str::size() const
{
	// Easy one, just return this->size_
	return size_;
}

char& Str::operator[](unsigned int i)
{
	// This is the regular [] operator on a string
	// FORMAT: str string(james), string[2] = 'm'

	// if the index that is in the [] is bigger than this's size minus the 1 for the end character
	// that means there is no index we can refer to. throw a out of range error
	if(i > unsigned(this->size_))
    {
    	// throws into error message if out of range
        throw std::out_of_range("out of range");
    }
	else
	{
		// if the index exists, this is simple. just return this's data @ index i
		return this->data_[i];
	} 
}

char const & Str::operator[](unsigned int i) const
{
	// CHECK THIS ONE
	// same thing as above, but the char that is returned from this is const (?)
	if(i > unsigned(this->size_))
    {
        throw std::out_of_range("out of range");
    }
	else
	{
		return this->data_[i];
	} 
}

// FIX THIS ONE
Str Str::operator+(const char* rhs) const
{
	/*char* temp = this->data_;

	temp = new char[this->size_ + strlen(rhs)];
	size_ += strlen(rhs);

	strcat(this->data_, temp);
	strcat(this->data_, rhs);

	delete [] temp;

	return this;
  	*/

  	// initialize a char* array with the size of this, the rhs char* and 1 for the end character
	/*char* temp = new char[this->size_ + strlen(rhs)];

	// concatenates this and rhs into the char* temp we just initialized
  	strcat(temp, this->data_);
  	strcat(temp, rhs);

  	// creates a new string using the constructor defined above
  	// set the new string to be the same as the char* temp that we just created
  	Str c1(temp);

  	// deletes the temporarily created char* array to avoid mem leaks
  	//delete [] temp;

  	// return the fully concatenated string
  	return c1;*/

  	return Str(this->data_) += Str(rhs);
}

Str Str::operator+(const Str& rhs) const
{	
	// CHECK THIS ONE
	// same thing as above, but the Str that is returned is constant and cannot be changed (?)
	char* temp = new char[this->size_ + rhs.size_];

	//concatenates this and rhs into temp
  	strcat(temp, this->data_);
  	strcat(temp, rhs.data_);

  	//set the new string and delete temp
  	Str c1(temp);
  	delete [] temp;

  	return c1;
  	
}

bool Str::operator==(const Str& rhs)
{
	// using a bitwise operator, return true or false based on comparing the data_ and size_ of this and rhs
	return (this->data_ == rhs.data_ && this->size_ == rhs.size_);
}

bool Str::operator!=(const Str& rhs)
{
	// using a bitwise operator, return true or false based on comparing the data_ and size_ of this and rhs
	return (this->data_ != rhs.data_ && this->size_ != rhs.size_);
}

bool Str::operator>(const Str& rhs)
{
	// if this's data_ is bigger than rhs's data_, strcmp will return >0
	// >0 means that the first letter that is different between the first and second string
	// is greater in the first one (this) than the second one (rhs)

	// What we are looking at: left > right
	// since we want to return for when the first is greater than second, return for when strcmp is >0
	return strcmp(this->data_, rhs.data_) > 0;
}

bool Str::operator<(const Str& rhs)
{
	// if this's data_ is smaller than rhs's data_, strcmp will return <0
	// <0 means that the first letter that is different 
	// is smaller in the first one (this) than the second one (rhs)

	// FORMAT: left < right
	// since we want to return for when the first is smaller than the second, return for when strcmp is <0
	return strcmp(this->data_, rhs.data_) < 0;
}

// These next two are friend functions
// this means they are able to be accessed and overloaded from istream to str
std::istream& operator>>(std::istream& istr, Str& s)
{

  // take whatever is at the top of istr and put it into the new temporary string
  istr.getline(s.data_, sizeof(s.data_));

  // since this is a istream function, return the istream file
  return istr;
}

std::ostream& operator<<(std::ostream& ostr, const Str& s)
{
  // take the data_ of s (basically the string that we want) and push it into the out file
  ostr << s.data_;

  // since this is a ostream function, return the modified ostream file
  return ostr;
}