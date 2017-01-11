/****************************************************************************************************
                                       40. Combination Sum II     
-----------------------------------------------------------------------------------------------------
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
****************************************************************************************************/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > rst;
        if (candidates.size()==0) return rst;
        
        sort(candidates.begin(),candidates.end());
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
            find(c,rst,bt,ic-1,ctg);
            bt.pop_back();
        }
        return;
    }
};

/****************************************************************************************************
                                             Note
*** be careful, there may be duplacation, so, need to find it out. 
In solution search by index loop. cannot include the duplication. 
****************************************************************************************************/