#include "cmdhandler.h"
#include "util.h"
using namespace std;

QuitHandler::QuitHandler()
{

}

QuitHandler::QuitHandler(Handler* next)
  : Handler(next)
{

}

bool QuitHandler::canHandle(const std::string& cmd) const
{
	return cmd == "QUIT";

}

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
	std::vector<std::string> searchTerms;
	std::string temp;

	while(instr >> temp)
	{
		searchTerms.push_back(temp);
	}

	std::vector<Tweet*> searchResults = eng->search(searchTerms, 0);
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
	instr >> name;
	std::string text;
	DateTime time;
	
	getline(instr, text);
	eng->addTweet(name, time, text);
	
	return HANDLER_OK;
}