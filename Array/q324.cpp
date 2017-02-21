/****************************************************************************************************
                                       324. Wiggle Sort II      
-----------------------------------------------------------------------------------------------------
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    void wiggleSort(vector<int>& nums) {
	        int len=nums.size();
	        if (len<2) return;
	        
	        vector<int> tmp=nums;
	        sort(tmp.begin(),tmp.end());
	        
	        for(int i=0;i<(len+1)/2;i++)        // **
	        {
	            nums[i*2]=tmp[(len+1)/2-i-1];   // ***
	        }

	        for(int i=1;i<=(len+1)/2;i++)       // ****
	        {
	            nums[i*2-1]=tmp[len-i];         // *****
	        }
	        return;
	    }
	};

}

/****************************************************************************************************
                                             Note
** Here is the catches...
I don't know how to do the follow ups now...
****************************************************************************************************/