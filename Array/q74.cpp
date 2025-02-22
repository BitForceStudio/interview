/****************************************************************************************************
                                       74. Search a 2D Matrix      
-----------------------------------------------------------------------------------------------------
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the 
following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	        int lenc = matrix.size();
	        if (lenc==0) return false;
	        int lenr = matrix[0].size();
	        if (lenr==0) return false;
	        if (target<matrix[0][0]) return false;
	        
	        int l=0,r=lenc*lenr-1;
	        while(l!=r)
	        {
	            int mid=(l+r-1)>>1;
	            if (matrix[mid/lenr][mid%lenr]<target) l=mid+1;
	            else r=mid;
	        }
	        return matrix[r/lenr][r%lenr]==target;
	    }
	};

	class Solution {
	public:
	    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	        int lenr = matrix.size();
	        if(lenr==0) return false;
	        int lenc = matrix[0].size();
	        if(lenc==0) return false;
	        if(target<matrix[0][0] || target > matrix[lenr-1][lenc-1]) return false;
	        
	        // binary search on first colume
	        int s=0,t=lenr*lenc-1;
	        int mid =0;
	        while(s<=t)
	        {
	            mid=(s+t)/2;
	            if(matrix[mid/lenc][mid%lenc]<target) s=mid+1;
	            else if(matrix[mid/lenc][mid%lenc]>target) t=mid-1;
	            else return true;
	        }
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
1: it was a sorted list
2: better remember how to do the binary searth, this kind of basic algorithm. it cannot be wrong.
****************************************************************************************************/