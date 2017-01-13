/****************************************************************************************************
                                   168. Excel Sheet Column Title        
-----------------------------------------------------------------------------------------------------
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string convertToTitle(int n) {
	        int curr=1;
	        string rst;
	        while (n!=0)
	        {
	            curr=n%26;
	            if(curr==0) {rst='Z'+rst;n--;}           // **
	            else        rst=char(curr-1+'A')+rst;    // ***
	            n/=26;
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
** here should -1 because 'Z' count as one already. or it will left 1 for the next. 

*** need to pust things in front
****************************************************************************************************/