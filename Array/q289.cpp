/****************************************************************************************************
                                    289. Game of Life             
-----------------------------------------------------------------------------------------------------
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular 
automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell 
interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules 
(taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot 
update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which 
would cause problems when the active area encroaches the border of the array. How would you address 
these problems?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    void gameOfLife(vector<vector<int>>& board) {
	        int lenr = board.size();
	        if (lenr==0) return;
	        int lenc = board[0].size();
	        if (lenc==0) return;
	        
	        for(int i=0;i<lenr;i++)
	        {
	            for(int j=0;j<lenc;j++)
	            {
	                int nlives=0;
	                if (i>0 && board[i-1][j]%10==1) nlives++;
	                if (j>0 && board[i][j-1]%10==1) nlives++;
	                if (i>0 && j>0 && board[i-1][j-1]%10==1) nlives++;
	                if (i<lenr-1 && board[i+1][j]%10==1) nlives++;
	                if (j<lenc-1 && board[i][j+1]%10==1) nlives++;
	                if (i<lenr-1 && j<lenc-1 && board[i+1][j+1]%10==1) nlives++;
	                if (i>0 && j<lenc-1 && board[i-1][j+1]%10==1) nlives++;
	                if (i<lenr-1 && j>0 && board[i+1][j-1]%10==1) nlives++;
	                
	                if (board[i][j]==1 && nlives<=3 && nlives>=2) board[i][j]+=10;
	                if (board[i][j]==0 && nlives==3) board[i][j]+=10;
	            }
	        }
	        
	        for(int i=0;i<lenr;i++)
	        {
	            for(int j=0;j<lenc;j++)
	            {
	                board[i][j]/=10;
	            }
	        }
	    }

	    void check(int i,int j,int lenr, int lenc,vector<vector<int>>& board)
	    {
	        int sum=((i-1)>=0?(board[i-1][j]%10):0)                   // top
	               +(((i-1)>=0 && (j-1)>=0)?(board[i-1][j-1]%10):0)   // top left
	               +(((i-1)>=0 && (j+1)<lenc)?(board[i-1][j+1]%10):0) // top right
	               +((j-1)>=0?(board[i][j-1]%10):0)                   // left
	               +((j+1)<lenc?board[i][j+1]:0)                      // right
	               +(((i+1)<lenr && (j-1)>=0)?board[i+1][j-1]:0)      // bottom left
	               +((i+1)<lenr?board[i+1][j]:0)                      // bottom
	               +(((i+1)<lenr && (j+1)<lenc)?board[i+1][j+1]:0);   // bottom right
	        
	        if (sum==2) board[i][j]*=11;
	        else if (sum==3) board[i][j]+=10;
	    }
	};

}

/****************************************************************************************************
                                             Note
use 10s as the second status

****************************************************************************************************/