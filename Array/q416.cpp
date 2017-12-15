/****************************************************************************************************
                                    416. Partition Equal Subset Sum         
-----------------------------------------------------------------------------------------------------
Given a non-empty array containing only positive integers, find if the array can be partitioned into 
two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool canPartition(vector<int>& nums) {
	        int len=nums.size();
	        if(len==1) return false;
	        if(len==2) return nums[1]==nums[0];
	        
	        int rst=INT_MAX;
	        int sum=0;
	        for(int i=0;i<len;i++) sum+=nums[i];
	        sort(nums.begin(),nums.end());
	        vector< bool > dp(sum+1,false);
	        dp[0]=true;
	        for(int i=0;i<len;i++)
	        {
	            for(int j=sum;j>=nums[i];j--)
	            {
	                dp[j] = dp[j] || dp[j-nums[i]];
	                if(dp[j])
	                {
	                    rst=min(rst,abs(2*j-sum));
	                }
	            }
	        }
	        return rst==0;
	    }
	};

}

/****************************************************************************************************
                                             Note
back pack problem

For this problem, mem can be optimized. The j need to count down from sum to the nums[i]
****************************************************************************************************/