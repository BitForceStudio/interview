/****************************************************************************************************
                                      120. Triangle         
-----------------------------------------------------------------------------------------------------
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent 
numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of 
rows in the triangle.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int minimumTotal(vector<vector<int>>& triangle) {
	        if (triangle.size()==0) return 0;
	        if (triangle.size()==1 && triangle[0].size()<=0) return 0;
	        
	        int len = triangle.size();
	        vector<int> rst(len,0);
	        rst[0] = triangle[0][0];
	        for(int i=1;i<len;i++)
	        {
	            vector<int> tmp=rst;
	            for(int j=0;j<=i;j++)
	            {
	                if (j==0) rst[j]+=triangle[i][0];
	                else if(j==i) rst[j]=tmp[j-1]+triangle[i][j];
	                else rst[j]=(tmp[j-1]>tmp[j]?tmp[j]:tmp[j-1])+triangle[i][j];
	            }
	        }
	        
	        int min = 2147483647;
	        for(int i=0;i<len;i++)
	        {
	            if(rst[i]<min) min=rst[i];
	        }
	        
	        return min;
	    }
	};


	class BetterSolution {
	public:
	    int minimumTotal(vector<vector<int>>& triangle) {
	        if (triangle.size()==0) return 0;
	        if (triangle.size()==1 && triangle[0].size()<=0) return 0;
	        
	        int len = triangle.size();
	        vector<int> rst(triangle.back()); // init the rst as the bottom vector
	        
	        for(int i=len-2;i>=0;i--)
	        {
	            for(int j=0;j<=i;j++)
	            {
	                rst[j] = triangle[i][j]+min(rst[j],rst[j+1]);
	            }
	        }
	        
	        return rst[0];
	    }
	};

}

/****************************************************************************************************
                                             Note
Not best solution. best one is from bottom to top.
same idea. 
****************************************************************************************************/