/****************************************************************************************************
                                 238. Product of Array Except Self            
-----------------------------------------------------------------------------------------------------
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal 
to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra 
space for the purpose of space complexity analysis.)
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> productExceptSelf(vector<int>& nums) {
	        int len = nums.size();
	        vector<int> rst(len,1);
	        if (len<=1) return rst;
	        
	        // forward
	        for(int i=1;i<len;i++)
	        {
	            rst[i]=rst[i-1]*nums[i-1];
	        }
	        
	        // backward
	        int curr=nums[len-1];
	        for(int i=len-2;i>=0;i--)
	        {
	            rst[i] = rst[i]*curr;
	            curr*=nums[i];
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
got the idea from the solution. it was really smart...
****************************************************************************************************/