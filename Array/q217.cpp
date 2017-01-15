/****************************************************************************************************
                                   217. Contains Duplicate          
-----------------------------------------------------------------------------------------------------
Given an array of integers, find if the array contains any duplicates. Your function should return 
true if any value appears at least twice in the array, and it should return false if every element 
is distinct.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool containsDuplicate(vector<int>& nums) {
	        int len=nums.size();
	        if (len<2) return false;
	        // hash table
	        map<int,bool> qcontain;
	        for(int i=0;i<len;i++)
	        {
	            if(qcontain[nums[i]]) return true;
	            qcontain[nums[i]]=true;
	        }
	        // sort
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
two solutions, one is hash table, O(n) & O(n)
another is sort O(nlgn) & O(1)
****************************************************************************************************/