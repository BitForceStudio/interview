/****************************************************************************************************
                                 167. Two Sum II - Input array is sorted            
-----------------------------------------------------------------------------------------------------
Given an array of integers that is already sorted in ascending order, find two numbers such that they 
add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> twoSum(vector<int>& numbers, int target) {
	        int len = numbers.size();
	        vector<int> rst;
	        if (len<2) return rst;
	        int left=0;
	        int right = len-1;
	        while(left<right)
	        {
	            if(numbers[left]+numbers[right]<target)
	            {
	                left++;
	            }
	            else if (numbers[left]+numbers[right]>target)
	            {
	                right--;
	            }
	            else
	            {
	                rst.resize(2,left+1);
	                rst[1]=right+1;
	                break;
	            }
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
1 based...
****************************************************************************************************/