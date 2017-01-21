/****************************************************************************************************
                                       90. Subsets II      
-----------------------------------------------------------------------------------------------------
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	        int len=nums.size();
	        vector<vector<int> > rst(1,vector<int>());
	        if (len==0) return rst;
	        if (len==1) {rst.push_back(nums); return rst;}
	        
	        sort(nums.begin(),nums.end());
	        map<int,int> count;
	        for(int i=0;i<len;i++)
	        {
	            count[nums[i]]++;  //real count * 
	        }
	        map<int,int>::iterator it; it = count.begin();
	        
	        for(it=count.begin();it!=count.end();it++)
	        {
	            int n=rst.size();
	            for(int i=0;i<n;i++)
	            {
	                rst.push_back(rst[i]);
	                for(int j=0;j<it->second;j++)
	                {
	                    rst.back().push_back(it->first);
	                    if(j+1<it->second)   // **
	                        rst.push_back(rst.back());
	                }
	            }
	        }
	        return rst;
	    }
	};

	class OthersSolution {
	public:
	    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	        int len=nums.size();
	        vector<vector<int> > rst(1,vector<int>());
	        if (len==0) return rst;
	        if (len==1) {rst.push_back(nums); return rst;}
	        
	        sort(nums.begin(),nums.end());
	        
	        int currsize=0;
	        for(int i=0;i<len;i++)
	        {
	            int ind = i>0 && nums[i-1]==nums[i] ? currsize:0;
	            currsize=rst.size();
	            for(int j=ind;j<currsize;j++)
	            {
	                rst.push_back(rst[j]);
	                rst.back().push_back(nums[i]);
	            }
	        }
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
*  it is real count because it was ++, so first time result 1
** because it was added before.

And there is better solution, just set the start point

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> ret = {{}};
    int size = 0, startIndex = 0;
    for (int i = 0; i < S.size(); i++) {
        startIndex = i >= 1 && S[i] == S[i - 1] ? size : 0;
        size = ret.size();
        for (int j = startIndex; j < size; j++) {
            vector<int> temp = ret[j];
            temp.push_back(S[i]);
            ret.push_back(temp);
        }
    }
    return ret;
}
****************************************************************************************************/