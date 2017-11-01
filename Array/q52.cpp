/****************************************************************************************************
                                       52. N-Queens II      
-----------------------------------------------------------------------------------------------------
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int totalNQueens(int n) {
	        if (n<=1) return n;
	        vector<string> board(n,string(n,'.'));
	        int rst=0;
	        solver(board,0,n,rst);
	        return rst;
	    }
	    
	    void solver(vector<string>& board,int s,int t, int& rst)
	    {
	        if (s==t) 
	        {
	            rst+=1;
	            return;
	        }
	        
	        for(int col=0;col<t;col++)
	        {
	            if (isValid(board,s,col,t))
	            {
	                board[s][col]='Q';
	                solver(board,s+1,t,rst);
	                board[s][col]='.';
	            }
	        }
	    }
	    
	    bool isValid(vector<string>& board,int s,int col, int t)
	    {
	        for(int i=0;i<s;i++)
	        {
	            if (board[i][col]=='Q') return false;
	        }
	        
	        for(int i=s-1,j=col-1;i>=0 && j>=0;i--,j--)
	        {
	            if (board[i][j]=='Q') return false;
	        }
	        
	        for(int i=s-1,j=col+1;i>=0 && j<t;i--,j++)
	        {
	            if (board[i][j]=='Q') return false;
	        }
	        
	        return true;
	    }
	};

	class Solution2 {
	public:
	    int totalNQueens(int n) {
	        if (n==1) return 1;
	        if (n==2) return 0;
	        
	        vector<bool> vert(n,false);
	        vector<bool> forw(2*n-1,false);
	        vector<bool> back(2*n-1,false);
	        int rst=0;
	        
	        helper(0,n,vert,forw,back,rst);
	        return rst;
	    }
	    
	    void helper(int i, int& n, vector<bool>& vert, vector<bool>& forw, vector<bool>& back, int& rst)
	    {
	        if (i==n)
	        {
	            rst++;
	            return;
	        }
	        
	        for(int j=0;j<n;j++)
	        {
	            if (vert[j] || forw[i+j] || back[i+n-j-1]) continue;
	            vert[j]=forw[i+j]=back[i+n-j-1] = true;
	            helper(i+1,n,vert,forw,back,rst);
	            vert[j]=forw[i+j]=back[i+n-j-1] = false;
	        }
	    }
	};

}


/****************************************************************************************************
                                             Note
easy if know how to do n queens problem...
****************************************************************************************************/