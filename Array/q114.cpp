/****************************************************************************************************
                            114. Flatten Binary Tree to Linked List                 
-----------------------------------------------------------------------------------------------------
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a 
pre-order traversal.

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
	    void flatten(TreeNode* root) {
	        if (root==NULL) return;
	        TreeNode* tmp = ftree(root);
	    }
	    
	    TreeNode* ftree(TreeNode* root)
	    {
	        if (root->left==NULL && root->right==NULL) return root;  // leaf
	        
	        TreeNode* rrt = root->right;                             // keep right
	        
	        if (root->left!=NULL)                                    // set the left side to right
	        {
	            root->right=root->left; root->left=NULL; 
	            root = root->right;                                  // go to left which copied to the right
	            root = ftree(root);
	        }
	        else                                                     // if there is no left, keep right
	            rrt=NULL;
	    
	        if (rrt!=NULL)                               
	            root->right=rrt;
	            
	        if (root->right!=NULL)                                  // keep doing right part
	        {
	            root=root->right;
	            root = ftree(root);
	        }
	        
	        return root;
	    }
	};

}

/****************************************************************************************************
                                             Note
need some clear head...
****************************************************************************************************/