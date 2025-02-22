/****************************************************************************************************
                                      70. Climbing Stairs       
-----------------------------------------------------------------------------------------------------
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.
****************************************************************************************************/

#include "problems\problems\Header.h"

namespace std
{
    class Solution {
    public:
        int climbStairs(int n) {
            // DP problem
            // f(n) = f(n-1) + f(n-2)
            if (n==0) return 0;
            
            int p=1,q=1;
            for(int i=0;i<n;i++)
            {
                int temp = q;
                q+=p;
                p=temp;
            }
            return p;
        }
        
        int fb(int n)  // time limit exceed
        {
            if(n==1 || n==2) return n;
            return fb(n-1)+fb(n-2);
        }
    };

    class Solution2 {
    public:
        int climbStairs(int n) {
            if (n<=3) return n;
            
            int p=2,rst=3;
            for(int i=3;i<n;i++)
            {
                rst+=p;
                p=rst-p;
            }
            return rst;
        }
    };
}

/****************************************************************************************************
                                             Note
The iter function working but time exceed. 
it should use the loop because it was easy. 
****************************************************************************************************/