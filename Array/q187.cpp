/****************************************************************************************************
                               187. Repeated DNA Sequences              
-----------------------------------------------------------------------------------------------------
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in 
a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> findRepeatedDnaSequences(string s) {
	        int len = s.size();
	        vector<string> rst;
	        if (len<=10) return rst;
	        
	        map<string,int> sq;
	        for(int i=0;i<=len-10;i++)
	        {
	            string sstr = s.substr(i,10);
	            sq[sstr]++;
	            if (sq[sstr]==2) rst.push_back(sstr);
	        }
	        
	        return rst;
	    }
	};

	class Solution2 {
	public:
	    vector<string> findRepeatedDnaSequences(string s) {
	        int len=s.size();
	        vector<string> rst;
	        if (len<10) return rst;
	        unordered_map<char,int> tran;
	        tran['A']=1;
	        tran['C']=2;
	        tran['G']=3;
	        tran['T']=4;
	        
	        unordered_map<long,int> store;
	        int i=0;
	        long curr=0;
	        while(i<=9)
	        {
	            curr=curr*10+tran[s[i++]];
	        }
	        store[curr]++;;
	        while(i<len)
	        {
	            curr-=long(tran[s[i-10]])*1e9;
	            curr=curr*10+tran[s[i]];
	            if (store.find(curr)!=store.end() && store[curr]==1)
	                rst.push_back(s.substr(i-9,10));
	            store[curr]++;
	            i++;
	        }
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
The improvement is change the string to int. 
****************************************************************************************************/