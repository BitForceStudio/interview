/****************************************************************************************************
                               81. Search in Rotated Sorted Array II           
-----------------------------------------------------------------------------------------------------
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool search(vector<int>& nums, int target) {
	        int len=nums.size();
	        if (len==0) return false;
	        
	        int l=0,r=len-1;
	        int mid=0;
	        while(l<r)
	        {
	            mid=(l+r)/2;
	            if(nums[mid]==target) return true;
	            else if(nums[mid]>nums[r])
	            {
	                if (nums[mid]>target && nums[l]<=target) r=mid;
	                else l=mid+1;
	            }
	            else if (nums[mid]<nums[r])
	            {
	                if (nums[mid]<target && nums[r]>=target) l=mid+1;
	                else r=mid;
	            }
	            else
	            {
	                r--;
	            }
	        }
	        
	        return target==nums[l];
	        
	    }
	};

}

/****************************************************************************************************
                                             Note
there is one additional one: r--. 
can ** do better? 

****************************************************************************************************/