/****************************************************************************************************
                            154. Find Minimum in Rotated Sorted Array II           
-----------------------------------------------------------------------------------------------------
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int findMin(vector<int>& nums) {
	        int len = nums.size();
	        if (len==0) return 0;
	        if (len==1) return nums[0];
	        if (len==2) return nums[0]>nums[1]?nums[1]:nums[0];
	        
	        int s=0, t=len-1;
	        
	        while(s<t)
	        {
	            if (nums[s]<nums[t]) return nums[s];
	            
	            int mid = (s+t)/2;
	            if (nums[t]==nums[mid]) {s++;t--;}
	            else if (nums[mid]>nums[t]) s=mid+1;
	            else t=mid;
	        }
	        
	        return nums[s];
	    }
	};

}

/****************************************************************************************************
                                             Note
Just logic. Don't make it too complicate.
****************************************************************************************************/