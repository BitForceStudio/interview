/****************************************************************************************************
                                     283. Move Zeroes        
-----------------------------------------------------------------------------------------------------
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative 
order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be 
[1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    void moveZeroes(vector<int>& nums) {
	        int len=nums.size();
	        if (len<=1) return;
	        int s=0,f=1;  // s: current index, f: first none 0 index after s;
	        while(f<len && nums[f]==0) f++;
	        while(f<len)
	        {
	            if (nums[s]==0) swap(nums,s,f);
	            s++; if (f==s) f++;
	            while(f<len && nums[f]==0) f++;
	        }
	    }
	    
	    void swap(vector<int>& nums,int i,int j)
	    {
	        int t=nums[i];
	        nums[i]=nums[j];
	        nums[j]=t;
	    }
	};

}

/****************************************************************************************************
                                             Note
f should less than len.
****************************************************************************************************/