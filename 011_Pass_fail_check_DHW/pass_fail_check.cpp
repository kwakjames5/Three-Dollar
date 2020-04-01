#include <bits/stdc++.h>
#include <map>

int main()
{
	std::ofstream ofile("output.txt", std::ofstream::out);
	std::ifstream ifile("input.txt", std::ifstream::in);

	// map with string as key and pair<int, int> as values
	// pair first is passes, pair second is fails
	std::map<std::string, std::pair<int, int> > myMap;

	// read to the end of file
	while(!ifile.eof())
	{	
		// s will hold the first three letters, which indicate the name of whatever we are tracking
		// temp will be used for any other strings we need to read and hold (pass, fail)
		std::string s;
		std::string temp;
		std::getline(ifile, s, ',');

		// if the find iterator has hit the end of the map, it means that s, or the name, does not exist in the map yet
		if(myMap.find(s) == myMap.end())
		{
			// create a new key with a pair 0 0 to indicate the initial pass and fail values
			myMap[s] = std::make_pair(0, 0);

			// ignore all chars in between until the next comma
			// then read the next word into temp (either pass or fail)
			ifile.ignore(INT_MAX, ',');
			std::getline(ifile, temp, '\n');

			// based on temp, update accordingly
			if(temp == "pass")
			{	
				// at key s in the map, add 1 to the first of the pair
				myMap[s].first++;
			}
			else
			{
				// at key s in the map, add 1 to the second of the pair
				myMap[s].second++;
			}
		}
		else
		{
			ifile.ignore(INT_MAX, ',');
			std::getline(ifile, temp, '\n');

			if(temp == "pass")
			{
				myMap[s].first++;
			}
			else
			{
				myMap[s].second++;
			}
		}
	}

	// an iterator that can traverse through a map like myMap
	std::map<std::string, std::pair<int, int> >::iterator it;

	// iterate from the beginning of myMap to the end
	for(it = myMap.begin(); it != myMap.end(); it++)
	{
		ofile << it->first << " pass:" << it->second.first << " fail:" << it->second.second << std::endl;
	}

	ofile.close();

	return 0;

	/*
	int fioFail = 0, fioPass = 0, ungFail = 0, ungPass = 0, graFail = 0, graPass = 0, cliFail = 0, cliPass = 0;

	while(!ifile.eof())
	{
		std::string s;
		std::getline(ifile, s, ',');

		if(s == "fio")
		{
			ifile.ignore(5, ',');

			std::string t;
			std::getline(ifile, t, '\n');

			if(t == "pass")
			{
				fioPass++;
			}
			else
			{
				fioFail++;
			}
		}

		if(s == "ung")
		{
			ifile.ignore(5, ',');

			std::string t;
			std::getline(ifile, t, '\n');

			if(t == "pass")
			{
				ungPass++;
			}
			else
			{
				ungFail++;
			}
		}

		if(s == "gra")
		{
			ifile.ignore(5, ',');

			std::string t;
			std::getline(ifile, t, '\n');

			if(t == "pass")
			{
				graPass++;
			}
			else
			{
				graFail++;
			}
		}

		if(s == "cli")
		{
			ifile.ignore(5, ',');

			std::string t;
			std::getline(ifile, t, '\n');

			if(t == "pass")
			{
				cliPass++;
			}
			else
			{
				cliFail++;
			}
		}
	}

	ofile << "fio pass=" << fioPass << " fail=" << fioFail << std::endl;
	ofile << "ung pass=" << ungPass << " fail=" << ungFail << std::endl;
	ofile << "gra pass=" << graPass << " fail=" << graFail << std::endl;
	ofile << "cli pass=" << cliPass << " fail=" << cliFail << std::endl;
	*/
}