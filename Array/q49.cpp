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

/****************************************************************************************************
                                             Note
sort string. 
there are some more infactive solutions...
****************************************************************************************************/