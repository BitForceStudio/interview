/****************************************************************************************************
                                       645. Set Mismatch    
-----------------------------------------------------------------------------------------------------
The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of 
the numbers in the set got duplicated to another number in the set, which results in repetition of 
one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly 
find the number occurs twice and then find the number that is missing. Return them in the form of an 
array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> findErrorNums(vector<int>& nums) {
	        int len=nums.size();
	        vector<int> rst(2,0);
	        if (len<=1) return rst;
	        
	        for(int i=0;i<len;i++)
	        {
	            int curr = abs(nums[i]);
	            rst[1]^=curr^(i+1);
	            if (nums[curr-1]<0) rst[0] = curr;
	            else nums[curr-1]=-nums[curr-1];
	        }
	        rst[1]^=rst[0];
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
The idea is based on:
(1 ^ 2 ^ 3 ^ .. ^ n) ^ (1 ^ 2 ^ 3 ^ .. ^ n) = 0
Suppose we change 'a' to 'b', then all but 'a' and 'b' are XORed exactly 2 times. The result is then
0 ^ a ^ b ^ b ^ b = a ^ b
Let c = a ^ b, if we can find 'b' which appears 2 times in the original array, 'a' can be easily 
calculated by a = c ^ b.
****************************************************************************************************/