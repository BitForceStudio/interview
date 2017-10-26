/****************************************************************************************************
                                    47. Permutations II             
-----------------------------------------------------------------------------------------------------
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

    class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            int len = nums.size();
            vector<vector<int> > rst;
            if (len==0) return rst;
            if (len==1) {rst.push_back(nums); return rst;}
            
            vector<int> csol; csol.push_back(nums[0]);
            rst.push_back(csol);
            for(int i=1;i<len;i++)
            {
                map<vector<int>,bool> mtmp;
                vector<vector<int> > tmp;
                std::vector<vector<int> >::iterator itv;
                for(int j=0;j<rst.size();j++)
                {
                    vector<int> icsol=rst[j];
                    vector<int>::iterator it = icsol.begin();
                    icsol.insert(it,1,nums[i]);
                    if (!mtmp[icsol])
                    {
                        mtmp[icsol]=true;
                        tmp.push_back(icsol);
                    }
                    for(int k=0;k<rst[j].size();k++)
                    {
                        vector<int> csol=rst[j];
                        if (csol[k]==nums[i]) continue;
                        vector<int>::iterator it = csol.begin();
                        csol.insert(it+k+1,1,nums[i]);
                        if (!mtmp[csol])
                        {
                            mtmp[csol]=true;
                            tmp.push_back(csol);
                        }
                    }
                }
                rst = tmp;
            }
            return rst;
        }
    };

    class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int> > rst;
            int len=nums.size();
            if(len==0) return rst;
            if(len==1) {rst.push_back(nums); return rst;}
            
            vector<int> curr;
            helper(nums,curr,rst);
            return rst;
        }
        
        void helper(vector<int> nums, vector<int> curr, vector<vector<int> >& rst)
        {
            int len=nums.size();
            if(len==1)
            {
                curr.push_back(nums[0]);
                rst.push_back(curr);
                return;
            }
            
            set<int> placed;
            for(int i=0;i<len;i++)
            {
                if(placed.find(nums[i])!=placed.end()) continue;
                placed.insert(nums[i]);
                curr.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                helper(nums,curr,rst);
                nums.insert(nums.begin()+i,curr.back());
                curr.pop_back();
            }
        }
    };
}
/****************************************************************************************************
                                             Note
used hash table to hold all vectors. it was not very clever but it solved the problme.

there is another way. think about it.  

solution2

use dfs to do the purmute
****************************************************************************************************/