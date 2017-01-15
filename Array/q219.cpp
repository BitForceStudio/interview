/****************************************************************************************************
                                     219. Contains Duplicate II        
-----------------------------------------------------------------------------------------------------
Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{
	// map
	class Solution {
	public:
	    bool containsNearbyDuplicate(vector<int>& nums, int k) {
	        int len=nums.size();
	        if (len<2 || k==0) return false;
	        map<int,bool> qadd;
	        map<int,bool>::iterator it;
	        for (int i=0;i<len;i++)
	        {
	            if(i>k)
	            {
	                it=qadd.find(nums[i-k-1]);
	                qadd.erase(it);
	            }
	            if(qadd[nums[i]]) return true;
	            qadd[nums[i]]=true;
	        }
	        return false;
	    }
	};

	// set
	class Solution {
	public:
	    bool containsNearbyDuplicate(vector<int>& nums, int k) {
	        int len=nums.size();
	        if (len<2 || k==0) return false;
	        set<int> qadd;
	        for (int i=0;i<len;i++)
	        {
	            if(i>k) qadd.erase(nums[i-k-1]);
	            if(!qadd.insert(nums[i]).second) return true;
	        }
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
another map solution is to store the index as value. 
****************************************************************************************************/