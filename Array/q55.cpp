/****************************************************************************************************
                                        55. Jump Game     
-----------------------------------------------------------------------------------------------------
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
****************************************************************************************************/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        if (len==0) return false;
        if (len==1) return true;
        
        int i = 0;
        for (int reach = 0; i < len && i <= reach; ++i)
            reach = max(i + nums[i], reach);             // get the maxnum that I can reach
        return i == len;
        
        //return runner(nums,0,len-1);
    }
    
    bool runner(vector<int>& nums, int curr, int len)
    {
        if (curr>=len)     return true;
        if (nums[curr]==0) return false;
        for(int i=nums[curr];i>0;i--)
        {
            if (runner(nums,curr+i,len)) return true;
        }
        return false;
    }
};

/****************************************************************************************************
                                             Note
My solution is over all the path. however, in this case, it is not neccessary. What I need to find 
whether it can reach to the end or not. so, that reach part is very smart. 
****************************************************************************************************/