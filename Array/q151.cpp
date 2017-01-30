/****************************************************************************************************
                                 151. Reverse Words in a String            
-----------------------------------------------------------------------------------------------------
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    void reverseWords(string &s) {
	        int len=s.size();
	        if (len<1) return;
	        if (len==1 && s[0]!=' ') return;

	        int t=0;
	        int st=0;
	        int start=0;
	        int wc = 0;
	        while(1)
	        {
	            // skip " "
	            while(start<len && s[start]==' ') start++;
	            if (start==len) break;
	            
	            if (wc>0) s[t++]=' ';
	            st=t;
	            while(start<len && s[start]!=' ') {s[t]=s[start]; t++; start++; }
	            
	            revert(s,st,t-1);
	            wc++;
	        }
	        
	        s.resize(t);
	        revert(s,0,t-1);
	    }
	    
	    void revert(string& str, int s, int t)
	    {
	        while(s<t)
	        {
	            char tmp=str[s];
	            str[s]=str[t];
	            str[t]=tmp;
	            s++;
	            t--;
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
Need to ask the interviewer about the space. how to deal with it. 
****************************************************************************************************/