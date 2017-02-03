/****************************************************************************************************
                                     229. Majority Element II        
-----------------------------------------------------------------------------------------------------
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The 
algorithm should run in linear time and in O(1) space.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class SortSolution {
	public:
	    vector<int> majorityElement(vector<int>& nums) {
	        int len=nums.size();
	        vector<int> rst;
	        if (len==0) return rst;
	        if (len==1) return nums;
	        int lent = len/3;
	        
	        sort(nums.begin(),nums.end());
	        int curr=1;
	        int ic=0;
	        for(int i=1;i<=len;i++)
	        {
	            if (i<len && nums[i]==nums[ic]) curr++;
	            else 
	            {
	                if (curr>lent) rst.push_back(nums[ic]);
	                ic=i;
	                curr=1;
	            }
	        }
	        return rst;
	    }
	};

	class VoteSolution {
	public:
	    vector<int> majorityElement(vector<int>& nums) {
	        int len=nums.size();
	        vector<int> rst;
	        if (len==0) return rst;
	        if (len==1) return nums;
	        int lent = len/3;
	        int n1=0,n2=0,t1,t2;
	        for(int i=0;i<len;i++)
	        {
	            if (n1!=0 && t1==nums[i])   {n1++; continue;}
	            if (n2!=0 && t2==nums[i])   {n2++; continue;}
	            
	            if (n1==0) {t1=nums[i];n1++;continue;}
	            if (n2==0) {t2=nums[i];n2++;continue;}
	            n1--;
	            n2--;
	        }
	        n1=0;n2=0;
	        for(int i=0;i<len;i++)
	        {
	            if(nums[i]==t1) n1++;
	            if(nums[i]==t2) n2++;
	        }
	        if (n1>lent) rst.push_back(t1);
	        if (n2>lent && t2!=t1) rst.push_back(t2);
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Sort then count.

vote
****************************************************************************************************/