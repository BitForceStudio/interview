/****************************************************************************************************
                               334. Increasing Triplet Subsequence                 
-----------------------------------------------------------------------------------------------------
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool increasingTriplet(vector<int>& nums) {
	        int len = nums.size();
	        if (len<3) return false;
	        stack<int> arr;
	        
	        int a1=INT_MAX,a2=INT_MAX;
	        
	        for(int i=1;i<len;i++)
	        {
	            if (nums[i]<=a1)
	            {
	                a1=nums[i];
	            }
	            else if (nums[i]<=a2)
	            {
	                a2=nums[i];
	            }
	            else
	            {
	                return true;
	            }
	        }
	        
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
set the level, and then check it. see the code, it is obvious.
****************************************************************************************************/