/****************************************************************************************************
                                  257. Binary Tree Paths           
-----------------------------------------------------------------------------------------------------
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
	    vector<string> binaryTreePaths(TreeNode* root) {
	        vector<string> rst;
	        if (root==NULL) return rst;
	        
	        string curr=to_string(root->val);
	        treePath(root,curr,rst);
	        return rst;
	    }
	    
	    void treePath(TreeNode* root, string curr, vector<string>& rst)
	    {
	        if (root->left==NULL && root->right==NULL)
	        {
	            rst.push_back(curr);
	            return;
	        }
	        
	        if (root->left)
	        {
	            treePath(root->left,curr+"->"+to_string(root->left->val),rst);  // **
	        }
	        if (root->right)
	        {
	            treePath(root->right,curr+"->"+to_string(root->right->val),rst);
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
** the string can be changed here.
****************************************************************************************************/