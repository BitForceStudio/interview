/****************************************************************************************************
                                       139. Word Break      
-----------------------------------------------------------------------------------------------------
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine 
if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume 
the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    struct Node
	    {
	        string str;
	        int next;
	    };
	    
	    bool wordBreak(string s, vector<string>& wordDict) {
	        int lenWd = wordDict.size();
	        if (lenWd==0 || s.size()==0) return false;
	        int minLen = wordDict[0].size();
	        int maxLen = wordDict[0].size();
	        set<string> wd;
	        int strLen = s.size();
	        
	        for(int i=0;i<lenWd;i++)
	        {
	            int len = wordDict[i].size();
	            minLen = minLen>len?len:minLen;
	            maxLen = maxLen<len?len:maxLen;
	            wd.insert(wordDict[i]);
	        }
	        
	        // dp to solve it. dp[i] means before ith substring can / cannot be present by the dictiontory
	        vector<bool> dp(strLen+1,false);
	        dp[0]=true;
	        for(int i=1;i<=strLen;i++)
	        {
	            for(int j=i-1;j>=0;j--)
	            {
	                if (dp[j] && i-j<= maxLen && i-j >= minLen)
	                {
	                    string word = s.substr(j,i-j);
	                    if(wd.find(word)!=wd.end())
	                    {
	                        dp[i]=true;
	                        break;
	                    }
	                }
	            }
	        }
	        return dp[strLen];
	    }
	};

	class DFSSolution {
	public:
	    bool wordBreak(string s, vector<string>& wordDict) {
	        // dfs
	        int len=s.size();
	        unordered_set<int> lens;
	        unordered_set<string> dict;
	        for(int i=0;i<wordDict.size();i++)
	        {
	            lens.insert(wordDict[i].size());
	            dict.insert(wordDict[i]);
	        }
	        vector<bool> qc(len+1,false);
	        return dfs(dict,lens,qc,s,0);
	    }
	    
	    bool dfs(unordered_set<string> &dict, unordered_set<int> &lens, vector<bool>& qc, string& s, int begin)
	    {
	        for(auto it=lens.begin();it!=lens.end();++it)
	        {
	            if(begin+*it>s.size() || qc[begin+*it]) continue;
	            if(dict.find(s.substr(begin,*it))!=dict.end())
	            {
	                if(begin+*it==s.size()) return true;
	                qc[begin+*it]=true;
	                if(dfs(dict,lens,qc,s,begin+*it)) return true;
	            }
	        }
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
1: My BFS and DFS didn't work, why? too many trys. if index i was visited, then it not necessary to do 
that again. think about it and may optimize it.
1.1: DFS works
2: DP, it was the right way to do so...
****************************************************************************************************/