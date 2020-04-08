#include <set>
#include <map>
#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include "setops.h"

int main(int argc, char* argv[])
{
	std::ifstream MyFile1(argv[1]);
	std::ifstream MyFile2(argv[2]);
	std::ofstream MyFile3(argv[3]);

	std::map<std::string, std::set<std::string> > smap;
	std::map<std::string, std::set<std::string> > mmap;

	std::map<std::string, std::set<std::string> >::iterator a;
	std::map<std::string, std::set<std::string> >::iterator b;

	std::set<std::string>::iterator set;

	if (MyFile1.is_open())
	{
		std::string names, m;

		while (getline(MyFile1, names, ',') && getline(MyFile1, m))
		{
			std::stringstream ss1(names);
			std::stringstream ss2(m);
			std::string name;
			std::string storage;

			while (ss1 >> storage)
			{
				name += storage + ' ';
			}

			a = smap.find(name);

			if(a != smap.end())
			{
				std::string temp;
				while(ss2 >> temp)
				{
					a->second.insert(temp);
				}
			}
			else
			{
				std::string temp;
				std::set<std::string> m;
				while(ss2 >> temp)
				{
					m.insert(temp);
				}
				smap[names] = m;
			}
		}

	}
	else
		{
			return -1;
		}

	MyFile1.close();
	MyFile1.clear();

	if (MyFile2.is_open())
	{
		std::set<std::string> majors;
		std::set<std::string>::iterator it_majors = majors.begin();
		std::string temp;

		while (getline(MyFile2,temp))
		{
			majors.insert(temp);
		}

		std::set<std::string> i;

		for (a = smap.begin(); a != smap.end(); a++)
		{
			i = a->second & majors;
			if (i.size() == 1)
			{
				b = mmap.find(*i.begin());
				if(b != mmap.end())
				{
					b->second.insert(a->first);
				}
				else
				{
					std::set<std::string> s;
					s.insert(a->first);
					mmap[*i.begin()] = s;
				}
			}
			else if(i.size() > 0)
			{
				for (set = i.begin(); set != i.end(); set++)
				{
					b = mmap.find(*set);
					if(b != mmap.end())
					{
						b->second.insert(a->first);
					}
					else
					{
						std::set<std::string> s;
						s.insert(a->first);
						mmap[*set] = s;
					}
				}
			}
		}
	}
	else
		{
			return -1;
		}

	for (a = mmap.begin(); a != mmap.end(); a++)
	{
		MyFile3 << a->first << "\n";
		for (set = a->second.begin(); set != a->second.end(); set++)
		{
			MyFile3 << *set << "\n";
		}
		MyFile3 << "\n";
	}
	
	return 0;	
}
