/****************************************************************************************************
                                    216. Combination Sum III         
-----------------------------------------------------------------------------------------------------
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 
1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<vector<int>> combinationSum3(int k, int n) {
	        vector<vector<int> > rst;
	        if (k==0 || n==0) return rst;
	        
	        vector<int> curr;
	        comb(rst,curr,k,n);
	        return rst;
	    }
	    
	private:
	    void comb(vector<vector<int> >& rst, vector<int>& curr, int k, int n)
	    {
	        if (curr.size()==k && n==0)
	        {
	            rst.push_back(curr);
	            return;
	        }
	        
	        if (curr.size()<k)
	        {
	            for(int i=curr.empty()?1:curr.back()+1;i<=9;i++)
	            {
	                if (n-i<0) break;
	                curr.push_back(i);
	                comb(rst,curr,k,n-i);
	                curr.pop_back();
	            }
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
Backtrack needs more practice. 
****************************************************************************************************/