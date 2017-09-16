/****************************************************************************************************
                                     91. Decode Ways        
-----------------------------------------------------------------------------------------------------
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int numDecodings(string s) {
	        int len=s.size();
	        if (len<1) return len;
	        if (s[0]=='0') return 0;   // no possible to decode
	        if (len==1) return len;
	        
	        vector<int> rst(len+1,0);
	        rst[0]=1;
	        rst[1]=1;
	        for(int i=2;i<=len;i++)
	        {
	            int curr = stoi(s.substr(i-2,2));
	            rst[i]= ((s[i-1]=='0')?0:rst[i-1]) + ((curr>26 || s[i-2]=='0')?0:rst[i-2]);
	            
	        }
	        return rst[len];
	    }
	};

	class Solution {
	public:
	    int numDecodings(string s) {
	        int len=s.size();
	        if (len<=0) return len;
	        if (s[0]=='0') return 0;
	        
	        vector<int> count(len+1,0);
	        count[0]=1;
	        count[1]=1;
	        for(int i=1;i<len;i++)
	        {
	            if (s[i]!='0')
	            {
	                count[i+1]=count[i];
	                if ((s[i]-'0'+(s[i-1]-'0')*10)<=26 && s[i-1]!='0')
	                    count[i+1]+=count[i-1];
	            }
	            else if (s[i]=='0' && (s[i-1]=='2' || s[i-1]=='1'))
	            {
	                count[i+1]=count[i-1];
	                count[i]  =count[i-1];
	            }
	            else if (s[i]=='0' && (s[i-1]=='0' || s[i-1]>='3')) return 0;
	        }
	        return count[len];
	    }
	};
}

/****************************************************************************************************
                                             Note
need to consider case when s[i]=='0'
****************************************************************************************************/