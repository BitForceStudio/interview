/****************************************************************************************************
                                   327. Count of Range Sum         
-----------------------------------------------------------------------------------------------------
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int countRangeSum(vector<int>& nums, int lower, int upper) {
	        int len=nums.size();
	        if (len<1) return 0;
	        vector<long> sum(len+1,0);
	        
	        for(int i=1;i<len+1;i++)
	        {
	            sum[i]=sum[i-1]+nums[i-1];
	        }

	        int rst=mergesort(sum,0,len+1,lower,upper);
	        
	        return rst;
	    }
	    
	    int mergesort(vector<long>& sum, int s, int t, int lower, int upper)
	    {
	        if ((t-s)<=1) return 0;
	        
	        int mid = (s+t)/2;
	        int rst = mergesort(sum,s,mid,lower,upper)+
	                  mergesort(sum,mid,t,lower,upper);
	        
	        int j=mid,k=mid,r=mid;
	        vector<long> tmp((t-s),0);
	        // count & merge
	        for(int i=s,m=0;i<mid;i++,m++)
	        {
	            while(j<t && (sum[j]-sum[i])<lower) j++;
	            while(k<t && (sum[k]-sum[i])<=upper) k++;
	            while(r<t && sum[r]<sum[i]) tmp[m++]=sum[r++];
	            rst+=(k-j);
	            tmp[m]=sum[i];
	        }

	        for(int i=0;i<r-s;i++)
	        {
	            sum[s+i]=tmp[i];
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
I have the basic idea, but need to remember merge sort. 
****************************************************************************************************/