/****************************************************************************************************
                                      205. Isomorphic Strings       
-----------------------------------------------------------------------------------------------------
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isIsomorphic(string s, string t) {
	        int len = s.size();
	        if (len==0 || len==1) return true;
	        
	        vector<char> vs; vs.resize(256,0);
	        vector<char> vt; vt.resize(256,0);
	        for(int i=0;i<len;i++)
	        {
	            if (vs[s[i]]==0 && vt[t[i]]==0)
	            {
	                vs[s[i]] = t[i];
	                vt[t[i]] = s[i];
	            }
	            else 
	            {
	                if (vs[s[i]]!=t[i] || vt[t[i]]!=s[i]) return false;
	            }
	        }
	        return true;
	    }
	};

	class Solution2 {
	public:
	    bool isIsomorphic(string s, string t) {
	        int len=s.size();
	        if (len==0) return true;
	        
	        map<char,char> ms;
	        map<char,char> mt;
	        for(int i=0;i<len;i++)
	        {
	            if (ms.find(s[i])!=ms.end() && ms[s[i]]!=t[i]) return false;
	            if (mt.find(t[i])!=mt.end() && mt[t[i]]!=s[i]) return false;
	            ms[s[i]]=t[i];
	            mt[t[i]]=s[i];
	        }
	        return true;
	    }
	};

}

/****************************************************************************************************
                                             Note
need to understand this problem. it want to a mapping that map to the same one. 

map is not effiency.
****************************************************************************************************/