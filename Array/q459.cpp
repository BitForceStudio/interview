/****************************************************************************************************
                                   459. Repeated Substring Pattern          
-----------------------------------------------------------------------------------------------------
Given a non-empty string check if it can be constructed by taking a substring of it and appending 
multiple copies of the substring together. You may assume the given string consists of lowercase 
English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool repeatedSubstringPattern(string s) {
	        // kmp pattern vector
	        int len=s.size();
	        if (len<=1) return false;
	        int i=1,j=0;
	        vector<int> dp(len+1,0);
	        while(i<len)
	        {
	            if (s[i]==s[j]) dp[++i]=++j;
	            else if(j==0) i++;
	            else j=dp[j];
	        }
	        return dp[len] && dp[len]%(len-dp[len])==0; // repeat pattern length = len-dp[len]
	    }
	};

}

/****************************************************************************************************
                                             Note
KMP table. Understand KMP...
****************************************************************************************************/