/****************************************************************************************************
                                   567. Permutation in String              
-----------------------------------------------------------------------------------------------------
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In 
other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
Note:
The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool checkInclusion(string s1, string s2) {
	        int len=s1.size();
	        if (len>s2.size()) return false;
	        
	        vector<int> count(26,0);
	        for(int i=0;i<len;i++) count[s1[i]-97]++;
	        
	        for(int i=0;i<s2.size();i++)
	        {
	            if (count[s2[i]-97]>0)
	            {
	                int clen=0;
	                vector<int> currc(26,0); //***
	                int start = i;
	                while(i<s2.size() && count[s2[i]-97]>0)
	                {
	                    currc[s2[i]-97]++;
	                    clen++;
	                    
	                    if (currc[s2[i]-97]>count[s2[i]-97])
	                    {
	                        while(currc[s2[i]-97]>count[s2[i]-97])
	                        {
	                            currc[s2[start]-97]--;
	                            clen--;
	                            start++;
	                        }
	                    }
	                    else if (clen==len)             return true;
	                    else if ((s2.size()-start)<len) return false;
	                    i++;
	                }
	            }
	        }
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
1: KMP princple
2: no need to store the index, keep the start and check the above counter would be good
3: check size. 
4: vector resize problem? ***
****************************************************************************************************/