/****************************************************************************************************
                                 99. Recover Binary Search Tree   
-----------------------------------------------------------------------------------------------------
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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

	    TreeNode* first = NULL;  // biger than previous
	    TreeNode* second = NULL; // smaller than previous
	    TreeNode* previous = new TreeNode(-2147483648); 

	    void recoverTree(TreeNode* root) {
	        traversal(root);
	        
	        int tmp = first->val;
	        first->val=second->val;
	        second->val=tmp;
	        return;
	    }
	    
	    void traversal(TreeNode* root)
	    {
	        if (root==NULL) return;
	        // left
	        traversal(root->left);
	        
	        if (first==NULL && previous->val>root->val) first=previous;
	        if (first!=NULL && previous->val>root->val) second=root;
	        if (first!=NULL && second!=NULL && root->val > first->val) return;   // ***
	        previous=root;

	        traversal(root->right);
	    }
	};

}

/****************************************************************************************************
                                             Note
Simple in-order traversal. The catch is ***, stop traversal when no possible that after can swap. 
The other one is mirror traversal, understand it. 
****************************************************************************************************/