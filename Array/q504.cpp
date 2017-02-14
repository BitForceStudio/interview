/****************************************************************************************************
                                      504. Base 7       
-----------------------------------------------------------------------------------------------------
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string convertToBase7(int num) {
	        if (num<7 && num>-7) return to_string(num);
	        string rst="";
	        int curr=abs(num%7);
	        rst=convertToBase7(int(num/7));
	        
	        return rst+to_string(curr);
	    }
	};

}

/****************************************************************************************************
                                             Note
if negtive, keep the first one.
****************************************************************************************************/