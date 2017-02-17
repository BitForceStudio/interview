/****************************************************************************************************
                                       447. Number of Boomerangs      
-----------------------------------------------------------------------------------------------------
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points 
(i, j, k) such that the distance between i and j equals the distance between i and k (the order of 
the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points 
are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int numberOfBoomerangs(vector<pair<int, int>>& points) {
	        int len=points.size();
	        if (len==0) return 0;
	        
	        int rst=0;
	        for(int i=0;i<len;i++)
	        {
	            map<int,int> distmap;
	            for(int j=0;j<len;j++)
	            {
	                if (i==j) continue;
	                distmap[getdist(points[i],points[j])]++;
	            }
	            for(map<int,int>::iterator it=distmap.begin();it!=distmap.end();it++)
	            {
	                if (it->second>=2) rst+=it->second*(it->second-1);
	            }
	        }
	        return rst;
	    }
	    
	    int getdist(pair<int,int> i, pair<int,int> j)
	    {
	        int a=i.first-j.first;
	        int b=i.second-j.second;
	        return a*a+b*b;
	    }
	};

}

/****************************************************************************************************
                                             Note
The improvement is the reduce the recalculation of the distance. 
****************************************************************************************************/