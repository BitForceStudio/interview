/****************************************************************************************************
                                  409. Longest Palindrome           
-----------------------------------------------------------------------------------------------------
Given a string which consists of lowercase or uppercase letters, find the length of the longest 
palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int longestPalindrome(string s) {
	        int len = s.size();
	        if (len<=1) return len;
	        map<int,int> count;
	        for(int i=0;i<len;i++)
	        {
	            count[int(s[i])]++;
	        }
	        int rst=0;
	        for(map<int,int>::iterator it=count.begin();it!=count.end();it++)
	        {
	            if ((it->second)%2==1)
	            {
	                if (rst%2==0) rst+=1;
	                rst+=it->second-1;
	            }
	            else rst+=it->second;
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Main idea is the count all elements that more than once. 
if there is odd element, add one then. 
****************************************************************************************************/