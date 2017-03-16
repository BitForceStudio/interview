/****************************************************************************************************
                                124. Binary Tree Maximum Path Sum             
-----------------------------------------------------------------------------------------------------
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in 
the tree along the parent-child connections. The path must contain at least one node and does not 
need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
	    int maxPathSum(TreeNode* root) {
	        int currmax=-2147483648;
	        int rstmax = helper(root,currmax);
	        return max(rstmax,currmax);
	    }
	    
	    // return the max of current val + left or current val + right. 
	    int helper(TreeNode* root, int& currmax)
	    {
	        int left = 0;
	        if (root->left!=NULL) left=helper(root->left,currmax);
	        int right = 0;
	        if(root->right!=NULL) right=helper(root->right,currmax);
	        
	        int rst = max(root->val+right,max(root->val,root->val+left));
	        currmax = max(currmax,max(rst,right+root->val+left));
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
get this idea from the solution. from bottom to top and keep two maximums for each node:
1: max of the left+curr, right+curr
2: max of the left+curr+right,curr,left+curr,right+curr (all posibilities)

****************************************************************************************************/