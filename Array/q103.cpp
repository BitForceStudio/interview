/****************************************************************************************************
                          103. Binary Tree Zigzag Level Order Traversal             
-----------------------------------------------------------------------------------------------------
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to 
right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
	    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	        vector<vector<int> > rst;
	        if (root==NULL) return rst;
	        
	        queue<TreeNode*> qt;
	        qt.push(root); qt.push(NULL);
	        bool order=true;  // true: to right, false: to left
	        vector<int> clvl;
	        while(!qt.empty())
	        {
	            TreeNode* tmp = qt.front();
	            qt.pop();
	            if (tmp==NULL)
	            {
	                rst.push_back(clvl);
	                clvl.clear();
	                if(!qt.empty()) qt.push(NULL);
	                order=!order;
	            }
	            else
	            {
	                if(order)
	                {
	                    clvl.push_back(tmp->val);
	                }
	                else
	                {
	                    clvl.insert(clvl.begin(),tmp->val);
	                }
	                if(tmp->left) qt.push(tmp->left);
	                if(tmp->right) qt.push(tmp->right);
	            }
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
have to remember the level travel. 
****************************************************************************************************/