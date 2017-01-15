/****************************************************************************************************
                                      69. Sqrt(x)       
-----------------------------------------------------------------------------------------------------
Implement int sqrt(int x).

Compute and return the square root of x.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int mySqrt(int x) {
	        if (x==0) return 0;
	        int ulim = 1;
	        int tmp=x;
	        while(tmp!=0)
	        {
	            tmp/=100;
	            ulim*=10;
	        }

	        int llim = ulim/10;
	        while(llim<ulim-1)
	        {
	            long long middle = (ulim+llim)/2;   // need to consider the overflowing problem
	            long long mult = middle * middle;
	            if (mult>2147483647) ulim = middle;
	            else if (mult>x) ulim = middle;
	            else llim=middle;
	        }
	        return llim;
	    }
	};

}

/****************************************************************************************************
                                             Note
Overflowing is the key. 
and lower limit can be improved using this method. 

****************************************************************************************************/