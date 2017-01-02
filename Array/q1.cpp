/****************************************************************************************************
                                           1. Two Sum
-----------------------------------------------------------------------------------------------------
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
****************************************************************************************************/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> srcmap;
        vector<int> findindex; findindex.resize(2,-1);
        for (int i=0;i<int(nums.size());i++)
        {
            if(srcmap.find(target-nums[i])!=srcmap.end() )
            {
                findindex[0] = srcmap[target-nums[i]];
                findindex[1] = i;
                return findindex;
            }
            srcmap[nums[i]]=i;
        }
        return findindex;
    }
};

/****************************************************************************************************
                                             Note
Hint: use hash table. key is value and vale is the index.  
****************************************************************************************************/