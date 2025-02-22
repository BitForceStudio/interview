/****************************************************************************************************
                                      263. Ugly Number                
-----------------------------------------------------------------------------------------------------
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are 
ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isUgly(int num) {
	        if (num==0) return false;
	        if (num==1) return true;
	        while(num%2==0) num>>1;
	        while(num%3==0) num/=3;
	        while(num%5==0) num/=5;
	        return num==1;
	    }
	};

}

/****************************************************************************************************
                                             Note
No better solution
****************************************************************************************************/