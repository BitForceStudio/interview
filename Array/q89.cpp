/****************************************************************************************************
                                      89. Gray Code       
-----------------------------------------------------------------------------------------------------
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence 
of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> grayCode(int n) {
	        vector<int> rst(1,0);
	        if (n==0 || n>32) return rst;
	        
	        
	        int len=pow(2,n);
	        int curr=1;
	        for(int i=1;i<len;i++)
	        {
	            int nbit=1;
	            curr=0;
	            for(int j=0;j<n;j++)
	            {
	                if (i<nbit) break;
	                curr+=((i-nbit)/nbit/2)%2==0?nbit:0;
	                nbit<<1;
	            }
	            rst.push_back(curr);
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
It is not difficult, just try to write down the sequence, it will show the pattern. then try to use
math to model it. 
****************************************************************************************************/