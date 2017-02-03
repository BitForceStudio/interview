/****************************************************************************************************
                                      228. Summary Ranges       
-----------------------------------------------------------------------------------------------------
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> summaryRanges(vector<int>& nums) {
	        int len=nums.size();
	        vector<string> rst;
	        if (len==0) return rst;
	        int s=nums[0],t=nums[0];
	        string curr="";
	        for(int i=1;i<len;i++)
	        {
	            if (nums[i]-t==1) t=nums[i];
	            else
	            {
	                if (s==t) curr=to_string(s);
	                else curr=to_string(s)+"->"+to_string(t);
	                rst.push_back(curr);
	                s=nums[i];
	                t=s;
	            }
	        }
	        if (s==t) curr=to_string(s);
	        else curr=to_string(s)+"->"+to_string(t);
	        rst.push_back(curr);
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Nothing special
****************************************************************************************************/