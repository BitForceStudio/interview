/****************************************************************************************************
                                      454. 4Sum II       
-----------------------------------------------------------------------------------------------------
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such 
that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers 
are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	        int len=A.size();
	        if (len==0) return 0;
	        
	        unordered_map<int,int> upper;
	        
	        for(int i=0;i<len;i++)
	        {
	            for(int j=0;j<len;j++)
	            {
	                upper[A[i]+B[j]]++;
	            }
	        }
	        
	        int rst = 0;
	        for(int i=0;i<len;i++)
	        {
	            for(int j=0;j<len;j++)
	            {
	                rst+=upper[0-C[i]-D[j]];
	            }
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
map, O(n*n)
one map is enough.
****************************************************************************************************/