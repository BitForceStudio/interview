/****************************************************************************************************
                                     34. Search for a Range        
-----------------------------------------------------------------------------------------------------
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
****************************************************************************************************/

#include "problems\problems\Header.h"

namespace std
{
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> rst; rst.resize(2,-1);
            int len = nums.size();
            if (len==0 || target<nums[0] || target > nums[len-1]) return rst;
            if (target==nums[0])    {rst[0]=0; rst[1]=0;}
            if (target==nums[len-1]) rst[1] = len-1;
            int left=binaryfind(nums,double(target)-0.5);
            int right=binaryfind(nums,double(target)+0.5);
            if ((right - left)<1 && target!=nums[len-1]) return rst;
            rst[0] = left;     if (target==nums[0])     rst[0] = 0;
            rst[1] = right-1;  if (target==nums[len-1]) rst[1] = len-1;
            return rst;
        }
        
        int binaryfind(vector<int>& nums, double target)
        {
            int left=0,right=nums.size()-1;
            while(left<right-1)
            {
                int mid = (left+right)/2;
                if (target<nums[mid]) right=mid;
                else left=mid;
            }
            return right;
        }
    };

    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> rst(2,-1);
            int len=nums.size();
            if(len==0) return rst;
            int s=0;
            int t=len-1;
            int mid=0;
            if(target < nums[s] || target > nums[t]) return rst;
            while(s<=t) 
            {
                mid = (s+t)/2;
                if(nums[mid]<target) s=mid+1;
                else if (nums[mid]>target) t=mid-1;
                else break;
            }
            
            if(nums[mid]==target)
            {
                int tmp=mid;
                while(tmp>=0 && nums[tmp]==target) tmp--;
                rst[0]=tmp+1;
                tmp=mid;
                while(tmp<len && nums[tmp]==target) tmp++;
                rst[1]=tmp-1;
            }
            
            return rst;
        }
    };
}
/****************************************************************************************************
                                             Note
here it return the right pointor of the target. 
so there are several special cases need to be considered 

****************************************************************************************************/