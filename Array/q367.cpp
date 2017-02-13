/****************************************************************************************************
                                     367. Valid Perfect Square       
-----------------------------------------------------------------------------------------------------
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isPerfectSquare(int num) {
	        if (num==0 || num==1) return true;
	        
	        long long s=1,t=num/2,mid=0;
	        int tmp=0;
	        while(s<=t)  // **
	        {
	            mid=s+(t-s)/2;
	            long long tmp=mid*mid;
	            if (tmp==num) return true;
	            
	            if (tmp<num) s=mid+1;
	            else t=mid-1;  // ***
	        }
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
** corner cases
*** should be this?
****************************************************************************************************/