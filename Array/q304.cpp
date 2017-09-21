/****************************************************************************************************
                               304. Range Sum Query 2D - Immutable              
-----------------------------------------------------------------------------------------------------
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left 
corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), 
which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class NumMatrix {
	public:
	    NumMatrix(vector<vector<int>> matrix) {
	        int lenr=matrix.size();
	        if (lenr==0) return;
	        int lenc=matrix[0].size();
	        if (lenc==0) return;
	        
	        m_sum.resize(lenr+1,vector<int>(lenc+1,0));
	        m_sum[1][1]=matrix[0][0];
	        for(int i=2;i<lenr+1;i++) m_sum[i][1]=m_sum[i-1][1]+matrix[i-1][0];
	        for(int j=2;j<lenc+1;j++) m_sum[1][j]=m_sum[1][j-1]+matrix[0][j-1];
	        
	        for(int i=2;i<lenr+1;i++)
	        {
	            for(int j=2;j<lenc+1;j++)
	            {
	                m_sum[i][j]=matrix[i-1][j-1]+m_sum[i-1][j]+m_sum[i][j-1]-m_sum[i-1][j-1];  //**
	            }
	        }
	    }
	    
	    int sumRegion(int row1, int col1, int row2, int col2) {
	        return m_sum[row2+1][col2+1]-m_sum[row1][col2+1]-m_sum[row2+1][col1]+m_sum[row1][col1];
	    }
	    
	private:
	    vector<vector<int> > m_sum;
	};

	/**
	 * Your NumMatrix object will be instantiated and called as such:
	 * NumMatrix obj = new NumMatrix(matrix);
	 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
	 */

	class NumMatrix2 {
	private:
	    vector<vector<int>> matrixsum;
	public:
	    NumMatrix(vector<vector<int>> matrix) {
	        int lenr = matrix.size();
	        if (lenr==0) return;
	        int lenc = matrix[0].size();
	        if (lenc==0) return;
	        
	        matrixsum.resize(lenr+1,vector<int>(lenc+1,0));
	        
	        for(int i=1;i<=lenr;i++)
	        {
	            for(int j=1;j<=lenc;j++)
	            {
	                matrixsum[i][j] = matrixsum[i][j-1]+matrixsum[i-1][j]-matrixsum[i-1][j-1]+matrix[i-1][j-1];
	            }
	        }
	    }
	    
	    int sumRegion(int row1, int col1, int row2, int col2) {
	        return matrixsum[row2+1][col2+1]-matrixsum[row2+1][col1]-matrixsum[row1][col2+1]+matrixsum[row1][col1];
	    }
	};

}

/****************************************************************************************************
                                             Note
need to be careful in ** 
****************************************************************************************************/