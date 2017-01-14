/****************************************************************************************************
                                       59. Spiral Matrix II    
-----------------------------------------------------------------------------------------------------
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<vector<int>> generateMatrix(int n) {
	        vector<vector<int> > rst;
	        if (n==0) return rst;
	        if (n==1) { rst.resize(1); rst[0].resize(1,1); return rst;}
	        
	        rst.resize(n); 
	        for(int i=0;i<n;i++) rst[i].resize(n);
	        
	        int s=0,e=n-1;
	        int curr=1;
	        while(s<=e)
	        {
	            curr=orderMatrix(rst,s,e,curr);
	            ++s;
	            --e;
	        }
	        return rst;
	    }
	    
	    int orderMatrix(vector<vector<int> >& rst,int s,int e,int curr)
	    {
	        if (s<e)
	        {
	            for(int i=s;i<e;i++) rst[s][i]=curr++;
	            for(int i=s;i<e;i++) rst[i][e]=curr++;
	            for(int i=e;i>s;i--) rst[e][i]=curr++;
	            for(int i=e;i>s;i--) rst[i][s]=curr++;
	        }
	        else rst[s][s] = curr;
	        
	        return curr;
	    }
	};

}

/****************************************************************************************************
                                             Note
nothing to be said. just be careful about the s & e pointers. 
****************************************************************************************************/