/****************************************************************************************************
                                       49. Group Anagrams      
-----------------------------------------------------------------------------------------------------
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string,int> dict;
            vector<vector<string> > rst;
            int len = strs.size();
            if (len==0) return rst;
            if (len==1) {rst.push_back(strs); return rst;}
            for(int i=0;i<len;i++)
            {
                string curr = strs[i];
                sort(curr.begin(),curr.end());
                if(dict.find(curr)!=dict.end())
                {
                    rst[dict[curr]].push_back(strs[i]);
                }
                else
                {
                    // new
                    int sz = rst.size();
                    dict[curr]=sz;
                    rst.resize(sz+1);
                    rst[sz].push_back(strs[i]);
                }
            }
            
            return rst;
        }
    };

    class Solution2 {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string> > rst;
            int len =strs.size();
            if(len==0) return rst;
            unordered_map<string,vector<string> > store;
            
            for(int i=0;i<len;i++)
            {
                vector<int> counter(26,0);
                for(int j=0;j<strs[i].size();j++)
                {
                    counter[strs[i][j]-'a']++;
                }
                string tmp;
                for(int j=0;j<26;j++)
                {
                    for(int k=0;k<counter[j];k++)
                    {
                        tmp.push_back('a'+j);
                    }
                }
                store[tmp].push_back(strs[i]);
            }
            
            rst.resize(store.size());
            int nl=0;
            for(unordered_map<string,vector<string> >::iterator it=store.begin();it!=store.end();it++)
            {
                for(int i=0;i<(it->second).size();i++)
                {
                    rst[nl].push_back((it->second)[i]);
                }
                nl++;
            }
            return rst;
        }
    };
}
/****************************************************************************************************
                                             Note
sort string. 
there are some more infactive solutions...

solution 2: use counter to generate a new string
****************************************************************************************************/