/****************************************************************************************************
                                    35. Search Insert Position         
-----------------------------------------------------------------------------------------------------
Given a sorted array and a target value, return the index if the target is found. If not, return the 
index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
****************************************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len=nums.size();
        if (len<1) return 0;
        if (nums[0]>target) return 0;
        if (nums[len-1]<target) return len;
        
        int left=leftfound(nums,target);
        if (nums[left]<target) return left+1;
        return left;
    }
    
    int leftfound(vector<int>& nums, int target)
    {
        int left=0,right=nums.size()-1;
        while(left<right-1)
        {
            int mid=(left+right)/2;
            if (nums[mid]<target) left=mid;
            else                  right =mid;
        }
        return left;
    }
};

/****************************************************************************************************
                                             Note
Nothing special. return left pointer. 
****************************************************************************************************/