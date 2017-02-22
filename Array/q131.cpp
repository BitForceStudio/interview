/****************************************************************************************************
                                 131. Palindrome Partitioning            
-----------------------------------------------------------------------------------------------------
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<vector<string>> partition(string s) {
	        vector<vector<string> > rst;
	        if (s.size()==0) return rst;
	        
	        vector<string> path;
	        dfs(0,s,path,rst);
	        
	        return rst;
	    }
	    
	    void dfs(int st, string s, vector<string>& path, vector<vector<string> >& rst)
	    {
	        if (st==s.size())
	        {
	            rst.push_back(path);
	            return;
	        }
	        
	        for(int i=st;i<s.size();i++)
	        {
	            if (isPalindrome(st,i,s))
	            {
	                path.push_back(s.substr(st,i-st+1));
	                dfs(i+1,s,path,rst);
	                path.pop_back();
	            }
	        }
	    }
	    
	    bool isPalindrome(int st, int ed, string s)
	    {
	        while(st<=ed)
	        {
	            if (s[st++]!=s[ed--]) return false;
	        }
	        return true;
	    }
	};

}

/****************************************************************************************************
                                             Note
Simple dfs. need to remember it...
****************************************************************************************************/