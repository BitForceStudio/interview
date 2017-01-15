/****************************************************************************************************
                                        202. Happy Number     
-----------------------------------------------------------------------------------------------------
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, 
replace the number by the sum of the squares of its digits, and repeat the process until the number 
equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those 
numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isHappy(int n) {
	        if (n<=1) return true;
	        
	        map<int,bool> isAppear;   // **
	        while(true)
	        {
	            int ss = getSqrtSum(n);
	            if (ss==1) return true;
	            else if (isAppear[ss]) return false;
	            isAppear[ss] = true;
	            n=ss;
	        }
	        return false;
	    }
	    
	    int getSqrtSum(int n)
	    {
	        int rst=0;
	        while(n!=0)
	        {
	            int tmp = n%10;
	            rst+=tmp*tmp;
	            n/=10;
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
** use a map to record appearince. if appeared, it means it will go into a loop. 
****************************************************************************************************/