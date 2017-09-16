/****************************************************************************************************
                               329. Longest Increasing Path in a Matrix              
-----------------------------------------------------------------------------------------------------
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move 
diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int longestIncreasingPath(vector<vector<int>>& matrix) { 
	        int lenr = matrix.size();
	        if (lenr==0) return 0;
	        int lenc = matrix[0].size();
	        if (lenc==0) return 0;
	        
	        vector< vector<int> > maxlength(lenr,vector<int>(lenc,1));
	        
	        int maxrst = 1;
	        int currrst=0;
	        
	        for(int i=0;i<lenr;i++)
	        {
	            for(int j=0;j<lenc;j++)
	            {
	                if (maxlength[i][j]>1) 
	                    continue; 
	                currrst = longestpath(maxlength,matrix,lenr,lenc,i,j,maxrst);
	            }
	        }
	        return maxrst;
	    }
	    
	    int longestpath(vector<vector<int>>& maxlength,vector<vector<int>>& matrix, int lenr, int lenc, int i, int j, int& max)
	    {
	        int curr=1;
	        if (maxlength[i][j]>1)
	        {
	            return maxlength[i][j];
	        }
	        
	        if (i>0 && matrix[i-1][j]>matrix[i][j])
	        {
	            curr += longestpath(maxlength,matrix,lenr,lenc,i-1,j,max);
	        }
	        if (j>0 && matrix[i][j-1]>matrix[i][j])
	        {
	            int tmp =1+ longestpath(maxlength,matrix,lenr,lenc,i,j-1,max);
	            curr=curr>tmp?curr:tmp;
	        }
	        if (i<lenr-1 && matrix[i+1][j]>matrix[i][j])
	        {
	            int tmp = 1+longestpath(maxlength,matrix,lenr,lenc,i+1,j,max);
	            curr=curr>tmp?curr:tmp;
	        }
	        if (j<lenc-1 && matrix[i][j+1]>matrix[i][j])
	        {
	            int tmp = 1+longestpath(maxlength,matrix,lenr,lenc,i,j+1,max);
	            curr=curr>tmp?curr:tmp;
	        }
	        
	        maxlength[i][j]=curr;
	        if (curr>max) max=curr;
	        return curr;
	    }

	};

}

/****************************************************************************************************
                                             Note
dp, greedy. store the max length of current element. if explored this one, just 1+ this. 
****************************************************************************************************/