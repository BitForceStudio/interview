/****************************************************************************************************
                               144. Binary Tree Preorder Traversal             
-----------------------------------------------------------------------------------------------------
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
	class RecursionSolution {
	public:
	    vector<int> preorderTraversal(TreeNode* root) {
	        vector<int> rst;
	        if (root==NULL) return rst;
	        preorder(root,rst);
	        return rst;
	    }
	    
	    void preorder(TreeNode* root, vector<int>& rst)
	    {
	        if (root==NULL) return;
	        rst.push_back(root->val);
	        preorder(root->left,rst);
	        preorder(root->right,rst);
	    }
	};

	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	class IterativeSolution {
	public:
	    vector<int> preorderTraversal(TreeNode* root) {
	        vector<int> rst;
	        if (root==NULL) return rst;
	        vector<TreeNode*> st;
	        st.push_back(root);
	        
	        while(!st.empty())
	        {
	            TreeNode* curr = st.back();
	            st.pop_back();
	            rst.push_back(curr->val);
	            if(curr->right!=NULL) st.push_back(curr->right);   // ***
	            if (curr->left!=NULL) st.push_back(curr->left);    // ***
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
***: becuase uses stack, so it should push right first then left. 
****************************************************************************************************/