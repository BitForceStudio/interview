/****************************************************************************************************
                                 199. Binary Tree Right Side View             
-----------------------------------------------------------------------------------------------------
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes 
you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
	    vector<int> rightSideView(TreeNode* root) {
	        vector<int> rst;
	        if (root==NULL) return rst;
	        queue<TreeNode*> qt;
	        qt.push(root);
	        qt.push(NULL);
	        
	        int last = 0;
	        while(!qt.empty())
	        {
	            TreeNode* tmp;
	            tmp=qt.front();
	            qt.pop();
	            if (tmp==NULL)
	            {
	                rst.push_back(last);
	                if (!qt.empty()) qt.push(NULL);
	            }
	            else
	            {
	                if(tmp->left!=NULL) qt.push(tmp->left);
	                if(tmp->right!=NULL) qt.push(tmp->right);
	                last=tmp->val;
	            }
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
nothing special
****************************************************************************************************/