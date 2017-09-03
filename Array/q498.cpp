/****************************************************************************************************
                                   498. Diagonal Traverse          
-----------------------------------------------------------------------------------------------------
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal 
order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
	        vector<int> rst;
	        int lenr = matrix.size();
	        if (lenr==0) return rst;
	        int lenc = matrix[0].size();
	        if (lenc==0) return rst;
	        
	        rst.resize(lenr*lenc,0);
	        int i=0,j=0,counter=1;
	        bool dir=false;
	        rst[0] = matrix[0][0];
	        bool qchanged = false;

	        while(counter<lenr*lenc)
	        {
	            if(i==0 && j<lenc-1 && !dir)
	            {
	                qchanged=true;
	                j++;
	                dir=true;
	            }
	            else if (j==0 && i<lenr-1 && dir)
	            {
	                qchanged=true; 
	                i++;
	                dir = false;
	            }
	            else if (i==lenr-1 && dir)
	            {
	                if(j<lenc-1) 
	                {
	                    qchanged=true;
	                    j++;
	                }
	                dir=false;
	            }
	            else if (j==lenc-1 && !dir)
	            {
	                if (i<lenr-1) 
	                {
	                    qchanged=true;
	                    i++;
	                }
	                dir = true;
	            }
	            else if (dir)
	            {
	                i++;
	                j--;
	                qchanged=true;
	            }
	            else
	            {
	                i--;
	                j++;
	                qchanged=true;
	            }
	            
	            if(qchanged)
	            {
	                rst[counter]=matrix[i][j];
	                counter++;
	                qchanged = false;
	            }
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Nothing, just need to try sometimes.
****************************************************************************************************/