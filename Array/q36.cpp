/****************************************************************************************************
                                         36. Valid Sudoku    
-----------------------------------------------------------------------------------------------------
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
****************************************************************************************************/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row
        vector<bool> nine; nine.resize(9,false);
        for(int i=0;i<9;i++)
        {
            nine.resize(9,false);
            for(int j=0;j<9;j++)
            {
                if (board[i][j]=='.') continue;
                if (nine[board[i][j]-'1']) return false;
                nine[board[i][j]-'1']=true;
            }
            nine.clear();
        }
        nine.clear();
        
        // colume
        for(int j=0;j<9;j++)
        {
            nine.resize(9,false);
            for(int i=0;i<9;i++)
            {
                if (board[i][j]=='.') continue;
                if (nine[board[i][j]-'1']) return false;
                nine[board[i][j]-'1']=true;
            }
            nine.clear();
        }
        nine.clear();
        
        // cell
        for(int i=0;i<9;i+=3)
        {
            for(int j=0;j<9;j+=3)
            {
                nine.resize(9,false);
                for(int k=i;k<i+3;k++)
                {
                    for(int n=j;n<j+3;n++)
                    {
                        if (board[k][n]=='.') continue;
                        if (nine[board[k][n]-'1']) return false;
                            nine[board[k][n]-'1']=true;
                    }
                }
                nine.clear();
            }
        }
        
        return true;
    }
};

/****************************************************************************************************
                                             Note
vector resize (reset) problem
vector firstly need to be clear then resize.

****************************************************************************************************/