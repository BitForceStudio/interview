/****************************************************************************************************
                                   94. Binary Tree Inorder Traversal          
-----------------------------------------------------------------------------------------------------
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

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
	class ReSolution {
	public:
	    vector<int> inorderTraversal(TreeNode* root) {
	        vector<int> rst;
	        if (root==NULL) return rst;
	        inOrder(root,rst);
	        return rst;
	    }
	    
	    void inOrder(TreeNode* root, vector<int>& rst)
	    {
	        if (root->left!=NULL) inOrder(root->left,rst);
	        rst.push_back(root->val);
	        if(root->right!=NULL) inOrder(root->right,rst);
	    }
	};

	class Solution {
	public:
	    vector<int> inorderTraversal(TreeNode* root) {
	        vector<int> rst;
	        if(root==NULL) return rst;

	        unordered_set<TreeNode*> qvisited;
	        stack<TreeNode*> st;
	        st.push(root);
	        while(!st.empty())
	        {
	            TreeNode* curr = st.top();
	            if(qvisited.find(curr)!=qvisited.end())
	            {
	                rst.push_back(curr->val);
	                st.pop();
	            }
	            else
	            {
	                st.pop();
	                if(curr->right) st.push(curr->right);
	                st.push(curr);
	                qvisited.insert(curr);
	                if(curr->left) st.push(curr->left);
	            }
	        }
	        
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
Recursive is easy. How to do the iter? 

iter: 
Stack and a set to store the visited roots. 
****************************************************************************************************/