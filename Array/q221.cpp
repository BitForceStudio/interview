/****************************************************************************************************
                                       221. Maximal Square      
-----------------------------------------------------------------------------------------------------
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and 
return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maximalSquare(vector<vector<char>>& matrix) {
	        int rst=0;
	        int lenr = matrix.size();
	        if (lenr==0) return rst;
	        int lenc = matrix[0].size();
	        if (lenc==0) return rst;
	        
	        vector<vector<int> > q(lenr,vector<int>(lenc));
	        
	        for(int i=0;i<lenr;i++) 
	        {
	            q[i][0] = matrix[i][0]-'0';
	            if (q[i][0]==1) rst=1;
	        }
	        for(int j=0;j<lenc;j++) 
	        {
	            q[0][j] = matrix[0][j]-'0';
	            if (q[0][j]==1) rst=1;
	        }
	        
	        for(int i=1;i<lenr;i++)
	        {
	            for(int j=1;j<lenc;j++)
	            {
	                if (matrix[i][j]=='1')
	                    q[i][j]=min(min(q[i-1][j],q[i][j-1]),q[i-1][j-1])+1;
	                else
	                    q[i][j]=0;
	                
	                if (q[i][j]>rst) rst=q[i][j];
	            }
	        }
	        
	        return rst*rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
DP problem, should be easy to think of.
****************************************************************************************************/