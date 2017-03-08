/****************************************************************************************************
                                 85. Maximal Rectangle            
-----------------------------------------------------------------------------------------------------
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and 
return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maximalRectangle(vector<vector<char>>& matrix) {
	        // dp problem
	        // area = [min(right)-max(left)]*curr_height
	        
	        int lenr = matrix.size();
	        if (lenr==0) return 0;
	        int lenc = matrix[0].size();
	        if (lenc==0) return 0;
	        
	        vector<int> left(lenc,0);
	        vector<int> right(lenc,lenc);
	        vector<int> height(lenc,0);
	        int maxA=0;
	        for(int ir=0;ir<lenr;ir++)
	        {
	            int curr_left=0,curr_right=lenc;
	            for(int ic=0;ic<lenc;ic++)
	            {
	                //get height
	                if (matrix[ir][ic]=='1') height[ic]++;
	                else height[ic]=0;
	                
	                // get left
	                if (matrix[ir][ic]=='1') left[ic]=max(left[ic],curr_left);
	                else {left[ic]=0; curr_left=ic+1;}
	            }
	            
	            for(int ic=lenc-1;ic>=0;ic--)  //  *** it has to be from the right to left
	            {
	                // get right
	                if (matrix[ir][ic]=='1') right[ic]=min(right[ic],curr_right);
	                else {right[ic]=lenc; curr_right=ic; }
	                
	                maxA=max(maxA,((right[ic]-left[ic])*height[ic]));
	            }
	        }
	        return maxA;
	    }
	};

}

/****************************************************************************************************
                                             Note
it is the dp problem
area = max(left) * min(right) * curr height. all these three para are inherietied from the previous 
once. So it is the global min and max on current row and colume. 
****************************************************************************************************/