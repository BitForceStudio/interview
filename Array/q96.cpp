/****************************************************************************************************
                                  96. Unique Binary Search Trees           
-----------------------------------------------------------------------------------------------------
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int numTrees(int n) {
	        if(n==0 || n==1) return 1;
	        vector<int> rst(n+1,0);
	        rst[0]=1;
	        rst[1]=1;
	        for(int i=2;i<=n;i++)
	        {
	            for(int j=1;j<=i;j++)
	            {
	                //         left      right
	                rst[i] += rst[j-1]*rst[i-j]; 
	            }
	        }
	        return rst[n];
	    }
	};

	// catalan
	class Solution {
	public:
	    int numTrees(int n) {
	        if(n==0 || n==1) return 1;
	        long long rst;
	        rst=1;
	        for(int i=1;i<n;i++)
	            rst=rst*2*(2*i+1)/(i+2);  //**
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
divide and conquer. it is easy to solve if use this way. 
however, there is a quicker way, called catalan number: 
https://en.wikipedia.org/wiki/Catalan_number

** here cannot use rst*= |||  because it will calcualte the right side first and then times rst, which
could be wrong.
****************************************************************************************************/