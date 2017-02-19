/****************************************************************************************************
                                 414. Third Maximum Number        
-----------------------------------------------------------------------------------------------------
Given a non-empty array of integers, return the third maximum number in this array. If it does not 
exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int thirdMax(vector<int>& nums) {
	        int len=nums.size();
	        if (len==1) return nums[0];
	        vector<int> maxs(3,2147482147);
	        for(int i=0;i<len;i++)
	        {
	            if (nums[i]==maxs[0] || nums[i]==maxs[1] || nums[i]==maxs[2]) continue;
	            if (maxs[0]==2147482147 || nums[i]>maxs[0])
	            {
	                maxs[2]=maxs[1];
	                maxs[1]=maxs[0];
	                maxs[0]=nums[i];
	            }
	            else if (maxs[1]==2147482147 || nums[i]>maxs[1])
	            {
	                maxs[2]=maxs[1];
	                maxs[1]=nums[i];
	            }
	            else if (maxs[2]==2147482147 || nums[i]>maxs[2])
	                maxs[2]=nums[i];
	        }
	        return maxs[2]==2147482147?maxs[0]:maxs[2];
	    }
	};

}

/****************************************************************************************************
                                             Note
good idea...
****************************************************************************************************/