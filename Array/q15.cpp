/****************************************************************************************************
                                             15. 3Sum
-----------------------------------------------------------------------------------------------------
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
****************************************************************************************************/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> sol;
        if (len<3) return sol;
        
        // sort the array
        std::sort(nums.begin(),nums.end());
        
        map<int,int> dup;
        for (int i=0;i<len;i++)
        {
            if(dup.find(nums[i])!=dup.end()) dup[nums[i]]++;
            else dup[nums[i]] = 0;
        }
        
        vector<int> add;add.resize(3);
        for(int i=0;i<len;i++)
        {
            if (i>0)
            {
                if (nums[i]==nums[i-1]) continue;
            }
            if (nums[i]>0) break;
            
            for(int j=i+1;j<len;j++)
            {
                if (nums[j]==nums[j-1] && j>i+1) continue;  // j>i+1, accept if nums[i] == nums[i+1]
                int sum = -nums[i]-nums[j];
                
                if(dup.find(sum)!=dup.end())
                {
                    // find one, check does sum == nums[j] if so, check dup, if not, pass
                    if ((sum==nums[j] && dup[nums[j]]) || sum > nums[j] )
                    {
                        if(sum==0 && dup[0]<2) continue; // special case, if two 0s, and there are less than 3 0s, continue.
                        add[0] = nums[i];
                        add[1] = nums[j];
                        add[2] = sum;
                        sol.push_back(add);
                    }
                }
            }
        }
        return sol;
    }
    
};

/****************************************************************************************************
                                             Note
The key point is first sort the array, then get the hash table, key is integer and value is count.

in the loop, just check the bigger ones and duplication integer.  
****************************************************************************************************/