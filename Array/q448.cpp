/****************************************************************************************************
                                 448. Find All Numbers Disappeared in an Array            
-----------------------------------------------------------------------------------------------------
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and 
others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not 
count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> findDisappearedNumbers(vector<int>& nums) {
	        vector<int> rst;
	        int len=nums.size();
	        if (len==0) return rst;
	        
	        for(int i=0;i<len;i++)
	        {
	            nums[(nums[i]-1)%len]+=len; // pointed place, added length. if not pointed, then it stay less than len. 
	        }
	        
	        for(int i=0;i<len;i++)
	        {
	            if (nums[i]<=len) rst.push_back(i+1);
	        }
	        return rst;
	    }
	};

	class Solution2 {
	public:
	    vector<int> findDisappearedNumbers(vector<int>& nums) {
	        int len=nums.size();
	        vector<int> rst;
	        if (len==0) return rst;
	        int i=0;
	        while(i<len)
	        {
	            if(nums[nums[i]-1]!=nums[i])
	            {
	                swap(nums[nums[i]-1],nums[i]);
	            }
	            else i++;
	        }
	        for(i=0;i<len;i++)
	        {
	            if(nums[i]!=i+1) rst.push_back(i+1);
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
clever...


****************************************************************************************************/