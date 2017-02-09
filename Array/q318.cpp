/****************************************************************************************************
                             318. Maximum Product of Word Lengths       
-----------------------------------------------------------------------------------------------------
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two 
words do not share common letters. You may assume that each word will contain only lower case letters. 
If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maxProduct(vector<string>& words) {
	        int len=words.size();
	        if (len<=1) return 0;
	        
	        int max=0;
	        int curr=0;
	        vector<int> numw(len,0);
	        for(int i=0;i<len;i++)
	        {
	            for(int j=0;j<words[i].size();j++)
	            {
	                numw[i]|=1<<(char(words[i][j])-'a'); // move n bit to the left and | with it original 
	            }
	            for(int j=0;j<i;j++)
	            {
	                if ((numw[i]&numw[j])==0)
	                {
	                    curr=words[i].size()*words[j].size();
	                    if (curr>max) max=curr;
	                }
	            }
	        }

	        return max;
	    }
	};

}

/****************************************************************************************************
                                             Note
I thought about convert the words to number and then compare. but using bit is very clever. 
****************************************************************************************************/