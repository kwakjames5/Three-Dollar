all: twitter

twitter: twitter.cpp user.o tweet.o datetime.o twiteng.o handler.o util.o cmdhandler.o
	g++ -g -Wall -std=c++11 twitter.cpp user.o tweet.o datetime.o twiteng.o handler.o util.o cmdhandler.o -o twitter

user.o: user.h user.cpp
	g++ -g -Wall -std=c++11 -c user.cpp -o user.o

tweet.o: tweet.h tweet.cpp
	g++ -g -Wall -std=c++11 -c tweet.cpp -o tweet.o

datetime.o: datetime.h datetime.cpp
	g++ -g -Wall -std=c++11 -c datetime.cpp -o datetime.o

twiteng.o: twiteng.h twiteng.cpp
	g++ -g -Wall -std=c++11 -c twiteng.cpp -o twiteng.o

handler.o: handler.cpp handler.h
	g++ -g -Wall -std=c++11 -c handler.cpp -o handler.o

util.o: util.cpp util.h
	g++ -g -Wall -std=c++11 -c util.cpp -o util.o

cmdhandler.o: cmdhandler.cpp cmdhandler.h
	g++ -g -Wall -std=c++11 -c cmdhandler.cpp -o cmdhandler.o

clean:
	rm twitter;
	rm -rf ./*.o
	rm -rf ./*.feed