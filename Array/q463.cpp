/****************************************************************************************************
                                        463. Island Perimeter     
-----------------------------------------------------------------------------------------------------
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents 
water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely 
surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The 
island doesn't have "lakes" (water inside that isn't connected to the water around the island). One 
cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
Determine the perimeter of the island.

Example:

[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
Explanation: The perimeter is the 16 yellow stripes in the image below:
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int islandPerimeter(vector<vector<int>>& grid) {
	        int lenr=grid.size();
	        if (lenr==0) return 0;
	        int lenc=grid[0].size();
	        if (lenc==0) return 0;
	        
	        int ones=0;
	        int conn=0;
	        for(int i=0;i<lenr;i++)
	        {
	            for(int j=0;j<lenc;j++)
	            {
	                if (grid[i][j]==1)
	                {
	                    ones++;
	                
	                    if (i>0 && grid[i-1][j]==1) conn++;
	                    if (j>0 && grid[i][j-1]==1) conn++;
	                }
	            }
	        }
	        
	        return ones*4-2*conn;
	    }
	};

}

/****************************************************************************************************
                                             Note
Be careful about the conditions
****************************************************************************************************/