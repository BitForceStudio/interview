/****************************************************************************************************
                                    290. Word Pattern         
-----------------------------------------------------------------------------------------------------
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a 
non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated 
by a single space.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool wordPattern(string pattern, string str) {
	        int lenp = pattern.size();
	        int lens = str.size();
	        stringstream words;
	        words<<str;
	        if (lenp==0) return false;
	        vector<string> map(26,"");
	        set<string> usedword;
	        int curr=0;
	        for(int i=0;i<lenp;i++)
	        {
	            string word;
	            if (words.eof()) return false;
	            words>>word;
	            curr=pattern[i]-'a';
	            if (map[curr]=="" && usedword.find(word)==usedword.end()) 
	            {
	                map[curr]=word;
	                usedword.insert(word);
	            }
	            else
	            {
	                if (map[curr]!="" && map[curr]==word) continue;
	                else return false;
	            }
	        }
	        curr=0;
	        while (!words.eof()) 
	        {
	            string word;
	            words>>word;
	            if (word!="") curr++; 
	        }
	        return curr==0?true:false;
	    }
	};

}

/****************************************************************************************************
                                             Note
The catch is the number of word may not equals to the number of patterns. and multi mapping
****************************************************************************************************/