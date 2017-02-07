/****************************************************************************************************
                                349. Intersection of Two Arrays             
-----------------------------------------------------------------------------------------------------
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	        int len1 = nums1.size();
	        int len2 = nums2.size();
	        vector<int> rst;
	        
	        if (len1==0 || len2==0) return rst;
	        
	        map<int,int> maps;
	        for(int i=0;i<len1;i++) maps[nums1[i]]=1;
	        for(int i=0;i<len2;i++)
	        {
	            if (maps[nums2[i]]>0)
	            {
	                rst.push_back(nums2[i]);
	                maps[nums2[i]]=0;
	            }
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
hash table
****************************************************************************************************/