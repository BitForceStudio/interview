/****************************************************************************************************
                                   209. Minimum Size Subarray Sum          
-----------------------------------------------------------------------------------------------------
Given an array of n positive integers and a positive integer s, find the minimal length of a 
contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity 
is O(n log n).
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int minSubArrayLen(int s, vector<int>& nums) {
	        int len=nums.size();
	        if (len<=1) return 0;
	        
	        int curr=nums[0];
	        int crange=1;
	        int rrange=len;
	        int slow=0,fast=1;
	        bool qfound=false;
	        while (fast<=len && slow<=fast)
	        {
	            if (curr<s) 
	            {
	                if (fast==len) break;
	                curr+=nums[fast];
	                fast++;
	                crange++;
	            }
	            else if (curr>=s)
	            {
	                if(crange<rrange) rrange=crange;
	                curr-=nums[slow];
	                crange--;
	                slow++;
	                if (slow==fast) return 1;  // if 1, then return because it will be the smallest
	                qfound=true;
	            }
	        }
	        return qfound?rrange:0;
	    }
	};

}

/****************************************************************************************************
                                             Note
This O(n) is easy. the O(nlogn) is bit of tricky.
Use Binary Search to get the window, then, apply this window to search the sum, if santified, return
true for this window.
****************************************************************************************************/