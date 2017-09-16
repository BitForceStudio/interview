/****************************************************************************************************
                                         51. N-Queens          
-----------------------------------------------------------------------------------------------------
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens 
attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<vector<string>> solveNQueens(int n) {
	        vector<vector<string> > rst;
	        if (n==0) return rst;
	        vector<string> board(n,string(n,'.'));
	        solver(rst, board,0,n);
	        
	        return rst;
	    }
	    
	    void solver(vector<vector<string> >& rst, vector<string>& board, int s, int t)
	    {
	        if (s==t)
	        {
	            rst.push_back(board);
	            return;
	        }
	        
	        for(int col=0;col<t;col++)
	        {
	            if (isValid(board,s,col,t))
	            {
	                board[s][col]='Q';
	                solver(rst,board,s+1,t);
	                board[s][col]='.';
	            }
	        }
	    }
	    
	    bool isValid(vector<string>& board, int s, int c, int t)
	    {
	        // colume
	        for(int i=0;i<s;i++)
	        {
	            if (board[i][c]=='Q') return false;
	        }
	        
	        // 45
	        for(int i=s-1,j=c-1;i>=0 && j>=0;i--,j--)
	        {
	            if (board[i][j]=='Q') return false;
	        }
	        
	        // 135
	        for(int i=s-1,j=c+1;i>=0 && j<t; i--,j++)
	        {
	            if (board[i][j]=='Q') return false;
	        }
	        return true;
	    }
	    
	};

	class Solution {
	public:
	    vector<vector<string>> solveNQueens(int n) {
	        vector<vector<string> > rst;
	        if (n==0) return rst;
	        
	        vector<bool> vert(n,false);
	        vector<bool> fdiag(2*n-1,false);
	        vector<bool> bdiag(2*n-1,false);
	        vector<string> curr(n,string(n,'.'));
	        solver(0,n,vert,fdiag,bdiag,curr,rst);
	        
	        return rst;
	    }
	    
	    void solver(int i, int n, vector<bool>& vert, vector<bool>& fdiag, vector<bool>& bdiag, vector<string>& curr, vector<vector<string> >& rst)
	    {
	        if (i==n)
	        {
	            rst.push_back(curr);
	            return;
	        }
	        
	        for(int j=0;j<n;j++)
	        {
	            if (!vert[j] && !fdiag[n-1-i+j] && !bdiag[i+j])
	            {
	                vert[j]=fdiag[n-1-i+j]=bdiag[i+j]=true;
	                curr[i][j]='Q';
	                solver(i+1,n,vert,fdiag,bdiag,curr,rst);
	                curr[i][j]='.';
	                vert[j]=fdiag[n-1-i+j]=bdiag[i+j]=false;
	            }
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
classic n queens problem. Here is the better ones:
The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is 
also 2 * n - 1. When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and 
the 135° diagonal No. is n - 1 + col - row. We can use three arrays to indicate if the column or the 
diagonal had a queen before, if not, we can put a queen in this position and continue.

/**    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \ 
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
  */
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
};
//But we actually do not need to use three arrays, we just need one. Now, when reach [row, col], the subscript of column is col, the subscript of 45° 
//diagonal is n + row + col and the subscript of 135° diagonal is n + 2 * n - 1 + n - 1 + col - row.

class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
		std::vector<std::string> nQueens(n, std::string(n, '.'));
		/*
		flag[0] to flag[n - 1] to indicate if the column had a queen before.
		flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
		flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
		*/
		std::vector<int> flag(5 * n - 2, 1);
		solveNQueens(res, nQueens, flag, 0, n);
		return res;
    }
private:
	void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n) {
		if (row == n) {
			res.push_back(nQueens);
			return;
		}
		for (int col = 0; col != n; ++col)
			if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
				flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
				nQueens[row][col] = 'Q';
				solveNQueens(res, nQueens, flag, row + 1, n);
				nQueens[row][col] = '.';
				flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
			}
	}
};
/****************************************************************************************************/