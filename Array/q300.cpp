/****************************************************************************************************
                            300. Longest Increasing Subsequence        
-----------------------------------------------------------------------------------------------------
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may 
be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int lengthOfLIS(vector<int>& nums) {
	        int len=nums.size();
	        if (len<=1) return len;
	        int max=1;
	        vector<int> tmp(len,1);
	        for(int i=1;i<len;i++)
	        {
	            for(int j=0;j<i;j++)
	            {
	                if (nums[j]<nums[i])
	                {
	                    if(tmp[j]+1>tmp[i]) tmp[i]=tmp[j]+1;
	                }
	            }
	            if (max<tmp[i]) max=tmp[i];
	        }
	        return max;
	    }
	};

}

/****************************************************************************************************
                                             Note
DP problem, need to learn and understand...
****************************************************************************************************/