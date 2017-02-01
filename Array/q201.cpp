/****************************************************************************************************
                              201. Bitwise AND of Numbers Range               
-----------------------------------------------------------------------------------------------------
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this 
range, inclusive.

For example, given the range [5, 7], you should return 4.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int rangeBitwiseAnd(int m, int n) {
	        while(n>m) n=n&(n-1);
	        return n;
	    }
	};

}

/****************************************************************************************************
                                             Note
Think about it, it just keep all the left 1's
****************************************************************************************************/