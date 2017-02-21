/****************************************************************************************************
                                    287. Find the Duplicate Number      
-----------------------------------------------------------------------------------------------------
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int findDuplicate(vector<int>& nums) {
	        int len=nums.size();
	        if (len<=1) return 0;
	        
	        int s=nums[0];
	        int f=nums[nums[0]];
	        
	        while(s!=f)
	        {
	            s=nums[s];
	            f=nums[nums[f]];
	        }
	        
	        f=0;
	        while (s!=f)
	        {
	            s=nums[s];
	            f=nums[f];
	        }
	        
	        return s;
	    }
	};

}

/****************************************************************************************************
                                             Note
There are several points that direct it to the linked list...
****************************************************************************************************/