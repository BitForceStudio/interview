/****************************************************************************************************
                                    58. Length of Last Word          
-----------------------------------------------------------------------------------------------------
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the 
length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
****************************************************************************************************/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.size();
        int ic=len-1;
        while(s[ic]==' ') ic--;
        len=ic;
        for(;ic>=0;ic--)
        {
            if(s[ic]==' ') break;
        }
        return len-ic;
    }
};

/****************************************************************************************************
                                             Note
Need to understand the quesiton...
****************************************************************************************************/