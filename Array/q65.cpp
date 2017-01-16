/****************************************************************************************************
                                      65. Valid Number       
-----------------------------------------------------------------------------------------------------
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up 
front before implementing one.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isNumber(string s) {
	        int i=0;
	        
	        // skip the spaces in the front
	        for(;s[i]==' ';i++) {}
	        
	        // check sign
	        if (s[i]=='+' || s[i]=='-') i++;
	        
	        // check number and dots
	        int ndots=0;
	        int ndig=0;
	        for(;(s[i]=='.' || (s[i]>='0' && s[i]<='9'));i++)
	            s[i]=='.'?ndots++:ndig++;
	        if (ndots>1 || ndig<1) return false;
	        
	        // check for 'e'
	        if (s[i]=='e')
	        {
	            i++;
	            // check for sign
	            if (s[i]=='+' || s[i]=='-') i++;
	            // after e, it must be a integer and it must has at least one
	            int ndig=0;
	            for(;s[i]>='0' && s[i]<='9';i++) ndig++;
	            
	            if (ndig<1) return false;
	        }
	        
	        for(;s[i]==' ';i++) {}
	        
	        return i==s.size();
	    }
	};

}

/****************************************************************************************************
                                             Note
nothing special, careful about init int variable and that's it. 
16： hexadecimal.
ask about, should consider the cases other than decimal. 

****************************************************************************************************/