/****************************************************************************************************
                                   41. First Missing Positive    
-----------------------------------------------------------------------------------------------------
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
****************************************************************************************************/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size()==0) return 1;
        int len=nums.size();
        for(int i=0;i<len;i++)
        {
            int target = nums[i];
            while(target<len && target>=0 && target!=nums[target-1])
            {
                int tmp = nums[i];
                nums[i]=nums[target-1];
                if (target-1 < len) nums[target-1]=tmp;
                target = nums[i];
            }
        }
        
        for(int i=0;i<len;i++)
        {
            if (nums[i]!=i+1) return i+1;
        }
        return len+1;
    }
};

/****************************************************************************************************
                                             Note
push numbers in the right place and it must be in range. if out of the range, then ignore. 
****************************************************************************************************/