/****************************************************************************************************
                          80. Remove Duplicates from Sorted Array II           
-----------------------------------------------------------------------------------------------------
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
It doesn't matter what you leave beyond the new length.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class MySolution {
	public:
	    int removeDuplicates(vector<int>& nums) {
	        int len=nums.size();
	        if (len<3) return len;
	        
	        int ic=1,fast=1;
	        int count=1;
	        while(fast<len)
	        {
	            if (nums[fast]==nums[fast-1])
	            {
	                while(fast<len && nums[fast]==nums[fast-1]) fast++;
	                fast--;
	            }
	            nums[ic]=nums[fast];
	            ic++;
	            fast++;
	            count++;
	        }
	        return count;
	    }
	};

	class BetterSolution {
	public:
	    int removeDuplicates(vector<int>& nums) {
	        int len=nums.size();
	        if (len<3) return len;
	        
	        int ic=0;
	        for (int i=0;i<len;i++)
	            if (ic < 2 || nums[i] > nums[ic-2])
	                nums[ic++] = nums[i];
	                
	        return ic;
	    }
	};

	class Solution {
	public:
	    int removeDuplicates(vector<int>& nums) {
	        int len = nums.size();
	        if(len<=2) return len;
	        
	        int r = 1;
	        while(r<nums.size())
	        {
	            if(r<(nums.size()-1) && nums[r]==nums[r-1] && nums[r]==nums[r+1])
	            {
	                nums.erase(nums.begin()+r);
	            }
	            else
	            {
	                r++;
	            }
	        }
	        return nums.size();
	    }
	};

}

/****************************************************************************************************
                                             Note
same idea, but the better solution is using the modified idea, which is less straightforward but 
much better. if you think in this way, it should be easy to solve. 

****************************************************************************************************/