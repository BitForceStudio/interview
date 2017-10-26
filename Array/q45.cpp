/****************************************************************************************************
                                      45. Jump Game II      
-----------------------------------------------------------------------------------------------------
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps 
to the last index.)

Note:
You can assume that you can always reach the last index.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{
    class Solution {
    public:
        int maxstep = 2147483647;
        int jump(vector<int>& nums) {
            int len=nums.size();
            if (len==0) return 0;
            if (nums[0]==0) return 0;
            if (len==1 && nums[0]!=0) return 0;
            
            int max=0;
            int curr = 0;
            int step=0;
            for(int i=0;i<len-1;i++)
            {
                max=max>(i+nums[i])?max:i+nums[i];
                if (i==curr)
                {
                    step++;
                    curr=max;
                }
            }
            return step;
            //int maxstep=2147483647;
            //return runner(nums,0,len-1, 0);
        }
        
        int runner(vector<int>& nums, int curr, int len, int step)
        {
            if (step>=maxstep) return -1;
            if (curr>=len) { maxstep=step; return 0;}
            if (nums[curr]==0) return -1;
            int min = 2147483647;
            for(int i=nums[curr];i>0;i--)
            {
                int rcr = runner(nums,curr+i,len,step+1);
                if (rcr<0) continue;
                min=min<rcr?min:rcr;
            }
            return min+1;
        }
    };

    class Solution2 {
    public:
        int jump(vector<int>& nums) {
            int len=nums.size();
            if(len<=1) return 0;
            
            vector<int> dp(len,INT_MAX);
            dp[0]=0;
            for(int i=0;i<len;i++)
            {
                for(int j=min(i+nums[i],len-1);j>i;j--)
                {
                    if( dp[j]<INT_MAX) break;
                    dp[j]=dp[i]+1;
                    if(j==len-1) return dp[j];
                }
            }
            
            return dp[len-1];
        }
    };

}

/****************************************************************************************************
                                             Note
At first, I still want to use the runner. even I optimized it with maxsteps, it still to slow. 

the other one, is, find the maxnum step based on current step, then if can reach to that maxnum step, 
update the base and go on. becasue there is assumption that there always a solution. so, step store 
the minimal step that can reached the current index. sence the i to the end, it will show the minimal
step to the end. 
****************************************************************************************************/