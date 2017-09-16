/****************************************************************************************************
                                    541. Reverse String II         
-----------------------------------------------------------------------------------------------------
Given a string and an integer k, you need to reverse the first k characters for every 2k characters 
counting from the start of the string. If there are less than k characters left, reverse all of them. 
If there are less than 2k but greater than or equal to k characters, then reverse the first k 
characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string reverseStr(string s, int k) {
	        int len=s.size();
	        if (k<=1) return s;
	        int i=0;
	        while(i<len)
	        {
	            int j = min(i+k-1,len-1);
	            int t=i;
	            while(t<j)
	            {
	                char tmp = s[t];
	                s[t++]=s[j];
	                s[j--]=tmp;
	            }
	            i+=2*k;
	        }
	        return s;
	    }
	};

}

/****************************************************************************************************
                                             Note
Esay. j = min(i+k-1, len)  -> j = min(i+k-1, len-1)
****************************************************************************************************/