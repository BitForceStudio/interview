/****************************************************************************************************
                                98. Validate Binary Search Tree          
-----------------------------------------------------------------------------------------------------
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
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
	    bool isValidBST(TreeNode* root) {
	        if(root==NULL) return true;
	        return isBst(root,NULL,NULL);
	    }
	    
	    bool isBst(TreeNode* root, TreeNode* rightMin, TreeNode* leftMax)
	    {
	        if (root==NULL) return true;
	        if ((leftMax && leftMax->val >= root->val) ||(rightMin && rightMin->val <= root->val)) return false;
	        
	        return isBst(root->left, root, leftMax) && isBst(root->right,rightMin ,root);
	    }
	};

}

/****************************************************************************************************
                                             Note
remember it...
****************************************************************************************************/