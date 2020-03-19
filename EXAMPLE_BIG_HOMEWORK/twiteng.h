#ifndef TWITENG_H
#define TWITENG_H
#include <map>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "user.h"
#include "datetime.h"
#include "tagdata.h"
#include "hash.h"
#include "heap.h"

class TwitEng
{
 public:
  TwitEng();
  ~TwitEng();
  /**
   * Parses the Twitter database and populates internal structures
   * @param filename of the database file
   * @return true if there is an error, false if successful
   */
  bool parse(char* filename);

  /**
   * Allocates a tweet from its parts and adds it to internal structures
   * @param username of the user who made the tweet
   * @param timestamp of the tweet
   * @param text is the actual text of the tweet as a single string
   */
  void addTweet(const std::string& username, const DateTime& time, const std::string& text);

  /**
   * Searches for tweets with the given words and strategy
   * @param words is the hashtag terms in any case without the '#'
   * @param strategy 0=AND, 1=OR
   * @return the tweets that match the search
   */
  std::vector<Tweet*> search(std::vector<std::string>& terms, int strategy);

  /**
   * Dump feeds of each user to their own file
   */
  void dumpFeeds();

  void addFollowing(std::string name_of_follower, std::string name_to_follow);

  void create_save_db(std::string filename);

  void make_scc(std::string filename);

  void trending(int num);

  bool login(std::string, std::string);

  std::string currUser();

  bool currStatus();

  void changeStatus(bool);

  void logout(User*);

  /* You may add other member functions */
 private:
  /* Add any other data members or helper functions here  */
  std::list<Tweet*> tweets_;
  std::map<std::string, User*> masterUsers_;
  std::map<std::string, std::set<Tweet*>> masterHashtags_;
  std::map<std::string, std::string> logins_;

  User* currUser_;
  bool currStatus_;
  Heap<TagData, TagStringEqual, TagIntGreater, TagStringHasher> trending_;
};


#endif
