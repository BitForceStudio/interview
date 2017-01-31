/****************************************************************************************************
                                152. Maximum Product Subarray       
-----------------------------------------------------------------------------------------------------
Find the contiguous subarray within an array (containing at least one number) which has the largest 
product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maxProduct(vector<int>& nums) {
	        int len=nums.size();
	        if (len==0) return 0;
	        if (len==1) return nums[0];
	        
	        // neg and 0s...
	        int maxBefore=nums[0];
	        int minBefore=nums[0];
	        int minNow=nums[0];
	        int maxNow=nums[0];
	        int maxProd=nums[0];
	        
	        for(int i=1;i<len;i++)
	        {
	            maxNow=max( max(maxBefore*nums[i],minBefore*nums[i]),nums[i]);
	            minNow=min( min(minBefore*nums[i],maxBefore*nums[i]),nums[i]);
	            maxProd=max(maxNow,maxProd);
	            maxBefore=maxNow;
	            minBefore=minNow;
	        }
	        return maxProd;
	    }
	};

}

/****************************************************************************************************
                                             Note
From the solution...
It realy good idea. continue track the max and min, consider the 0 case. 
****************************************************************************************************/