/****************************************************************************************************
                               128. Longest Consecutive Sequence              
-----------------------------------------------------------------------------------------------------
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int longestConsecutive(vector<int>& nums) {
	        int len=nums.size();
	        if (len<=1) return len;
	        
	        set<int> setNums;
	        for(int e : nums) setNums.insert(e);
	        
	        int max=0;
	        for(int curr:setNums)
	        {
	            if(setNums.find(curr-1)==setNums.end())
	            {
	                int next=curr+1;
	                int currmax=1;
	                while(setNums.find(next)!=setNums.end())
	                {
	                    setNums.erase(next);
	                    currmax++;
	                    next++;
	                }
	                max=max<currmax?currmax:max;
	            }
	        }
	        return max;
	    }
	};

	class Solution2 {
	public:
	    int longestConsecutive(vector<int>& nums) {
	        int len = nums.size();
	        if(len<=1) return len;
	        
	        unordered_set<int> s;
	        for(int i=0;i<len;i++) s.insert(nums[i]);
	        int rst = 1;
	        while(!s.empty())
	        {
	            int tmp = 1;
	            unordered_set<int>::iterator it = s.begin();
	            // backward
	            int i=1;
	            while(s.find((*it)-i)!=s.end())
	            {
	                tmp++;
	                s.erase((*it)-i);
	                i++;
	            }
	            // forward
	            i=1;
	            while(s.find((*it)+i)!=s.end())
	            {
	                tmp++;
	                s.erase((*it)+i);
	                i++;
	            }
	            s.erase((*it));
	            rst=max(rst,tmp);
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Get the idea from the solution. but this one is very good.
Remeber, if one item is erased from the the set/map and use iterator for e:set, it will not be 
visited. 
****************************************************************************************************/