/****************************************************************************************************
                                    171. Excel Sheet Column Number         
-----------------------------------------------------------------------------------------------------
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int titleToNumber(string s) {
	        if (s.size()<1) return 0;
	        if (s.size()==1) return int(s[0])-64;
	        
	        int rst=0;
	        for(int i=0;i<s.size();i++)
	        {
	            rst=(s[i]-64)+rst*26;
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
use 64 instead of 'A'-1 will be much quicker. 

****************************************************************************************************/