#include "max_balloons.h"
#include <iostream>
#include <map>
#include <string>

// link: https://leetcode.com/problems/maximum-number-of-balloons/

// date: 6/22/2020

// description: given a string, return how many times the word "balloon" can be formed with the characters in the string

// ex) intput: krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdgtykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtmazxdbzwxthpvrfulvrspycqcghuopjirzoeuqhetnbrcdakilzmklxwudxxhwilasbjjhhfgghogqoofsufysmcqeilaivtmfziumjloewbkjvaahsaaggteppqyuoylgpbdwqubaalfwcqrjeycjbbpifjbpigjdnnswocusuprydgrtxuaojeriigwumlovafxnpibjopjfqzrwemoinmptxddgcszmfprdrichjeqcvikynzigleaajcysusqasqadjemgnyvmzmbcfrttrzonwafrnedglhpudovigwvpimttiketopkvqw
// output: 10

int Solution::maxNumberOfBalloons(std::string text) 
{
	int max_balloons = 0;

    std::map<char, int> text_track;
    std::map<char, int> balloon_track;
    std::string balloon = "balloon";
    std::map<char, int>::iterator it;

    for(int j = 0; j < balloon.size(); j++)
    {
    	balloon_track[balloon[j]]++;
    }

    /*
    std::cout << "Balloon map: " << std::endl;

    for(it = balloon_track.begin(); it != balloon_track.end(); it++)
    {
    	std::cout << it->first << ": " << it->second << std::endl;
    }
    */
    
    for(int i = 0; i < text.size(); i++)
    {
    	// if the balloon map has the current char in the text string
    	if(balloon_track.find(text[i]) != balloon_track.end())
    	{
        	text_track[text[i]]++;
    	}
    }
    
    int a_b_n_track = 0;
    int l_o_track = 0;

    for(it = text_track.begin(); it != text_track.end(); it++)
    {
    	if(it->first == 'a' || it->first == 'b' || it->first == 'n')
    	{
    		if(a_b_n_track == 0)
    		{
    			a_b_n_track = it->second;
    		}
    		else if(it->second < a_b_n_track)
    		{
    			a_b_n_track = it->second;
    		}
    			
    	}

    	if(it->first == 'l' || it->first == 'o')
    	{
    		if(l_o_track == 0)
    		{
    			l_o_track = it->second;
    		}
    		else if(it->second < l_o_track)
    		{
    			l_o_track = it->second;
    		}
    	}

    	std::cout << "a_b_n: " << a_b_n_track << " " << "l_o: " << l_o_track << std::endl;
    }

    while(a_b_n_track * 2 > l_o_track)
    {
    	a_b_n_track--;
    }

    std::cout << "a_b_n: " << a_b_n_track << std::endl;

    max_balloons = a_b_n_track;
    return max_balloons;

    /*
    if(l_o_track < a_b_n_track * 2)
    {
    	max_balloons = 0;
    	return max_balloons;
    }
    else 
    {
    	max_balloons = a_b_n_track;
    	return max_balloons;
    }
    */
}

int main()
{
	std::string text;
	std::cout << "Enter the test text: " << std::endl;
	std::cin >> text;

	Solution solution;
	int max_balloons = solution.maxNumberOfBalloons(text);

	std::cout << "Max Balloons: " << max_balloons << std::endl;

	return 0;
}