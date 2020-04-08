#ifndef SETOPS_H
#define SETOPS_H
#include <iostream>
#include <set>
#include <string>


// Intersection
std::set<std::string> operator&(const std::set<std::string>& s1, 
                                const std::set<std::string>& s2);

// Union
std::set<std::string> operator|(const std::set<std::string>& s1, 
                                const std::set<std::string>& s2);

// Difference
std::set<std::string> operator-(const std::set<std::string>& s1,
                                const std::set<std::string>& s2); 
#endif