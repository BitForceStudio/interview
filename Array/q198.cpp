/****************************************************************************************************
                                         198. House Robber        
-----------------------------------------------------------------------------------------------------
You are a professional robber planning to rob houses along a street. Each house has a certain amount 
of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses 
have security system connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the 
maximum amount of money you can rob tonight without alerting the police.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int rob(vector<int>& nums) {
	        // DP problem
	        // rob this house or not
	        // if rob it: curr = money(not rob previous one) + current money
	        // if not rob it: curr = max(money(not rob previous one) , money(rob previous one))
	        int len = nums.size(); 
	        if (len==0) return 0;
	        int rcurr = 0;
	        int nrcurr = 0;
	        for(int i=0;i<len;i++)
	        {
	            int tmp = rcurr;
	            rcurr = nrcurr + nums[i];
	            nrcurr = tmp>nrcurr?tmp:nrcurr;
	        }
	        return rcurr>nrcurr?rcurr:nrcurr;
	    }
	};
}

/****************************************************************************************************
                                             Note
DP problem.
Why i%2 is working? I don't understand...
****************************************************************************************************/