/****************************************************************************************************
                                    73. Set Matrix Zeroes         
-----------------------------------------------------------------------------------------------------
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    void setZeroes(vector<vector<int>>& matrix) {
	        // the O(m+n) is obvious, however, in place is not. use first row and colume to label 
	        //which one is the zero. if first row or first colume get zeros, then mark boolean value 
	        //as true. set the first row and colume at last. 
	        
	        int lenc=matrix.size();    if(lenc==0) return;
	        int lenr=matrix[0].size(); if(lenr==0) return;
	        bool qrow=false,qcol=false;
	        for(int i=0;i<lenc;i++)
	        {
	            for(int j=0;j<lenr;j++)
	            {
	                if (matrix[i][j]==0)
	                {
	                    matrix[i][0]=0;
	                    matrix[0][j]=0;
	                    if (i==0) qrow=true;
	                    if (j==0) qcol=true;
	                }
	            }
	        }
	        
	        for(int i=1;i<lenc;i++)
	        {
	            if (matrix[i][0]==0)
	            for(int j=1;j<lenr;j++) matrix[i][j]=0;
	        }

	        for(int j=1;j<lenr;j++)
	        {
	            if (matrix[0][j]==0)
	            for(int i=1;i<lenc;i++) matrix[i][j]=0;
	        }
	       
	        if (qrow) 
	        {
	            for(int i=0;i<lenr;i++) matrix[0][i]=0;
	        }
	        
	        if (qcol)
	        {
	            for(int i=0;i<lenc;i++) matrix[i][0]=0;
	        }
	        return;
	    }
	};

}

/****************************************************************************************************
                                             Note
Need to think about this. need to store which row or col is zero. and that's all it needs. 
Remember it. 
****************************************************************************************************/