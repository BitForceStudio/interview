/****************************************************************************************************
                  395. Longest Substring with At Least K Repeating Characters                            
-----------------------------------------------------------------------------------------------------
Find the length of the longest substring T of a given string (consists of lowercase letters only) 
such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int longestSubstring(string s, int k) {
	        int len=s.size();
	        if (len<k) return 0;
	        
	        int rst=0;
	        for(int i=0;i<=len-k;i++)
	        {
	            vector<int> counter(26,0);
	            int currmaxlast = -1;
	            int mask=0;
	            for(int j=i;j<len;j++)
	            {
	                counter[s[j]-'a']++;
	                if (counter[s[j]-'a']<k) mask|=(1<<(s[j]-'a'));
	                else mask &=(~(1<<(s[j]-'a')));
	                
	                if (mask==0)
	                {
	                    if ((j-i+1)>rst)
	                    {
	                        rst=j-i+1;
	                        currmaxlast=j;
	                    }
	                }
	            }
	            if (currmaxlast>0) i=currmaxlast+1;
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note

counting and compare chars, use mask
if max, don't go back, form the max.

The following is the recersive solution, I comeout this solution as well.

int longestSubstring(string s, int k) {
    return longestSubstring_recur(s, k, 0, s.size());
}

int longestSubstring_recur(const string& s, int k, int first, int last) {
    int count[26] = {0};
    for (int j = first; j < last; ++j) ++count[s[j] - 'a'];
    
    int max_len = 0;
    for (int j = first; j < last;) {
        while (j < last && count[s[j]-'a']<k) ++j;
        if (j == last) break;
        int l = j;
        while (l < last && count[s[l]-'a']>=k) ++l;
        //all chars appear more than k times
        if (j == first && l == last) return last-first; 
        max_len = max(max_len, longestSubstring_recur(s, k, j, l));
        j = l;
    }
    return max_len;
}
****************************************************************************************************/