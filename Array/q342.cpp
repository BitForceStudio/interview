/****************************************************************************************************
                                    342. Power of Four         
-----------------------------------------------------------------------------------------------------
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isPowerOfFour(int num) {
	        return num>0 && (num & (num-1))==0 && (num-1)%3==0;
	        // return num>0 && 1073741824%num==0 && (num-1)%3==0;
	    }
	};

}

/****************************************************************************************************
                                             Note
(num-1) % 3 ==0 is very clever
****************************************************************************************************/