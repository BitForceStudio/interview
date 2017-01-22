/****************************************************************************************************
                                       242. Valid Anagram      
-----------------------------------------------------------------------------------------------------
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isAnagram(string s, string t) {
	        if(s.size()!=t.size()) return false;
	        vector<int> tab(26,0);
	        int len=s.size();
	        for(int i=0;i<len;i++)
	        {
	            tab[s[i]-'a']++;
	            tab[t[i]-'a']--;
	        }
	        
	        for(int i=0;i<26;i++) 
	        {
	            if(tab[i]!=0) return false;
	        }
	        return true;
	    }
	};

}

/****************************************************************************************************
                                             Note
it said it just contain the lowercase. dont' forget this condition.
****************************************************************************************************/