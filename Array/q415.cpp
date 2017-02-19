/****************************************************************************************************
                                   415. Add Strings          
-----------------------------------------------------------------------------------------------------
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string addStrings(string num1, string num2) {
	        string rst="";
	        int len1=num1.size(); if (len1==0) return num2;
	        int len2=num2.size(); if (len2==0) return num1;
	        len1--;
	        len2--;
	        int c=0;
	        while(len1>=0 && len2>=0)
	        {
	            int curr=num1[len1]-'0'+num2[len2]-'0' + c;
	            c=curr/10;
	            curr=curr%10;
	            rst=to_string(curr)+rst;
	            len1--;
	            len2--;
	        }
	        
	        while(len1>=0)
	        {
	            int curr=num1[len1]-'0' + c;
	            c=curr/10;
	            curr=curr%10;
	            rst=to_string(curr)+rst;
	            len1--;
	        }
	        
	        while(len2>=0)
	        {
	            int curr=num2[len2]-'0' + c;
	            c=curr/10;
	            curr=curr%10;
	            rst=to_string(curr)+rst;
	            len2--;
	        }
	        
	        if (c>0) rst="1"+rst;
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Nothing to say...
****************************************************************************************************/