/****************************************************************************************************
                                  164. Maximum Gap           
-----------------------------------------------------------------------------------------------------
Given an unsorted array, find the maximum difference between the successive elements in its sorted 
form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed 
integer range.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maximumGap(vector<int>& nums) {
	        int len=nums.size();
	        if (len<2) return 0;
	        
	        sort(nums.begin(),nums.end());
	        int rst=0;
	        for(int i=1;i<len;i++)
	        {
	            if(nums[i]-nums[i-1] > rst) rst=nums[i]-nums[i-1];
	        }
	        
	        return rst;
	    }
	};

	class Solution2 {
	public:
	    int maximumGap(vector<int>& nums) {
	        int len = nums.size();
	        if(len<2) return 0;
	        
	        int nmax=0,nmin=INT_MAX;
	        for(int i=0;i<len;i++)
	        {
	            nmax = max(nmax,nums[i]);
	        }
	        
	        int nb = len;
	        int div = (nmax+1)/nb + 1;
	        vector<set<int> > b(nb);
	        for(int i=0;i<len;i++)
	        {
	            b[nums[i]/div].insert(nums[i]);
	        }
	        int rst = 0;
	        int pre = -1;
	        for(int i=0;i<nb;i++)
	        {
	            if(b[i].size()>0)
	            {
	                for(set<int>::iterator it=b[i].begin();it!=b[i].end();++it)
	                {
	                    if(pre<0) pre = (*it);
	                    else
	                    {
	                        rst=max(rst,(*it)-pre);
	                        pre=(*it);
	                    }
	                }
	            }
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
The O(n) answer is buscket sort. I don't know how to do this...

Solution 2, buscket sort. 
****************************************************************************************************/