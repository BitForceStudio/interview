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
}

/****************************************************************************************************
                                             Note
The improvement is change the string to int. 
****************************************************************************************************/