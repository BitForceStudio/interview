/****************************************************************************************************
                                     28. Implement strStr()          
-----------------------------------------------------------------------------------------------------
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
****************************************************************************************************/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenh=haystack.size();
        int lenn=needle.size();
        if (lenn>lenh) return -1;
        if (lenn==0)   return 0;        // if needle is empty, return 0
        
        for(int i=0;i<=lenh-lenn;i++)   // here should be <= be cause it was 0 based
        {
            if(haystack[i]==needle[0])
            {
                bool qfound=true;
                for(int j=1;j<lenn;j++)
                {
                    if (haystack[i+j]!=needle[j]) 
                    {
                        qfound=false;
                        break;
                    }
                }
                if (qfound) return i;
            }
        }
        return -1;                       // don't forget return something
    }
};

/****************************************************************************************************
                                             Note
needle can be more than one char. 

****************************************************************************************************/