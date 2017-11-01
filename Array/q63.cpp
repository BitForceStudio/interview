/****************************************************************************************************
                                    63. Unique Paths II        
-----------------------------------------------------------------------------------------------------
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	        // use -1 to do the trick.
	        int lenc = obstacleGrid.size()+1;    // colume
	        int lenr = obstacleGrid[0].size()+1; // row
	        vector<vector<long long> > mat; mat.resize(lenc);   // ***
	        for(int i=0;i<lenc;i++) mat[i].resize(lenr,0);
	        
	        mat[lenc-1][lenr-2] = -1;
	        for(int i=lenc-2;i>=0;i--)
	        {
	            bool qadd = false;
	            for(int j=lenr-2;j>=0;j--)
	            {
	                if (obstacleGrid[i][j]>0) continue;
	                mat[i][j] = mat[i+1][j]+mat[i][j+1];
	                qadd = true;
	            }
	            if (!qadd) return 0;
	        }
	        return -mat[0][0];
	    }
	};

	class Solution2 {
	public:
	    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	        int lenr = obstacleGrid.size();
	        if (lenr==0) return 0;
	        int lenc = obstacleGrid[0].size();
	        if (lenc==0) return 0;
	        if(obstacleGrid[0][0]==1 || obstacleGrid[lenr-1][lenc-1]==1) return 0;
	        
	        vector< vector<int> > dp(lenr,vector<int>(lenc,0));
	        for(int i=0;i<lenc;i++)
	        {
	            if(obstacleGrid[0][i]==0)
	            {
	                dp[0][i]=1;
	            }
	            else break;
	        }
	        
	        for(int i=0;i<lenr;i++)
	        {
	            if(obstacleGrid[i][0]==0)
	            {
	                dp[i][0]=1;
	            }
	            else break;
	        }
	        
	        for(int i=1;i<lenr;i++)
	        {
	            for(int j=1;j<lenc;j++)
	            {
	                dp[i][j]=((!obstacleGrid[i-1][j])?dp[i-1][j]:0)+((!obstacleGrid[i][j-1])?dp[i][j-1]:0);
	            }
	        }
	        
	        return dp[lenr-1][lenc-1];
	    }
	};
}

/****************************************************************************************************
                                             Note
*** here need to be careful, it may exceed the int range. 
****************************************************************************************************/