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

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // backtrack, from big to small, 
        vector<vector<int> > rst;
        sort(candidates.begin(),candidates.end());
        
        if (target<candidates[0]) return rst;
        
        int len = candidates.size()-1;
        for(;len>=0;len--)
        {
            if (candidates[len]<=target)
            {
                vector<int> bt; bt.push_back(len);
                bool tmp = find(candidates,rst,bt,len,target-candidates[len]);
            }
        }
        return rst;
    }
    
    bool find(vector<int>& c,vector<vector<int> >& rst, vector<int>& bt,int bg, int tg)
    {
        if (tg==0) 
        {
            vector<int> tmp; tmp.resize(bt.size());
            for(int i=0;i<bt.size();i++) tmp[i]=c[bt[i]];
            rst.push_back(tmp);
            return true;
        }
        for(int ic=bg;ic>=0;ic--)
        {
            int ctg=tg-c[ic];
            if (ctg<0) continue;
            bt.push_back(ic);
            bool tmp = find(c,rst,bt,ic,ctg);
            bt.pop_back();
        }
        return false;
    }
};

/****************************************************************************************************
                                             Note
it really difficult for me now. I got the thought, but implement the thought to real working code is
really different thing...
practice some more backtracing problem. 
****************************************************************************************************/