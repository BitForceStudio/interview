/****************************************************************************************************
                                      343. Integer Break       
-----------------------------------------------------------------------------------------------------
Given a positive integer n, break it into the sum of at least two positive integers and maximize the 
product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int integerBreak(int n) {
	        int max=0; //**
	        int div = 2;
	        while(div<=n)
	        {
	            int c = n/div;
	            int m = n%div;
	            int curr=1;
	            for(int i=0;i<div;i++) 
	            {
	                if (i<m) curr*=(c+1);
	                else curr*=c;
	            }
	            if (curr>max) max=curr;
	            else break;
	            div++;
	        }
	        return max;
	    }
	};

}

/****************************************************************************************************
                                             Note
** set to 0 at begining.
****************************************************************************************************/