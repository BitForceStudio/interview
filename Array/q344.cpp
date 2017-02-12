/****************************************************************************************************
                                   344. Reverse String          
-----------------------------------------------------------------------------------------------------
Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string reverseString(string s) {
	        if(s.size()<=1) return s;
	        int len=s.size();
	        string rst(s);
	        for(int i=s.size()-1;i>=0;i--)
	        {
	            rst[len-i-1]=s[i];
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Nothing...better than swapping?
****************************************************************************************************/