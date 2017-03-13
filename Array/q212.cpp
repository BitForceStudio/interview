/****************************************************************************************************
                                     212. Word Search II        
-----------------------------------------------------------------------------------------------------
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
those horizontally or vertically neighboring. The same letter cell may not be used more than once in 
a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class MySolution {
	public:
	    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	        // back tracking
	        vector<string> rst;
	        int lenr = board.size();
	        if (lenr==0) return rst;
	        int lenc = board[0].size();
	        if (lenc==0) return rst;
	        bool qfound=false;
	        for(int iw=0;iw<words.size();iw++)
	        {
	            qfound =false;
	            for(int i=0;i<lenr;i++)
	            {
	                for(int j=0;j<lenc;j++)
	                {
	                    if (board[i][j]==words[iw][0])
	                    {
	                        board[i][j]+=27;
	                        qfound = helper(board,words[iw],rst,1,i,j,lenr,lenc);
	                        board[i][j]-=27;
	                        if (qfound) break;
	                    }
	                }
	                if (qfound) break;
	            }
	        }
	        return rst;
	    }
	    
	    bool helper(vector<vector<char>>& board, string word, vector<string>& rst, int index, int i, int j, int lenr, int lenc)
	    {
	        if (word.size()==index)
	        {
	            if (find(rst.begin(),rst.end(),word)==rst.end()) rst.push_back(word);
	            return true;
	        }
	        bool qfound = false;
	        if (i+1<lenr && board[i+1][j]==word[index])
	        {
	            board[i+1][j]+=27;
	            qfound = helper(board,word,rst,index+1,i+1,j,lenr,lenc);
	            board[i+1][j]-=27;
	        }
	        if (qfound) return qfound;
	        if (i-1>=0 && board[i-1][j]==word[index])
	        {
	            board[i-1][j]+=27;
	            qfound = helper(board,word,rst,index+1,i-1,j,lenr,lenc);
	            board[i-1][j]-=27;
	        }
	        if (qfound) return qfound;
	        if (j+1<lenc && board[i][j+1]==word[index])
	        {
	            board[i][j+1]+=27;
	            qfound = helper(board,word,rst,index+1,i,j+1,lenr,lenc);
	            board[i][j+1]-=27;
	        }
	        if (qfound) return qfound;
	        if (j-1>=0 && board[i][j-1]==word[index])
	        {
	            board[i][j-1]+=27;
	            qfound = helper(board,word,rst,index+1,i,j-1,lenr,lenc);
	            board[i][j-1]-=27;
	        }
	        return qfound;
	    }
	};

	class TrieSolution {
	private:
	    struct TrieNode{
	      vector<TrieNode*> next;
	      string word;
	      TrieNode(string word): word(word), next(26) {}
	    };
	    
	    TrieNode* buildTrieTree(vector<string> words)
	    {
	        TrieNode* root = new TrieNode("");
	        for(string w:words)
	        {
	            TrieNode *p=root;
	            for(char c:w)
	            {
	                int ic = c-'a';
	                if ( p->next[ic]==NULL ) p->next[ic]=new TrieNode("");
	                p=p->next[ic];
	            }
	            p->word=w;
	        }
	        return root;
	    }

	public:
	    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
	        // back tracking
	        vector<string> rst;
	        int lenr = board.size();
	        if (lenr==0) return rst;
	        int lenc = board[0].size();
	        if (lenc==0) return rst;
	        
	        TrieNode* root = buildTrieTree(words);

	        for(int i=0;i<lenr;i++)
	        {
	            for(int j=0;j<lenc;j++)
	            {
	                helper(board,root,rst,i,j,lenr,lenc);
	            }

	        }

	        return rst;
	    }
	    
	    void helper(vector<vector<char>>& board, TrieNode* p, vector<string>& rst, int i, int j, int lenr, int lenc)
	    {
	        char c = board[i][j];
	        
	        if (c=='*' || p->next[c-'a']==NULL) return;
	        p=p->next[c-'a'];
	        if(p->word!="") 
	        {
	            rst.push_back(p->word);
	            p->word=""; // remove duplicate
	        }
	        
	        board[i][j] = '*';
	        if (i > 0) helper(board ,p, rst, i-1, j,lenr, lenc); 
	        if (j > 0) helper(board, p, rst, i, j-1,lenr, lenc);
	        if (i < lenr-1) helper(board, p, rst, i+1, j,lenr, lenc); 
	        if (j < lenc-1) helper(board, p, rst, i, j+1,lenr, lenc); 
	        board[i][j] = c;
	    }
	};
}

/****************************************************************************************************
                                             Note
** Trie tree, acturall, it search the tree on board. 
****************************************************************************************************/