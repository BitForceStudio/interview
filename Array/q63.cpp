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

}

/****************************************************************************************************
                                             Note
*** here need to be careful, it may exceed the int range. 
****************************************************************************************************/