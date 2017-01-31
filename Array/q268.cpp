/****************************************************************************************************
                                  268. Missing Number                  
-----------------------------------------------------------------------------------------------------
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing 
from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant 
extra space complexity?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int missingNumber(vector<int>& nums) {
	        int len=nums.size();
	        if (len==0) return -1;
	        if (len==1) return nums[0]==0?1:0;
	        // it was not sorted
	        
	        long long sum=0;
	        for(int i=0;i<len;i++)
	        {
	            sum+=nums[i];
	        }
	        long long tmp=len*(1+len)/2;
	        return int(tmp-sum);
	        
	    }
	};

}

/****************************************************************************************************
                                             Note
It didn't say it was sorted.
****************************************************************************************************/