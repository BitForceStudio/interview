/****************************************************************************************************
                             145. Binary Tree Postorder Traversal             
-----------------------------------------------------------------------------------------------------
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].
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
	class RecursiveSolution {
	public:
	    vector<int> postorderTraversal(TreeNode* root) {
	        vector<int> rst;
	        if(root==NULL) return rst;
	        helper(root,rst);
	        return rst;
	    }
	    
	    void helper(TreeNode* root, vector<int>& rst)
	    {
	        if (root->left) helper(root->left,rst);
	        if (root->right) helper(root->right,rst);
	        rst.push_back(root->val);
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
	class Iterative_Solution {
	public:
	    vector<int> postorderTraversal(TreeNode* root) {
	        vector<int> rst;
	        if(root==NULL) return rst;
	        
	        vector<TreeNode*> st;
	        vector<TreeNode*> tmp;
	        st.push_back(root);
	        while(!st.empty())
	        {
	            TreeNode* curr=st.back();
	            if (curr==NULL)  // restore
	            {
	                rst.push_back(tmp.back()->val);
	                tmp.pop_back();
	                st.pop_back();
	            }
	            else if (curr->left==NULL && curr->right==NULL)  // leaf
	            {
	                rst.push_back(curr->val);
	                st.pop_back();
	            }
	            else
	            {
	                st.back()=NULL;
	                tmp.push_back(curr);
	                if (curr->right) st.push_back(curr->right);
	                if (curr->left) st.push_back(curr->left);
	            }
	        }
	        
	        while(!tmp.empty())
	        {
	            rst.push_back(tmp.back()->val);
	            tmp.pop_back();
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note

****************************************************************************************************/