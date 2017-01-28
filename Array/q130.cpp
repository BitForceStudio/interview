/****************************************************************************************************
                                    130. Surrounded Regions         
-----------------------------------------------------------------------------------------------------
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    void solve(vector<vector<char>>& board) {
	        int ilen = board.size();
	        if (ilen==0) return;
	        int jlen = board[0].size();
	        if (jlen==0) return;
	        
	        for(int i=0;i<ilen;i++)
	        {
	            change(board,i,0,ilen-1,jlen-1);
	            if (jlen>1)
	                change(board,i,jlen-1,ilen-1,jlen-1);  // **
	        }
	        
	        for(int j=0;j<jlen;j++)
	        {
	            change(board,0,j,ilen-1,jlen-1);
	            if (ilen>1)
	                change(board,ilen-1,j,ilen-1,jlen-1);
	        }
	        
	        // change all 'O' to 'X' and change 'A' to 'O'
	        for(int i=0;i<ilen;i++)
	        {
	            for(int j=0;j<jlen;j++)
	            {
	                if (board[i][j]=='O') board[i][j] = 'X';
	                if (board[i][j]=='A') board[i][j] = 'O';
	            }
	        }
	    }
	    
	    void change(vector<vector<char> >& board, int ith, int jth, int ilen, int jlen)
	    {
	        if (board[ith][jth]=='O')
	        {
	            board[ith][jth]='A';
	            if(ith>1)
	            {
	                change(board,ith-1,jth,ilen,jlen);
	            }
	            if(ith<ilen)
	            {
	                change(board,ith+1,jth,ilen,jlen);
	            }
	            if(jth>1)
	            {
	                change(board,ith,jth-1,ilen,jlen);
	            }
	            if(jth<jlen)
	            {
	                change(board,ith,jth+1,ilen,jlen);
	            }
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
get this idea from others, it was really good. However, the oj didn't happy in don't why...
** i found why.. it better be < not <=. just use -1.
****************************************************************************************************/