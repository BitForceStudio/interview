/****************************************************************************************************
                                  442. Find All Duplicates in an Array           
-----------------------------------------------------------------------------------------------------
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others 
appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> findDuplicates(vector<int>& nums) {
	        int len=nums.size();
	        vector<int> rst;
	        if (len<=1) return rst;
	        
	        int i=0;
	        while(i<len)
	        {
	            if (nums[nums[i]-1]!=nums[i]) swap(nums[i],nums[nums[i]-1]);
	            else i++;
	        }
	        
	        for(int i=0;i<len;i++)
	        {
	            if (i!=nums[i]-1) rst.push_back(nums[i]);
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
swap the array to the right place. the wrong place is the duplicate ones.
****************************************************************************************************/