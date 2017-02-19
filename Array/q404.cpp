/****************************************************************************************************
                                    404. Sum of Left Leaves         
-----------------------------------------------------------------------------------------------------
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
	    int sumOfLeftLeaves(TreeNode* root) {
	        if (root==NULL) return 0;
	        int rst=0;
	        helper(root,rst);
	        return rst;
	    }
	    
	    void helper(TreeNode* root, int& rst)
	    {
	        if (root->left!=NULL  && root->left->left==NULL && root->left->right==NULL)
	        {
	            rst+=root->left->val; // ***
	        }
	        else if (root->left!=NULL) helper(root->left,rst);
	        if (root->right!=NULL) helper(root->right,rst);
	    }
	};

}

/****************************************************************************************************
                                             Note
*** should not return here...

****************************************************************************************************/