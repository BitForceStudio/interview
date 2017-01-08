/****************************************************************************************************
                                 33. Search in Rotated Sorted Array            
-----------------------------------------------------------------------------------------------------
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
****************************************************************************************************/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // special case
        int len=nums.size();
        if (len <1) return -1;
        if (target < nums[0] && target > nums[len-1]) return -1;
        
        // find the splite
        int left=0,right=len-1;
        
        if (nums[0]>nums[len-1])
        {
            while(left<right-1)
            {
                int mid=(left+right)/2;
                if(nums[mid]>nums[right]) left=mid;
                else                      right=mid;
            }
            right--;
        }
        int splite = right;
        if (target>=nums[0])     return binarysearch(nums,0,splite,target);
        if (target<=nums[len-1]) return binarysearch(nums,splite+1,len-1,target);
        return -1;
    }
    
    int binarysearch(vector<int>& nums, int left, int right, int target)
    {
        if (left>right || target>nums[right] || target<nums[left]) return -1;
        if (target==nums[left]) return left;
        if (target==nums[right]) return right;
        
        while(left<right-1)
        {
            int mid=(left+right)/2;
            if(nums[mid]>target) right = mid;
            else                  left = mid;
        }
        
        if (nums[left]<target && nums[right]>target) return -1;
        return left;
    }
};

/****************************************************************************************************
                                             Note
1: binary search, return what? need to think about it. 
****************************************************************************************************/