/****************************************************************************************************
                                      338. Counting Bits       
-----------------------------------------------------------------------------------------------------
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the 
number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in 
linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ 
or in any other language.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> countBits(int num) {
	        vector<int> rst(num+1,0);
	        int offset=1;
	        for(int i=1;i<=num;i++)
	        {
	            if (offset*2==i) offset*=2;
	            
	            rst[i]=rst[i-offset]+1;
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
if meet this kind of question again, firstly, try to find the pattern. Just like Olympic do. It may
be easy to find the answer. 
****************************************************************************************************/