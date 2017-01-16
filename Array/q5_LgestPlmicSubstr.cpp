/****************************************************************************************************
                                   5. Longest Palindromic Substring
-----------------------------------------------------------------------------------------------------
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length 
of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
****************************************************************************************************/

class Solution {
public:
    string longestPalindrome(string s) {
        // mirror expansion
        int maxlen = 1;
        string substring = s.substr(0,1);
        int im=0;
        int ip=0;
        for (int ic=1;ic<s.size();ic++)
        {
            // two letter for center. get the maxlen

            im=ic-1;
            ip=ic;
            
            while(im>=0 && ip<s.size())
            {
                if (s[ip]!=s[im])
                {
                    break;
                }
                im--;
                ip++;
            }
            if (maxlen<ip-im-1)
            {
                maxlen = ip-im-1;
                substring = s.substr(im+1,maxlen);
            }

            im=ic;ip=ic;
            while(im>=0 && ip<s.size())
            {
                if (s[ip]!=s[im])
                {
                    break;
                }
                im--;
                ip++;
            }
            
            if (maxlen<ip-im-1)
            {
                maxlen=ip-im-1;
                substring = s.substr(im+1,maxlen);
            }
        }
        return substring;
    }
};

/****************************************************************************************************
                                             Note
Hint: using mirroring. on pointer ic, two possibility: two-letter-center or one-letter-center. match
on both side.

****************************************************************************************************/