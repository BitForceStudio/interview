/****************************************************************************************************
                                     174. Dungeon Game       
-----------------------------------------------------------------------------------------------------
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially 
positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health 
point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering 
these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or 
downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the 
princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he 
follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right 
room where the princess is imprisoned.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int calculateMinimumHP(vector<vector<int>>& dungeon) {
	        int lenr = dungeon.size();
	        if (lenr==0) return 1;
	        int lenc = dungeon[0].size();
	        if (lenc==0) return 1;
	        
	        vector<vector<int> > minhp(lenr+1,vector<int>(lenc+1,INT_MAX));
	        minhp[lenr][lenc-1]=1;
	        minhp[lenr-1][lenc]=1;
	        
	        for(int i=lenr-1;i>=0;i--)
	        {
	            for(int j=lenc-1;j>=0;j--)
	            {
	                int curr = min(minhp[i][j+1],minhp[i+1][j])-dungeon[i][j];
	                minhp[i][j] = curr<=0?1:curr;
	            }
	        }
	        return minhp[0][0];
	    }
	};

	class Solution2 {
	public:
	    int calculateMinimumHP(vector<vector<int>>& dungeon) {
	        int lenr = dungeon.size();
	        if (lenr==0) return 1;
	        int lenc = dungeon[0].size();
	        if (lenc==0) return 1;
	        
	        vector<int> minhp(lenc,0);
	        vector<int> curr(lenc,0);

	        // last row
	        minhp[lenc-1] = dungeon[lenr-1][lenc-1]>=0?1:(1-dungeon[lenr-1][lenc-1]);
	        
	        for(int i=lenc-2;i>=0;i--)
	        {
	            int tmp = minhp[i+1]-dungeon[lenr-1][i];
	            minhp[i] = tmp>0?tmp:1;
	        }
	        
	        for(int i=lenr-2;i>=0;i--)
	        {
	            int tmp = minhp[lenc-1]-dungeon[i][lenc-1];
	            minhp[lenc-1]=tmp>0?tmp:1;
	            for(int j=lenc-2;j>=0;j--)
	            {
	                int tmp = min(minhp[j],minhp[j+1])-dungeon[i][j];
	                minhp[j]=tmp>0?tmp:1;
	            }
	        }
	        
	        return minhp[0];
	    }
	};

}

/****************************************************************************************************
                                             Note
minhp[i][j] represents the min hp needed at position (i, j)
Add dummy row and column at bottom and right side
idea is from right bottom to the left top and dungeon blood reverse. 

solution2, space save
****************************************************************************************************/