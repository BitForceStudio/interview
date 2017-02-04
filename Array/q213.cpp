/****************************************************************************************************
                                      213. House Robber II            
-----------------------------------------------------------------------------------------------------
After robbing those houses on that street, the thief has found himself a new place for his thievery 
so that he will not get too much attention. This time, all houses at this place are arranged in a 
circle. That means the first house is the neighbor of the last one. Meanwhile, the security system 
for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the 
maximum amount of money you can rob tonight without alerting the police
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int rob(vector<int>& nums) {
	        // dp problem 
	        // if rob current house, it plus the previous none rob current one
	        // if not rub current one, it is the max of rob previous one or the none rob prev
	        int len=nums.size();
	        if (len==0) return 0;
	        if (len==1) return nums[0];
	        if (len==2) return max(nums[0],nums[1]);
	        int nfirst=robHouse(nums,1,len);
	        int rfirst=robHouse(nums,0,len-1);
	        return max(nfirst,rfirst);
	    }
	    
	    int robHouse(vector<int>& nums, int s, int t)
	    {
	        int curr=0,ncurr=0;
	        for(int i=s;i<t;i++)
	        {
	            int tmp=curr;
	            curr=ncurr+nums[i];
	            ncurr=max(tmp,ncurr);
	        }
	        return max(curr,ncurr);
	    }
	};

}

/****************************************************************************************************
                                             Note
it acturally the two robs, first is the rob the first, and the second is not rob first.
****************************************************************************************************/