/****************************************************************************************************
                                      39. Combination Sum       
-----------------------------------------------------------------------------------------------------
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique 
combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
****************************************************************************************************/

#include "problems\problems\Header.h"

namespace std
{

    class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            // backtrack, from big to small, 
            vector<vector<int> > rst;
            sort(candidates.begin(),candidates.end());
            
            if (target<candidates[0]) return rst;
            
            int len = candidates.size()-1;
            vector<int> bt;
            find(candidates,rst,bt,len,target);
            return rst;
        }
        
        void find(vector<int>& c, vector<vector<int> >& rst, vector<int>& bt, int bg, int tg )
        {
            if (tg==0)
            {
                vector<int> t; t.resize(bt.size());
                for(int i=0;i<bt.size();i++) t[i] = c[bt[i]];
                rst.push_back(t);
                return;
            }
            if (bg<0) return;
            for(int ic=bg;ic>=0;ic--)
            {
                int ctg = tg-c[ic];
                if (ctg<0) continue;
                if (ic+1<=bg && c[ic]==c[ic+1]) continue;   // ***
                bt.push_back(ic);
                find(c,rst,bt,ic,ctg);
                bt.pop_back();
            }

            return;
        }
    };

    class Solution2 {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int> > rst;
            int len = candidates.size();
            if(len==0) return rst;
            
            sort(candidates.begin(),candidates.end());
            vector<int> curr;
            dfs(candidates, curr, rst, 0,target);
            return rst;
        }
        
        void dfs(vector<int>& dict, vector<int> curr, vector<vector<int> >& rst, int st, int target)
        {
            if(target==0)
            {
                rst.push_back(curr);
                return;
            }
            
            for(int i=st; i<dict.size() && dict[i]<=target ;i++)
            {
                curr.push_back(dict[i]);
                dfs(dict,curr,rst,i,target-dict[i]);
                curr.pop_back();
            }
        }
    };
}

/****************************************************************************************************
                                             Note
it really difficult for me now. I got the thought, but implement the thought to real working code is
really different thing...
practice some more backtracing problem. 
****************************************************************************************************/