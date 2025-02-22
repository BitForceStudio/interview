/****************************************************************************************************
                                      140. Word Break II           
-----------------------------------------------------------------------------------------------------
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces 
in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary 
does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> wordBreak(string s, vector<string>& wordDict) {
	        // backtracking problem
	        vector<string> rst;
	        map<int,set<string> > dict;

	        for(int i=0;i<wordDict.size();i++)
	        {
	            dict[wordDict[i].size()].insert(wordDict[i]);
	        }

	        vector<string> curr;
	        map<int,vector<string> > subsols;  // ***
	        rst = helper(0,s,dict,subsols);
	        return rst;
	    }
	    
	    vector<string> helper(int bg, string s, map<int,set<string> >& dict, map<int,vector<string> >& subsols)
	    {
	        if (subsols.find(bg)!=subsols.end()) return subsols[bg]; // ***
	        
	        vector<string> rst;
	        if (bg>=s.size()) 
	        {
	            rst.push_back("");  // ****
	            return rst;
	        }

	        map<int,set<string> >::iterator it=dict.begin();
	        for(;it!=dict.end();it++)
	        {
	            string tmp=s.substr(bg,it->first);
	            if (it->second.find(tmp)!=it->second.end())
	            {
	                vector<string> sub = helper(bg+it->first,s,dict,subsols);
	                if (sub.size()>0) 
	                {
	                    for(int i=0;i<sub.size();i++)
	                    {
	                        string rtmp=tmp+(sub[i]==""?"":(" "+sub[i]));
	                        rst.push_back(rtmp);
	                    }
	                }
	            }
	        }
	        subsols[bg]=rst;
	        return rst;
	    }
	};


	class Solution2 {
	public:
	    vector<string> wordBreak(string s, vector<string>& wordDict) {
	        unordered_set<string> dict;
	        set<int> length;
	        for(int i=0;i<wordDict.size();i++) 
	        {
	            length.insert(wordDict[i].size());
	            dict.insert(wordDict[i]);
	        }
	        
	        vector<string> rst;
	        map<int,vector<string> > m;
	        rst = helper(dict,length, m,s,s.size());
	        
	        return rst;
	    }
	    
	    vector<string> helper(unordered_set<string>& dict, set<int>& len, map<int,vector<string> >& m, string s, int index)
	    {
	        if(m.find(index)!=m.end()) return m[index];
	        vector<string> rst;
	        if(index<=0)
	        {
	            return rst;
	        }
	        
	        for(set<int>::iterator it=len.begin();it!=len.end();++it)
	        {
	            if(index-*it < 0) break;
	            string str = s.substr(index-*it);
	            if(dict.find(str)!=dict.end())
	            {
	                if (index-*it==0) rst.push_back(str);
	                else
	                {
	                    vector<string> rtmp = helper(dict,len,m,s.substr(0,index-*it),index-*it);

	                    if(rtmp.size()>0)
	                    {
	                        for(int i=0;i<rtmp.size();i++)
	                        {   
	                            string curr=rtmp[i]+" "+str;
	                            rst.push_back(curr);
	                        }
	                    }
	                }
	            }
	            m[index] = rst;
	        } 
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
***: use a map to store the current begin index all possibilities, it will reduce the duplication
****: if rst=="", then it means it hit the end. if empty, then it means no solution on current 
      partition.
****************************************************************************************************/