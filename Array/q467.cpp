/****************************************************************************************************
                               467. Unique Substrings in Wraparound String        
-----------------------------------------------------------------------------------------------------
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will 
look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are 
present in s. In particular, your input is the string p and you need to output the number of different 
non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int findSubstringInWraproundString(string p) {
	        int len=p.size();
	        if (len<=1) return len;
	        
	        // save the max length of conitunes ending on letter 
	        vector<int> count(26,0);
	        int curr=1;
	        for(int i=0;i<len;i++)
	        {
	            if (count[p[i]-97]<curr) count[p[i]-97]=curr;
	            while(i<len-1 && (p[i+1]-p[i]==1 || (p[i]=='z' && p[i+1]=='a')))
	            {
	                i++;
	                curr++;
	                if (count[p[i]-97]<curr) count[p[i]-97]=curr;
	            }
	            curr=1;
	        }
	        
	        int rst=0;
	        for(int i=0;i<26;i++)
	        {
	            rst+=count[i];
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
count on ending letter.
****************************************************************************************************/