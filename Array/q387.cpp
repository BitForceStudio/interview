/****************************************************************************************************
                            387. First Unique Character in a String          
-----------------------------------------------------------------------------------------------------
Given a string, find the first non-repeating character in it and return it's index. If it doesn't 
exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int firstUniqChar(string s) {
	        int len=s.size();
	        if (len==0) return -1;
	        vector<int> count(26,-1);
	        for(int i=0;i<len;i++)
	        {
	            count[s[i]-'a']=count[s[i]-'a']>=0?len:i;
	        }
	        int rst=len;
	        for(int i=0;i<26;i++)
	        {
	            if(count[i]<len && count[i]>=0)
	            {
	                rst=rst<count[i]?rst:count[i];
	            }
	        }
	        return rst==len?-1:rst;  // ***
	    }
	};

}

/****************************************************************************************************
                                             Note
be careful...
*** if no unique, return -1
****************************************************************************************************/