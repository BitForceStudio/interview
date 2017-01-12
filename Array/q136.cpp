/****************************************************************************************************
                                     136. Single Number        
-----------------------------------------------------------------------------------------------------
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
****************************************************************************************************/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            nums[0]=nums[0]^nums[i];
        }
        
        return nums[0];
    }
};

/****************************************************************************************************
                                             Note
i should consider as extra mem?
****************************************************************************************************/