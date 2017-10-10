/****************************************************************************************************
                                     125. Valid Palindrome        
-----------------------------------------------------------------------------------------------------
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring 
cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

    class Solution {
    public:
        bool isPalindrome(string s) {
            int len=s.size();
            if (len==0 || len==1) return true;
            
            int i=0,j=len-1;
            while(i<j)
            {
                if (!(s[i]>='a' && s[i]<='z') && !(s[i]>='A' && s[i]<='Z') && !(s[i]>='0' && s[i]<='9')) {i++; continue;}
                if (!(s[j]>='a' && s[j]<='z') && !(s[j]>='A' && s[j]<='Z') && !(s[j]>='0' && s[j]<='9')) {j--; continue;}
                
                char bg = s[i]<'a'?s[i]:s[i]-32;
                char ed = s[j]<'a'?s[j]:s[j]-32;
                if (bg==ed) 
                {
                    i++;
                    j--;
                }
                else 
                {
                    return false;
                }
            }
            return true;
        }
    };

    class Solution2 {
    public:
        bool isPalindrome(string s) {
            int len=s.size();
            if (len<=1) return true;
            
            int i=0,j=len-1;
            while(i<j)
            {
                while(i<len && !isan(s[i])) i++;
                while(j>=0  && !isan(s[j])) j--;
                if (s[i]==s[j] || (abs(s[i]-s[j])==32 && ((s[i]>=97 && s[i]<=122) || (s[j]>=97 && s[j]<=122))))
                {
                    i++;j--;
                }
                else return false;
            }
            return true;
        }
        
        bool isan(char c)
        {
            return (c>=65 && c<=90) || (c>=97 && c<=122) || (c>=48 && c<=57);
        }
    };
    
}
/****************************************************************************************************
                                             Note
it will consider the numbers. I forgot this part at begining. 
and need to know the ascII table for some basic chars. 
don't forget {}, that's stupid. 
****************************************************************************************************/