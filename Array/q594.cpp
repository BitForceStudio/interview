/****************************************************************************************************
                             594. Longest Harmonious Subsequence                
-----------------------------------------------------------------------------------------------------
We define a harmonious array is an array where the difference between its maximum value and its 
minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious subsequence among 
all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
Note: The length of the input array will not exceed 20,000.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int findLHS(vector<int>& nums) {
	        int len=nums.size();
	        if (len<=1) return 0;
	        
	        map<int,int> counter;
	        for(int i=0;i<len;i++)
	        {
	            counter[nums[i]]++;
	        }
	        
	        map<int,int>::iterator it=counter.begin(); it;
	        map<int,int>::iterator itm = it; it++;
	        int rst=0;
	        for(;it!=counter.end();it++)
	        {
	            if(it->first-itm->first==1)
	            {
	                int sum = it->second + itm->second;
	                if (sum>rst) rst=sum;
	            }
	            itm=it;
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note

****************************************************************************************************/