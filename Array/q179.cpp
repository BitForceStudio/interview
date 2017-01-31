/****************************************************************************************************
                                  179. Largest Number           
-----------------------------------------------------------------------------------------------------
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string largestNumber(vector<int>& nums) {
	        string rst;
	        int len=nums.size();
	        if (len==0) return rst;
	        if (len==1) return to_string(nums[0]);
	        
	        vector<string> strnums(len);
	        for(int i=0;i<len;i++)
	            strnums[i]=to_string(nums[i]);
	        
	        sort(strnums.begin(),strnums.end(),max);
	        if (strnums[0]=="0") return "0";
	        
	        for(int i=0;i<len;i++)
	        {
	            rst+=strnums[i];
	        }
	        
	        return rst;
	    }
	    
	private:
	    static bool max(string a, string b)
	    {
	        return a+b>b+a;  // ** 
	    }
	};

}

/****************************************************************************************************
                                             Note
** this is the key. need to think about this way...
****************************************************************************************************/