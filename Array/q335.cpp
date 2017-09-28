/****************************************************************************************************
                                    335. Self Crossing               
-----------------------------------------------------------------------------------------------------
You are given an array x of n positive numbers. You start at point (0,0) and moves x[0] metres to 
the north, then x[1] metres to the west, x[2] metres to the south, x[3] metres to the east and so on. 
In other words, after each move your direction changes counter-clockwise.

Write a one-pass algorithm with O(1) extra space to determine, if your path crosses itself, or not.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isSelfCrossing(vector<int>& x) {
	        int len=x.size();
	        if (len<=3) return false;

	        for(int i=3;i<len;i++)
	        {
	            // i-3
	            if (x[i]>=x[i-2] && x[i-1]<=x[i-3]) return true;
	            // i-4
	            if (i>=4 && x[i-3]==x[i-1] && x[i-2]==(x[i-4]+x[i])) return true;
	            // i-5
	            if (i>=5 && x[i-5]<=x[i-3] && x[i-4]<=x[i-2] && x[i-1]<=x[i-3] && x[i-1]>=(x[i-3]-x[i-5]) && x[i]>=(x[i-2]-x[i-4]))
	                return true;
	        }
	        
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
1: don't forget =
2: ask the interviewer, overlap? 
****************************************************************************************************/