/****************************************************************************************************
                             26. Remove Duplicates from Sorted Array             
-----------------------------------------------------------------------------------------------------
Given a sorted array, remove the duplicates in place such that each element appear only once and 
return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 
respectively. It doesn't matter what you leave beyond the new length.
****************************************************************************************************/

#include "problems\problems\Header.h"

namespace std
{
    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            // slow and fast pointer
            if (nums.size()<=1) return nums.size();
            
            int slow=1,fast=1;
            int len=nums.size();
            while(fast<len)
            {
                while(fast<len && nums[fast]==nums[fast-1]) fast++;
                if (fast>=len) break;
                nums[slow] = nums[fast];
                slow++;fast++;   // I forgot the fast++, where would cause problem
            }
            return slow;
        }
    };

    class Solution2 {
    public:
        int removeDuplicates(vector<int>& nums) {
            int len=nums.size();
            if (len<=1) return len;
            
            int s=1;
            for(int f=1;f<len;f++)
            {
                if (nums[f]==nums[f-1]) continue;
                if (nums[f]!=nums[s])
                {
                    nums[s]=nums[f];
                    s++;
                }
                else if (nums[s]!=nums[s-1]) s++;
            }
            return s;
        }
    };
}
/****************************************************************************************************
                                             Note
the fast should add 1 after set the value to slow.
****************************************************************************************************/