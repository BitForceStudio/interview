/****************************************************************************************************
                               215. Kth Largest Element in an Array         
-----------------------------------------------------------------------------------------------------
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the 
sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int findKthLargest(vector<int>& nums, int k) {
	        int len=nums.size();
	        if (len==0) return 0;
	        
	        return quickselect(nums,0,len-1,len-k);
	    }

	    int quickselect(vector<int>& nums,int s, int t, int k)
	    {
	        if (s>t) return -1;
	        int pv = nums[t];
	        int si = s;
	        for(int i=s;i<t;i++)
	        {
	            if (nums[i]<=pv)
	            {
	                swap(nums,i,si);
	                si++;
	            }
	        }
	        swap(nums,t,si);
	        if (si==k) return nums[si];
	        else if (si<k) return quickselect(nums,si+1,t,k);
	        else return quickselect(nums,s,si-1,k);
	    }
	    
	    void swap(vector<int>&nums, int i, int j)
	    {
	        int t=nums[i];
	        nums[i]=nums[j];
	        nums[j]=t;
	    }
	};

}

/****************************************************************************************************
                                             Note
It is quick select. 
** need to remember the quick sort kind of problem.
****************************************************************************************************/