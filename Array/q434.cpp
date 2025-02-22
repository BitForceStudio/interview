/****************************************************************************************************
                               434. Number of Segments in a String          
-----------------------------------------------------------------------------------------------------
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of 
non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int countSegments(string s) {
	        int rst=0;
	        for(int i=0;i<s.size();i++)
	        {
	            if (s[i]!=' ' && (i==0 || s[i-1]==' ')) rst++;
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
it cannot count the number of spaces. it could be more spaces .

another one is that, if non-space chat with a space, it will be counted.
****************************************************************************************************/