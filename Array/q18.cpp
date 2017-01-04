/****************************************************************************************************
                                          18. 4Sum         
-----------------------------------------------------------------------------------------------------
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
****************************************************************************************************/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rst;
        if (nums.size()<4) return rst; 
        std::sort(nums.begin(),nums.end());
        
        int front=2,tail=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            int target1 = target-nums[i];
            int j=i+1;
            while(j<nums.size()-2)
            {
                int target2 = target1-nums[j];
                front = j+1;
                tail = nums.size()-1;
                while(front<tail)
                {
                    int sum=nums[front]+nums[tail];
                    if (sum<target2)
                    {
                        front++;
                    }
                    else if (sum>target2)
                    {
                        tail--;
                    }
                    else
                    {
                        vector<int> qual;qual.resize(4,0);
                        qual[0]=nums[i];
                        qual[1]=nums[j];
                        qual[2]=nums[front];
                        qual[3]=nums[tail];

                        rst.push_back(qual);
                        
                        while (front<tail && nums[front]==qual[2]) front++;
                        while (front<tail && nums[tail]==qual[3]) tail--;
                    }
                }
                
                j++;
                while(j<nums.size()-2 && nums[j]==nums[j-1]) j++;
            }
            
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
        return rst;
    }
};

/****************************************************************************************************
                                             Note
Be careful about the conditions. 
extension version of 3sum.
there are several ways to optimize the conditions. 
****************************************************************************************************/