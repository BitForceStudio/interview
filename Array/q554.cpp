/****************************************************************************************************
                                     554. Brick Wall        
-----------------------------------------------------------------------------------------------------
There is a brick wall in front of you. The wall is rectangular and has several rows of bricks. The 
bricks have the same height but different width. You want to draw a vertical line from the top to the 
bottom and cross the least bricks.

The brick wall is represented by a list of rows. Each row is a list of integers representing the 
width of each brick in this row from left to right.

If your line go through the edge of a brick, then the brick is not considered as crossed. You need 
to find out how to draw the line to cross the least bricks and return the number of crossed bricks.

You cannot draw a line just along one of the two vertical edges of the wall, in which case the line 
will obviously cross no bricks.

Example:
Input: 
[[1,2,2,1],
 [3,1,2],
 [1,3,2],
 [2,4],
 [3,1,2],
 [1,3,1,1]]
Output: 2
Explanation: 

Note:
The width sum of bricks in different rows are the same and won't exceed INT_MAX.
The number of bricks in each row is in range [1,10,000]. The height of wall is in range [1,10,000]. 
Total number of bricks of the wall won't exceed 20,000.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int leastBricks(vector<vector<int>>& wall) {
	        int rst=0;
	        int h = wall.size();
	        if (h==1) return wall[0].size()<=1;
	        int max=0;
	        
	        map<int,int> count;
	        for(int i=0;i<h;i++)
	        {
	            int curr=0;
	            for(int j=0;j<wall[i].size()-1;j++) //**
	            {
	                curr+=wall[i][j];
	                count[curr]++;
	                if(count[curr]>max) max=count[curr];
	            }
	        }
	        return h-max;
	    }
	};

}

/****************************************************************************************************
                                             Note
** here must be size -1. because the boundary is not counted.
****************************************************************************************************/