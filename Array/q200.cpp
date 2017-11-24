/****************************************************************************************************
                                     200. Number of Islands        
-----------------------------------------------------------------------------------------------------
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is 
surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may 
assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int numIslands(vector<vector<char>>& grid) {
	        // find a 1 and label it and its island to 2, then continue find 1, label it 3,...,n+1, return n
	        int rlen=grid.size();
	        if(rlen==0) return 0;
	        int clen=grid[0].size();
	        if (clen==0) return 0;
	        
	        int label = 0;
	        for(int i=0;i<rlen;i++)
	        {
	            for(int j=0;j<clen;j++)
	            {
	                if (grid[i][j]=='1')
	                {
	                    mark(grid,i,j,rlen,clen);
	                    label++;
	                }
	            }
	        }
	        return label;
	    }
	    
	    void mark(vector<vector<char> >& grid, int i, int j, int rl, int cl)
	    {
	        
	        grid[i][j]='A';
	        if (i+1<rl && grid[i+1][j]=='1') mark(grid,i+1,j,rl,cl);
	        if (i-1>=0 && grid[i-1][j]=='1') mark(grid,i-1,j,rl,cl);
	        if (j+1<cl && grid[i][j+1]=='1') mark(grid,i,j+1,rl,cl);
	        if (j-1>=0 && grid[i][j-1]=='1') mark(grid,i,j-1,rl,cl);
	    }
	};

	class Solution2 {
	public:
	    int numIslands(vector<vector<char>>& grid) {
	        int lenr = grid.size();
	        if(lenr==0) return 0;
	        int lenc = grid[0].size();
	        if(lenc==0) return 0;
	        int rst=0;
	        for(int i=0;i<lenr;i++)
	        {
	            for(int j=0;j<lenc;j++)
	            {
	                if(grid[i][j]=='1')
	                {
	                    rst++;
	                    markisland(grid,i,j,lenr,lenc);
	                }
	            }
	        }
	        return rst;
	    }
	    
	    void markisland(vector<vector<char> >& grid, int i, int j, int lenr, int lenc)
	    {
	        if(i<0 || i>=lenr || j<0 || j>=lenc || grid[i][j]=='0' || grid[i][j]=='*') return;
	        grid[i][j]='*';
	        markisland(grid,i-1,j,lenr,lenc);
	        markisland(grid,i,j-1,lenr,lenc);
	        markisland(grid,i+1,j,lenr,lenc);
	        markisland(grid,i,j+1,lenr,lenc);
    }
	};

}

/****************************************************************************************************
                                             Note
Nothing special. it just need a mark that not '1'. 
****************************************************************************************************/