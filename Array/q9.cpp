/****************************************************************************************************
                                     9. Palindrome Number
-----------------------------------------------------------------------------------------------------
Determine whether an integer is a palindrome. Do this without extra space.
****************************************************************************************************/

#include "problems\problems\Header.h"

namespace std
{

    class Solution {
    public:
        bool isPalindrome(int x) {
            if (x<0) return false;
            int left = 10;
            while(int(x/left)>0 && left<1000000000)
                left*=10;
            if (left<1000000000) left/=10;
            while(left>=10 || x!=0)
            {
                if (int(x/left) != x%10) return false;
                x=x%left;
                x=int(x/10);
                left/=100;
            }
            
            return true;
        }
    };

    class Solution2 {
    public:
        bool isPalindrome(int x) {
            if (x<0) return false;
            if (x<10) return true;
            if (x%10==0) return false;
            
            int tmp=0;
            while(x>tmp)
            {
                tmp=tmp*10+x%10;
                x/=10;
            }
            return (x==tmp) || (x==tmp/10);
        }
    };
}
/****************************************************************************************************
                                             Note
here I use left to find out maxnum E^n. However, it could overflow by times 10. So, it needs a 
condition for it.  
****************************************************************************************************/