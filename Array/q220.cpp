/****************************************************************************************************
                                   220. Contains Duplicate III     
-----------------------------------------------------------------------------------------------------
Given an array of integers, find out whether there are two distinct indices i and j in the array such 
that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference 
between i and j is at most k.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	    	auto nLen = nums.size();        
			if (!k || t<0 || nLen<2)
	    		return false;
	    		
	    	for (int i = 0; i < nLen;++i)
	    	{
	    		for(int j=i+1;j<=i+k && j<nLen;j++)
	    		{
	    		    long long rst=0;
	    		    if (t==0)
	    		        rst=nums[j]==nums[i]?0:2;
	    		    else
	    		    {
	    		        // corner case: nums[i]>=MAX-2 and nums[j]<=-(MAX-2)
	    		        //              nums[i]<=-(MAX-2) and nums[j]>=MAX-2
	    		        if ((nums[i]>=2147483645 && nums[j]<=-2147483645) || (nums[i]<=-2147483645 && nums[j]>=2147483645))
	    		            continue;
	    		        rst=nums[i]-nums[j];
	    		    }
	    		        
	    		    if (abs(rst)<=t) return true;
	    		}
	    	}
	    	return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
it is not good. However, it could be a O(n) solution. use a contianer and save the smallest. 
****************************************************************************************************/