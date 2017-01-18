/****************************************************************************************************
                                       77. Combinations      
-----------------------------------------------------------------------------------------------------
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{
    // vector 
	class Solution {
	public:
	    vector<vector<int>> combine(int n, int k) {
	        // dp problem
	        vector<vector<int> > rst;
	        if (n<1 || k<1 || k>n) return rst;
	        
	        // push seed to the rst
	        for(int i=0;i<n-k+1;i++)
	        {
	            vector<int> tmp(1,i+1);
	            rst.push_back(tmp);
	        }
	        
	        for(int i=1;i<k;i++)
	        {
	            // by layers
	            vector<vector<int> >vtmp;
	            for(int j=0;j<rst.size();j++)
	            {
	                int len=rst[j].size();
	                for(int m=rst[j][len-1]+1;m<=n-k+1+i;m++)
	                {
	                    vector<int> tmp=rst[j];
	                    tmp.push_back(m);
	                    vtmp.push_back(tmp);
	                }
	            }
	            rst=vtmp;
	        }
	        
	        return rst;
	    }
	};

	// queue
	class Solution {
	public:
	    vector<vector<int>> combine(int n, int k) {
	        // dp problem
	        vector<vector<int> > rst;
	        if (n<1 || k<1 || k>n) return rst;
	        
	        // push seed to the rst
	        for(int i=0;i<n-k+1;i++)
	        {
	            vector<int> tmp(1,i+1);
	            rst.push_back(tmp);
	        }
	        
	        // act as queue
	        while(true)
	        {
	            int len=rst.front().size(); if (len==k) break;
	            for(int i=rst.front()[len-1]+1;i<=n-k+len+1;i++)
	            {
	                vector<int> tmp=rst.front(); tmp.push_back(i); 
	                rst.push_back(tmp);
	            }
	            rst.erase(rst.begin());
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
1: vector
2: queue?

better one
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n-k+i+1) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};
don't understand... need to know how it works.
****************************************************************************************************/