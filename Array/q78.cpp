/****************************************************************************************************
                                      78. Subsets       
-----------------------------------------------------------------------------------------------------
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<vector<int>> subsets(vector<int>& nums) {
	        vector<vector<int> > rst;
	        vector<vector<int> > index;
	        vector<int> tmp; rst.push_back(tmp); index.push_back(tmp);
	        int nlen = nums.size();
	        if (nlen==0) return rst;
	        
	        for(int i=0;i<nlen;i++)
	        {
	            vector<int> tmp(1,nums[i]);
	            rst.push_back(tmp);
	            tmp[0]=i;
	            index.push_back(tmp);
	        }
	        int i=1;
	        while(true)
	        {
	            if (rst.back().size()==nlen) break;
	            int len = index[i].size();
	            vector<int> tmp=index[i];
	            vector<int> rtmp=rst[i];
	            tmp.resize(len+1); rtmp.resize(len+1);
	            for(int j=tmp[len-1]+1;j<nlen;j++)
	            {
	                tmp[len]=j;
	                index.push_back(tmp);
	                rtmp[len] = nums[j];
	                rst.push_back(rtmp);
	            }
	            i++;
	        }
	        
	        return rst;
	    }
	};

	class Solution2 {
	public:
	    vector<vector<int>> subsets(vector<int>& nums) {
	        int len = nums.size();
	        vector<vector<int> > rst; rst.resize(1);
	        if (len<=0)
	        {
	            return rst;
	        }
	        
	        for(int i=0;i<len;i++)
	        {
	            int l = rst.size();
	            for(int j=0;j<l;j++)
	            {
	                vector<int> tmp = rst[j];
	                tmp.push_back(nums[i]);
	                rst.push_back(tmp);
	            }
	        }
	        
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
need to use two vectors to store. is there a better way?

class Solution {
public:
vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int> > res(1, vector<int>());
	sort(S.begin(), S.end());
	
	for (int i = 0; i < S.size(); i++) {
		int n = res.size();
		for (int j = 0; j < n; j++) {
			res.push_back(res[j]);
			res.back().push_back(S[i]);
		}
	}

	return res;
  }
};
use the first empty. then it will do the trick
****************************************************************************************************/