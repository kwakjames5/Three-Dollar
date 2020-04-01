#include <bits/stdc++.h>

int main()
{
	std::ofstream ofile("output.txt", std::ofstream::out);
	std::ifstream ifile("input.txt", std::ifstream::in);

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

	return 0;
}