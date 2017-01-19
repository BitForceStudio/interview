/****************************************************************************************************
                                       79. Word Search      
-----------------------------------------------------------------------------------------------------
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{
	// naive greedy search
	class Solution {
	public:
	    bool exist(vector<vector<char>>& board, string word) {
	        int lenr = board.size();
	        if (lenr==0) return false;
	        int lenc = board[0].size();
	        if (lenc==0) return false;
	        int lenw = word.size();
	        if (lenw>lenc*lenr) return false;
	        
	        vector<vector<bool> > qused(lenr,vector<bool>(lenc,false));
	        bool qfind = true;
	        for(int i=0;i<lenr;i++)
	        {
	            for(int j=0;j<lenc;j++)
	            {
	                // found first letter
	                if (word[0]==board[i][j])
	                {
	                    qused[i][j]=true;
	                    qfind = search(board, qused, word, 1, i, j, lenr, lenc);  //**
	                    if (qfind) return true;
	                    qused[i][j]=false;
	                }
	            }
	        }
	        return false;
	    }
	    
	    bool search(vector<vector<char> >& board, vector<vector<bool> >& qused, string word, int k, int i, int j, int lenr, int lenc)
	    {
	        if (k>=word.size()) return true;
	        bool qfind = false;
	        // four different directions
	        if (i>=1 && board[i-1][j]==word[k] && !qused[i-1][j])
	        {
	            qused[i-1][j]=true;
	            qfind = search(board, qused, word, k+1, i-1, j, lenr, lenc);
	            if (qfind) return true;
	            qused[i-1][j]=false;
	        }
	        if (j>=1 && board[i][j-1]==word[k] && !qused[i][j-1])
	        {
	            qused[i][j-1]=true;
	            qfind = search(board, qused, word, k+1, i, j-1, lenr, lenc);
	            if (qfind) return true;
	            qused[i][j-1]=false;
	        }
	        if (i<lenr-1 && board[i+1][j]==word[k] && !qused[i+1][j])
	        {
	            qused[i+1][j]=true;
	            qfind = search(board, qused, word, k+1, i+1, j, lenr, lenc);
	            if (qfind) return true;
	            qused[i+1][j]=false;
	        }
	        if (j<lenc-1 && board[i][j+1]==word[k] && !qused[i][j+1])
	        {
	            qused[i][j+1]=true;
	            qfind = search(board, qused, word, k+1, i, j+1, lenr, lenc);
	            if (qfind) return true;
	            qused[i][j+1]=false;
	        }
	        return qfind;
	    }
	};

}

/****************************************************************************************************
                                             Note
** don't forgot it could be same letter sourrend the current letter, every way should be tryed. 
better solution?
****************************************************************************************************/