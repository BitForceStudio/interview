/****************************************************************************************************
                                   345. Reverse Vowels of a String          
-----------------------------------------------------------------------------------------------------
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string reverseVowels(string s) {
	        if (s.size()<=1) return s;
	        int t=s.size();
	        set<char> vowels;
	        vowels.insert('a');
	        vowels.insert('e');
	        vowels.insert('i');
	        vowels.insert('o');
	        vowels.insert('u');
	        vowels.insert('A');
	        vowels.insert('E');
	        vowels.insert('I');
	        vowels.insert('O');
	        vowels.insert('U');
	        
	        int b=0;
	        while(b<t)
	        {
	            while (vowels.find(s[b])==vowels.end()) b++;
	            while (vowels.find(s[t])==vowels.end()) t--;
	            if (b>=t) break;
	            char tmp=s[b];
	            s[b]=s[t];
	            s[t]=tmp;
	            b++;
	            t--;
	        }
	        
	        return s;
	    }
	};

}

/****************************************************************************************************
                                             Note
convert it to int?
****************************************************************************************************/