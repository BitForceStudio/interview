/****************************************************************************************************
                                       226. Invert Binary Tree      
-----------------------------------------------------------------------------------------------------
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

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
	/// recursively 
	class Solution {
	public:
	    TreeNode* invertTree(TreeNode* root) {
	        // level travel
	        if (root==NULL) return root;
	        if (root->left==NULL && root->right==NULL) return root;
	        
	        invert(root);
	        
	        return root;
	    }
	    
	    void invert(TreeNode* root)
	    {
	        if (root->left==NULL && root->right==NULL) return;
	        TreeNode* tmpl = root->left;
	        root->left = root->right;
	        root->right = tmpl;
	        if (root->left!=NULL)  invert(root->left);
	        if (root->right!=NULL) invert(root->right);
	        return;
	    }
	};

	/// Iteratively
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
	    TreeNode* invertTree(TreeNode* root) {
	        // level travel
	        if (root==NULL) return root;
	        if (root->left==NULL && root->right==NULL) return root;
	        
	        queue<TreeNode*> qt; qt.push(root);
	        
	        while(!qt.empty())
	        {
	            TreeNode* tmp = qt.front(); qt.pop();
	            if(tmp->left!=NULL) qt.push(tmp->left);
	            if(tmp->right!=NULL) qt.push(tmp->right);
	            
	            TreeNode* t = tmp->left;
	            tmp->left=tmp->right;
	            tmp->right=t;
	        }
	        
	        return root;
	    }
	};
}

/****************************************************************************************************
                                             Note

****************************************************************************************************/