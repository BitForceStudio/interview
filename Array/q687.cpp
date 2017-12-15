/****************************************************************************************************
                                        687. Longest Univalue Path     
-----------------------------------------------------------------------------------------------------
Given a binary tree, find the length of the longest path where each node in the path has the same 
value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{
	
	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    int longestUnivaluePath(TreeNode* root) {
	        if(root==NULL) return 0;
	        int rst=1;
	        dfs(root,rst);
	        
	        return rst-1;
	    }
	    
	    int dfs(TreeNode* root, int& rst)
	    {
	        int maxleft=1,maxright=1;
	        
	        if(root->left) 
	        {
	            maxleft =dfs(root->left,rst);
	            maxleft =  (root->val==root->left->val)?(maxleft+1):1;
	        }
	        if(root->right)
	        {
	            maxright = dfs(root->right,rst);
	            maxright = (root->val==root->right->val)?(maxright+1):1;
	        }
	        
	        int maxforward = max(maxleft,maxright);
	        int maxcurr=0;
	        if(maxleft!=1 && maxright!=1)
	        {
	            maxcurr=maxleft+maxright-1;
	        }
	        rst=max(rst,max(maxcurr,maxforward));
	        return maxforward;
	    }
	};

}

/****************************************************************************************************
                                             Note

****************************************************************************************************/