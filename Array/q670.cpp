/****************************************************************************************************
                                    670. Maximum Swap         
-----------------------------------------------------------------------------------------------------
Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maximumSwap(int num) {
	        if (num<10) return num;
	        vector<int> nums;
	        while(num>0)
	        {
	            int curr = num%10;
	            nums.push_back(curr);
	            num/=10;
	        }
	        vector<int> tmp=nums;
	        sort(nums.begin(),nums.end());
	        int i=nums.size()-1;
	        for(;i>=0;i--)
	        {
	            if (nums[i]!=tmp[i])
	            {
	                // find first nums[i] in tmp
	                for(int j=0;j<tmp.size();j++)
	                {
	                    if (tmp[j]==nums[i])
	                    {
	                        int t = tmp[i];
	                        tmp[i] = nums[i];
	                        tmp[j] = t;
	                        break;
	                    }
	                }
	                break;
	            }
	        }
	        
	        int curr = 1;
	        for(i=0;i<tmp.size();i++)
	        {
	            num+=curr*tmp[i];
	            curr*=10;
	        }
	        return num;
	    }
	};

}

/****************************************************************************************************
                                             Note
Not difficult. 
****************************************************************************************************/