/****************************************************************************************************
                                   162. Find Peak Element         
-----------------------------------------------------------------------------------------------------
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int findPeakElement(vector<int>& nums) {
	        int len=nums.size();
	        // special cases
	        if (len<=1) return 0;
	        if(nums[0]>nums[1])         return 0;
	        if(nums[len-1]>nums[len-2]) return len-1;
	        
	        // if A[mid-1]<A[mid]>A[mid+1] return mid
	        // if A[mid-1]>A[mid]>A[mid+1] t=mid;
	        // if A[mid-1]<A[mid]<A[mid+1] s=mid;
	        // if A[mid-1]>A[mid]<A[mid+1] both said
	        return find(nums,1,len-2,len);
	    }
	    
	    int find(vector<int>& nums, int s, int t, int len)
	    {
	        int mid=(s+t)/2;
	        if (s==t) return s;
	        else if (s+1==t)
	        {
	            return nums[s]>nums[t]?s:t;
	        }
	        else if ( mid>0 && mid<len-1 && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) 
	        {
	            return mid;
	        }
	        else if ( mid>0 && mid<len-1 && nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]) 
	        {
	            return find(nums,mid,t,len);
	        }
	        else if ( mid>0 && mid<len-1 && nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1])
	        {
	            return find(nums,s,mid,len);
	        }
	        else if (mid>0 && mid<len-1 && nums[mid-1]>nums[mid] && nums[mid]<nums[mid+1])
	        {
	            return find(nums,s,mid,len);
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note

****************************************************************************************************/