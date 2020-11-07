#include "cmdhandler.h"
#include "util.h"
using namespace std;

// IMPORTANT FOR TwitEng::addTweet()
QuitHandler::QuitHandler()
{

}

// IMPORTANT FOR TwitEng::addTweet()
QuitHandler::QuitHandler(Handler* next)
  : Handler(next)
{

}

// IMPORTANT FOR TwitEng::addTweet()
bool QuitHandler::canHandle(const std::string& cmd) const
{
	return cmd == "QUIT";

}

// IMPORTANT FOR TwitEng::addTweet()
Handler::HANDLER_STATUS_T QuitHandler::process(TwitEng* eng, std::istream& instr) const
{
	eng->dumpFeeds();
	return HANDLER_QUIT;
}



AndHandler::AndHandler()
{
}

AndHandler::AndHandler(Handler* next)
  : Handler(next)
{
}

bool AndHandler::canHandle(const std::string& cmd) const
{
	return cmd == "AND";
}

Handler::HANDLER_STATUS_T AndHandler::process(TwitEng* eng, std::istream& instr) const
{
	vector<string> searchTerms;
	string temp;

	while(instr >> temp)
	{
		searchTerms.push_back(temp);
	}

	vector<Tweet*> searchResults = eng->search(searchTerms, 0);
	displayHits(searchResults);

	return HANDLER_OK;
}



OrHandler::OrHandler()
{
}

OrHandler::OrHandler(Handler* next)
  : Handler(next)
{
}

bool OrHandler::canHandle(const std::string& cmd) const
{
	return cmd == "OR";
}

Handler::HANDLER_STATUS_T OrHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::vector<std::string> searchTerms;
	std::string temp;

	while(instr >> temp)
	{
		searchTerms.push_back(temp);
	}

	std::vector<Tweet*> searchResults = eng->search(searchTerms, 1);
	displayHits(searchResults);

	return HANDLER_OK;
}



TweetHandler::TweetHandler()
{
}

TweetHandler::TweetHandler(Handler* next)
  : Handler(next)
{
}

bool TweetHandler::canHandle(const std::string& cmd) const
{
	return cmd == "TWEET";
}

Handler::HANDLER_STATUS_T TweetHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::string name;
	// getline(instr, name, ' ');
	instr >> name;

	// test line
	// std::cout << "NAME: " << name << std::endl;
	
	std::string text;
	DateTime time;
	
	getline(instr, text);

	// test line
	// std::cout << "TEXT: " << text << std::endl;

	// since instr was extracted with a >> then a getline(), the text as it is includes a space
	// since >> does not skip delimiters as getline() might
	// because this space should not be there, add the text in starting from index 1
	eng->addTweet(name, time, text.substr(1));
	
	return HANDLER_OK;
}

FollowHandler::FollowHandler()
{
}

FollowHandler::FollowHandler(Handler* next)
  : Handler(next)
{
}

bool FollowHandler::canHandle(const std::string& cmd) const
{
	return cmd == "FOLLOW";
}

Handler::HANDLER_STATUS_T FollowHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::string name_of_follower;
	instr >> name_of_follower;
	std::string name_to_follow;
	instr >> name_to_follow;

	eng->addFollowing(name_of_follower, name_to_follow);

	return HANDLER_OK;
}

SaveHandler::SaveHandler()
{
}

SaveHandler::SaveHandler(Handler* next)
  : Handler(next)
{
}

bool SaveHandler::canHandle(const std::string& cmd) const
{
	return cmd == "SAVE";
}

Handler::HANDLER_STATUS_T SaveHandler::process(TwitEng* eng, std::istream& instr) const
{
	std::string new_db_filename;
	instr >> new_db_filename;

	eng->create_save_db(new_db_filename);

	return HANDLER_OK;
}

LoginHandler::LoginHandler()
{

}

LoginHandler::LoginHandler(Handler* next)
  : Handler(next)
{

}

bool LoginHandler::canHandle(const string& cmd) const
{
	return cmd == "LOGIN";

}

Handler::HANDLER_STATUS_T LoginHandler::process(TwitEng* eng, istream& instr) const
{
	string username;
	string pass;
	instr >> username;
	instr >> pass;

	unsigned int encrypted_pw = calculateHash(pass);

	User* user = eng->find(username);
	if(user != NULL)
	{
		if(encrypted_pw == user->password())
		{
			cout << "Logged in." << endl;
			eng->login(user);
			return HANDLER_OK;
		}
	}

	cout << "Login failed, try again" << endl;
	return HANDLER_ERROR;


	/*
	loginSuccessful = eng->login(username, pass);

	if(loginSuccessful == false){
		cout << "Invalid username/password." << endl;
		return HANDLER_ERROR;
	}

	cout << "Login successful" << endl;
	return HANDLER_OK;
	*/
}



LogoutHandler::LogoutHandler()
{

}

LogoutHandler::LogoutHandler(Handler* next)
  : Handler(next)
{

}

bool LogoutHandler::canHandle(const string& cmd) const
{
	return cmd == "LOGOUT";

}

Handler::HANDLER_STATUS_T LogoutHandler::process(TwitEng* eng, istream& instr) const
{
	if(eng->currUser() == NULL)
	{
		cout << "Not logged in" << endl;
		return HANDLER_ERROR;
	}
	eng->login(nullptr);
	cout << "Logged out" << endl;
	return HANDLER_OK;
}