/****************************************************************************************************
                                     279. Perfect Squares            
-----------------------------------------------------------------------------------------------------
Given a positive integer n, find the least number of perfect square numbers 
(for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int numSquares(int n) {
	        if (n==1 || n==0) return 1;
	        
	        return helper(n,0,2147483647);
	    }
	    
	    int helper(int n, int level, int cmin) {
	        if (n==1 || n==0) return 1;
	        if (level>=cmin) return level;
	        
	        int p=0,l=0;
	        int num=1,curr=1;
	        int min=cmin;
	        p = int(sqrt(n));
	        l = n-p*p;
	        
	        if (l==0) return 1;
	        int low = p/2;
	        while (p>=low)
	        {
	            num=helper(l,level+1,min);
	            curr+=num;
	            if (curr<min) min=curr;
	            if (min==2) break;
	            curr-=num;
	            p--;
	            l=n-p*p;
	        }
	        
	        return min;
	    }
	};
}

/****************************************************************************************************
                                             Note
The problem is : lower bound and when to return. 
****************************************************************************************************/