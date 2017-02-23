/****************************************************************************************************
                                 37. Sudoku Solver            
-----------------------------------------------------------------------------------------------------
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    void solveSudoku(vector<vector<char>>& board) {
	        helper(board,0,0)+'0';
	    }
	    
	    bool helper(vector<vector<char>>& board, int r, int c)
	    {
	        for(int i=r;i<9;i++)
	        {
	            for(int j=(i==r?c:0);j<9;j++) // ****
	            {
	                if (board[i][j]=='.')
	                {
	                    vector<char> poss = possibleSolution(board,i,j);
	                    if (poss.size()==0) return false;
	                    
	                    for(int ip=0;ip<poss.size();ip++)
	                    {
	                        board[i][j]=poss[ip];
	                        if (i==8 && j==8) return true;
	                        
	                        bool qfound=false;
	                        if (j<8)
	                        {
	                            qfound=helper(board,i,j+1);
	                        }
	                        else
	                        {
	                            qfound=helper(board,i+1,0);
	                        }
	                        
	                        if (qfound) return true;
	                    }
	                    
	                    board[i][j]='.';
	                    return false;
	                }
	            }
	        }
	        return true;
	    }
	    
	    vector<char> possibleSolution(vector<vector<char>>& board, int i, int j)
	    {
	        vector<int> poss(9,0);
	        
	        // 3*3 block
	        int sr=(i/3)*3;
	        int sc=(j/3)*3;
	        for(int ii=sr;ii<sr+3;ii++)
	        {
	            for(int jj=sc;jj<sc+3;jj++)
	            {
	                if (board[ii][jj]!='.') poss[board[ii][jj]-'1']--;
	            }
	        }
	        
	        for(int ii=0;ii<9;ii++)
	        {
	            if (board[ii][j]!='.' && poss[board[ii][j]-'1']==0) poss[board[ii][j]-'1']--;
	        }
	        
	        for(int jj=0;jj<9;jj++)
	        {
	            if (board[i][jj]!='.' && poss[board[i][jj]-'1']==0) poss[board[i][jj]-'1']--;
	        }
	        
	        vector<char> rst;

	        for(int i=0;i<9;i++)
	        {
	            if (poss[i]==0)
	                rst.push_back(i+'1');
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
backtracking...
**** if to the next row, it should from the start...
****************************************************************************************************/