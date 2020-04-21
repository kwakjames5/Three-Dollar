#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void readWords(char* filename, vector<vector<string> >& words);

// client interface
void generateSentences(vector<vector<string> >& words, ofstream& ofile);

// recursive helper function
void genHelper(vector<vector<string> >& words,
	       ofstream& ofile,
	       int currentOption,
	       string sentence,
	       int& numSentences);

void readWords(char* filename,vector<vector<string> >& words)
{
	ifstream ifile(filename);

	// temporary empty string to store each line from ifile
	string tempSentence;

	// check that the infile opens
	if(!ifile.is_open())
	{
		cout << "No input file." << endl;
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		// each line from the ifile that's being stored into temp sentence is the adjectives, nouns, verbs, adverbs (in that order)
		// each iteration of the forloop will get every word in each line and push them into their respective spot in the vector<vector<string>> words
		getline(ifile, tempSentence);
		stringstream ss(tempSentence);

		// empty vector<string> that will be initialized and pushed into words, which is a vector<vector<string>>
		vector<string> tempVector;

		// conditional to run ss to the end of the line
		while(ss.peek() != EOF)
		{
			// takes the stringstream and pushes into tempWord
			string tempWord;
			ss >> tempWord;

			// push tempWords into tempVector
			tempVector.push_back(tempWord);
		}

		// after getting all of the words into tempVector, push back into words (vector<vector<string>>)
		words.push_back(tempVector);
	}
}

void generateSentences(vector<vector<string> >& words, ofstream& ofile)
{
	// for when there is no adj/adv
	// inserts a empty string for when there is no adj or adverb in order for genHelper to run properly with the currentOption updating
	// this empty string otherwise does not affect the words vector<vector<string>> if there is already adjectives and adverbs present
	words[0].insert(words[0].begin(), "");
    words[3].insert(words[3].begin(), "");

    // generate sentence outfile
	int numSentences = 0;

	// pass the words vector<vector<string>>, ofile, currentOption as 0, empty sentence to be updated, and a numSentences at 0 to be updated
    genHelper(words, ofile, 0, "",  numSentences);
    ofile << numSentences << " sentences.";

    // reset the vector
    words[0].erase(words[0].begin());
    words[3].erase(words[3].begin());
}

void genHelper(vector<vector<string> >& words,
	       ofstream& ofile,
	       int currentOption,
	       string sentence,
	       int& numSentences)
{
	// for when sentence is fully formed
	// currentOption == 4 means after adverbs have been accounted for
	if(currentOption == 4)
	{
		ofile << "The " << sentence.substr(0, sentence.length() - 1) << "." << endl;
        numSentences++;
	}
	else
	{
		// go to currentOption-th index in words (0-adj, 1-noun, 2-verb, 3-adv)
		// iterate through the part of speech's words
		for(int i = 0; i < words[currentOption].size(); i++)
		{
			// add the new word into the sentence
			sentence = sentence + words[currentOption].at(i);

			// increase size according to the length of the new word
			int size = words[currentOption].at(i).length();

			// when the new word is just a space / empty
			if(!words[currentOption].at(i).empty())
			{
				// need to add a space
				sentence += " ";

				// size goes up 1 for the space
				size++;
			}

			// recursize call
			// genHelper is called here recursively because essentially, every word in every part of speech index needs to have 
			// a sentence done with the other words in the other parts of speeches. since this program needs to produce as many sentences as possible
			// given a certain set of adjectives, nouns, verbs, and adverbs, each adjective needs to be made into a sentence with each noun, each 
			// noun (which will be described by every adjective) with each verb and each verb (paired up with each noun) with each adverb
			genHelper(words, ofile, currentOption + 1, sentence, numSentences);

			// sets the sentence back to before the new word was input so the next word in the line can be put in without overlapping with the previous one
            sentence = sentence.substr(0, sentence.length() - size);
		}
	}
}

int main(int argc, char* argv[])
{
  if(argc < 3){
    cerr << "Usage ./sentences input_file output_file" << endl;
  }
  vector<vector<string> > words;

  // Parse the file
  readWords(argv[1], words);

  // Check the status of parsing
  if(words.size() < 4){
    cerr << "Input file requires 4 lines of words" << endl;
    return 1;
  }

  // Open the output file
  ofstream ofile(argv[2]);
 
  // generate all the sentence options writing them to ofile
  generateSentences(words, ofile);

  ofile.close();

  return 0;
}
