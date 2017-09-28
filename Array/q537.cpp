/****************************************************************************************************
                                537. Complex Number Multiplication             
-----------------------------------------------------------------------------------------------------
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string complexNumberMultiply(string a, string b) {
	        int a1=0,a2=0,b1=0,b2=0;
	        getint(a,a1,a2);
	        getint(b,b1,b2);
	        int c1 = a1*b1-a2*b2;
	        int c2 = a1*b2+a2*b1;
	        return to_string(c1)+'+'+to_string(c2)+'i';
	    }
	    
	    void getint(string str, int& first, int& second)
	    {
	        int i=0;
	        int sign = 1;
	        if (str[i]=='-') 
	        {
	            sign=-1;
	            i++;
	        }
	        for(;i<str.size() && str[i]!='+';i++) 
	        {
	            first=first*10+str[i]-'0';
	        }
	        first*=sign;
	        i++; sign=1;
	        if (str[i]=='-') 
	        {
	            sign=-1;
	            i++;
	        }
	        for(;i<str.size() && str[i]!='i';i++) 
	        {
	            second=second*10+str[i]-'0';
	        }
	        second*=sign;
	    }
	};

}

/****************************************************************************************************
                                             Note
Don't forget the negtive number from the string if use the function defined by myself (stoi)
****************************************************************************************************/