/****************************************************************************************************
                                    258. Add Digits         
-----------------------------------------------------------------------------------------------------
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int addDigits(int num) {
	        if(num<10) return num;
	        
	        /*
	        while(num>9)
	        {
	            int curr=num; num=0;
	            while(curr>0)
	            {
	                num+=curr%10;
	                curr/=10;
	            }
	        }
	        */
	        // dr(n)=n - 9*int[(n-1)/9]
	        num=num-9*int((num-1)/9);
	        return num;
	    }
	};

}

/****************************************************************************************************
                                             Note
the formular is the key...
****************************************************************************************************/