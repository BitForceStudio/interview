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
	        /*
	        // breadth first search. each node is sub string of remain string with length from minLen to maxLen : time limit
	        
	        queue<Node> qsf;
	        Node curr; curr.str = ""; curr.next = 0; 
	        qsf.push(curr);
	        queue<Node> qsb;
	        curr.str = ""; curr.next = strLen;
	        qsb.push(curr);
	        
	        bool qfound = false;
	        while(!qsf.empty() && !qsb.empty())
	        {
	            // check begin->end way
	            Node pre = qsf.front();
	            qsf.pop();
	            if(pre.next<=strLen-minLen)
	            {
	                int currIndex = pre.next;
	                for(int i=maxLen;i>=minLen;i--)
	                {
	                    if (currIndex+i<=strLen)
	                    {
	                        string sstr = s.substr(currIndex,i);
	                        if(find(wordDict.begin(),wordDict.end(),sstr)!=wordDict.end())
	                        {
	                            if (currIndex+i==strLen) return true;
	                            curr.str = sstr;
	                            curr.next = currIndex+i;
	                            qsf.push(curr);
	                        }
	                    }
	                }
	            }
	            // check end->begin way
	            pre = qsb.front();
	            qsb.pop();
	            if(pre.next>=minLen)
	            {
	                int currIndex = pre.next;
	                for(int i=maxLen;i>=minLen;i--)
	                {
	                    if (currIndex-i>=0)
	                    {
	                        string sstr = s.substr(currIndex-i,i);
	                        if(find(wordDict.begin(),wordDict.end(),sstr)!=wordDict.end())
	                        {
	                            if (currIndex-i==0) return true;
	                            curr.str = sstr;
	                            curr.next = currIndex-i;
	                            qsb.push(curr);
	                        }
	                    }
	                }
	            }
	        }
	        
	        return qfound;
	        */
	        
	        /*
	        // depth first search:  not working. need two way BFS
	        bool qfound=dfs(s,wordDict,0,minLen,maxLen,strLen);
	        
	        return qfound;
	        */
	    }
	    
	    /*
	    bool dfs(string s, vector<string> wd, int st, int mi, int mx, int len)
	    {
	        bool qfound = false;
	        for(int i=mx;i>=mi;i--)
	        {
	            if (st+i<=len)
	            {
	                string sstr = s.substr(st,i);
	                if(find(wd.begin(),wd.end(),sstr)!=wd.end())
	                {
	                    if (st+i==len) return true;
	                    qfound = dfs(s,wd,st+i,mi,mx,len);
	                    if (qfound) return true;
	                }
	            }
	        }
	        return qfound;
	    }
	    */
	};

}

/****************************************************************************************************
                                             Note
1: My BFS and DFS didn't work, why? too many trys. if index i was visited, then it not necessary to do 
that again. think about it and may optimize it.
2: DP, it was the right way to do so...
****************************************************************************************************/