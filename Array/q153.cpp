/****************************************************************************************************
                         153. Find Minimum in Rotated Sorted Array            
-----------------------------------------------------------------------------------------------------
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
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
	        
	        int s=0,t=len-1;
	        while(s<t)
	        {
	            int mid = (s+t)/2;
	            if (mid==s) return nums[s]>nums[t]?nums[t]:nums[s];  // ***
	            
	            else if (nums[mid]>nums[s] && nums[mid]>nums[t]) s=mid+1;
	            else if (nums[mid]>nums[s] && nums[mid]<nums[t]) return nums[s];
	            else if (nums[mid]<nums[s] && nums[mid]<nums[t]) t=mid;
	            else return nums[mid+1];
	        }
	        
	        return nums[s];
	    }
	};

	class Solution {
	public:
	    int findMin(vector<int>& nums) {
	        if (nums.size()==0) return 0;
	        if (nums.size()==1) return nums[0];
	        
	        int s=0,t=nums.size()-1;
	        int mid=0;
	        while(s<t)
	        {
	            mid = (s+t)/2;
	            if (nums[s]<nums[t]) break;
	            else if (nums[mid]>=nums[s]) s=mid+1;
	            else t=mid;
	        }
	        return nums[s];
	    }
	};

}

/****************************************************************************************************
                                             Note
this one just need to find the minimum one, considered all the possible solutions. 
*** if t-s==1, then return the smaller one.
****************************************************************************************************/