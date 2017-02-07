/****************************************************************************************************
                                    240. Search a 2D Matrix II         
-----------------------------------------------------------------------------------------------------
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the 
following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool searchMatrix(vector<vector<int>>& matrix, int target) {
	        int lenr = matrix.size();    if (lenr==0) return false;
	        int lenc = matrix[0].size(); if (lenc==0) return false;
	        
	        for(int i=0;i<lenr;i++)
	        {
	            if (matrix[i][0]<=target && matrix[i][lenc-1]>=target)
	                if (find(matrix,i,target)) return true;
	        }
	        return false;
	    }
	    
	    bool find(vector<vector<int> >& matrix, int row, int target)
	    {
	        int s=0,t=matrix[row].size()-1;
	        int mid=0;
	        while(s<t)
	        {
	            mid=s+(t-s)/2;
	            if (matrix[row][mid]==target) return true;
	            else if(matrix[row][mid]<target) s=mid+1;
	            else t=mid;
	        }
	        
	        return target==matrix[row][s];
	    }
	};

}

/****************************************************************************************************
                                             Note
Nothing special, here is the better solution:

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target) {
            j--;
        } else 
            i++;
    }
    return false;
}
****************************************************************************************************/