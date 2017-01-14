/****************************************************************************************************
                                    189. Rotate Array         
-----------------------------------------------------------------------------------------------------
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    void rotate(vector<int>& nums, int k) {
	        // rotate first n-k element, rotate last k element and then rotate the whole string
	        int len=nums.size();
	        if (len==0 || k==0) return;
	        k=k%len;
	        if (k==0) return;
	        
	        rt(nums,0,len-k-1);
	        rt(nums,len-k,len-1);
	        rt(nums,0,len-1);
	    }
	    
	    void rt(vector<int>& nums, int s, int e)
	    {
	        while(s<e)
	        {
	            int tmp=nums[s];
	            nums[s]=nums[e];
	            nums[e]=tmp;
	            s++;
	            e--;
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
nothing special remember this kind of question. rotate two times. 

****************************************************************************************************/