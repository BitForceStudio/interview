/****************************************************************************************************
                              522. Longest Uncommon Subsequence II              
-----------------------------------------------------------------------------------------------------
Given a list of strings, you need to find the longest uncommon subsequence among them. The longest 
uncommon subsequence is defined as the longest subsequence of one of these strings and this 
subsequence should not be any subsequence of the other strings.

A subsequence is a sequence that can be derived from one sequence by deleting some characters without 
changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an 
empty string is a subsequence of any string.

The input will be a list of strings, and the output needs to be the length of the longest uncommon 
subsequence. If the longest uncommon subsequence doesn't exist, return -1.

Example 1:
Input: "aba", "cdc", "eae"
Output: 3
Note:

All the given strings' lengths will not exceed 10.
The length of the given list will be in the range of [2, 50].
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int findLUSlength(vector<string>& strs) {
	        int rst=-1;
	        int len=strs.size();
	        for(int i=0;i<len;i++)
	        {
	            int curr = strs[i].size();
	            bool qcommon=false;
	            for(int j=0;j<len;j++)
	            {
	                if (i!=j && isCommon(strs[i],strs[j]))
	                {
	                    qcommon=true;
	                    break;
	                }
	            }
	            if (!qcommon)
	            {
	                rst=rst>curr?rst:curr;
	            }
	        }
	        return rst;
	    }
	    
	    bool isCommon(string str, string base)
	    {
	        // return is str has common substring in base
	        int len1=str.size();
	        int len2=base.size();
	        int remain_str=len1;
	        int remain_base=len2;
	        for(;remain_str>0 && remain_base>0;)
	        {
	            int i=len1-remain_str;
	            int j=len2-remain_base;
	            if (str[i]==base[j])
	            {
	                remain_str--;
	                remain_base--;
	            }
	            else
	            {
	                remain_base--;
	            }
	        }
	        return remain_str==0;
	    }
	};

}

/****************************************************************************************************
                                             Note
if candidate in a word, then this word is the solution. So, just find the word that not others' common
subsequence.
 
****************************************************************************************************/