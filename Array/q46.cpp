/****************************************************************************************************
                                    46. Permutations         
-----------------------------------------------------------------------------------------------------
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{
    class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            // dp. f(n) = g(f(n-1)): g: insert the nth element to n possible position from f(n-1) results. 
            vector<vector<int> > rst;
            int len=nums.size(); 
            if (len<1) return rst;
            if (len==1) {rst.push_back(nums); return rst;}
            
            vector<int> csol; csol.push_back(nums[0]);
            rst.push_back(csol);
            for(int i=1;i<len;i++)
            {
                vector<vector<int> > temp;
                int ilen=rst.size();
                for(int j=0;j<ilen;j++)
                {
                    csol=rst[j];
                    for(int k=0;k<=csol.size();k++)
                    {
                        vector<int> icsol=csol;
                        vector<int>::iterator it=icsol.begin();
                        icsol.insert(it+k,1,nums[i]);
                        temp.push_back(icsol);
                    }
                }
                rst=temp;
            }
            return rst;
        }
    };

    class Solution2 {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            int len=nums.size();
            vector<vector<int> > rst;
            if (len<=1)
            {
                rst.push_back(nums);
                return rst;
            }
            vector<int> current;
            helper(nums,current,rst);
            return rst;
        }
        
        void helper(vector<int> nums, vector<int> current, vector<vector<int> >& rst)
        {
            int len=nums.size();
            if (len==1) 
            {
                current.push_back(nums[0]);
                rst.push_back(current);
                return;
            }
            for(int i=0;i<len;i++)
            {
                current.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                helper(nums,current,rst);
                nums.insert(nums.begin()+i,current.back());
                current.pop_back();
            }
        }
    };
}
/****************************************************************************************************
                                             Note
remember it is a dp problem. 
****************************************************************************************************/