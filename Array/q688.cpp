/****************************************************************************************************
                              688. Knight Probability in Chessboard              
-----------------------------------------------------------------------------------------------------
On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K 
moves. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right 
square is (N-1, N-1).

A chess knight has 8 possible moves it can make, as illustrated below. Each move is two squares in 
a cardinal direction, then one square in an orthogonal direction.


Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even 
if the piece would go off the chessboard) and moves there.

The knight continues moving until it has made exactly K moves or has moved off the chessboard. 
Return the probability that the knight remains on the board after it has stopped moving.

Example:
Input: 3, 2, 0, 0
Output: 0.0625
Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
From each of those positions, there are also two moves that will keep the knight on the board.
The total probability the knight stays on the board is 0.0625.
Note:
N will be between 1 and 25.
K will be between 0 and 100.
The knight always initially starts on the board.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    double knightProbability(int N, int K, int r, int c) {
	        if (K==0) return 1;
	        if(N<=2) return 0;
	        vector<vector<int> > step={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
	        vector<vector<double> > dp0(N, vector<double>(N,1) );
	        for(int ik=0;ik<K;ik++)
	        {
	            vector<vector<double> > dp1(N,vector<double>(N,0));
	            for(int i=0;i<N;i++)
	            {
	                for(int j=0;j<N;j++)
	                {
	                    for(int s=0;s<8;s++)
	                    {
	                        if ((i+step[s][0])>=0 && (i+step[s][0])<N && (j+step[s][1])>=0 && (j+step[s][1])<N)
	                        {
	                            dp1[i+step[s][0]][j+step[s][1]]+=dp0[i][j];
	                        }
	                    }
	                }
	            }
	            dp0=dp1;
	        }
	        
	        return dp0[r][c]/pow(8,K);
	    }
	};

}

/****************************************************************************************************
                                             Note
dp problem, need to understand this kind of problem
****************************************************************************************************/