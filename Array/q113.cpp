/****************************************************************************************************
                                   113. Path Sum II          
-----------------------------------------------------------------------------------------------------
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
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
	    vector<vector<int>> pathSum(TreeNode* root, int sum) {
	        vector<vector<int> > rst;
	        if (root==NULL) return rst;
	        
	        vector<int> curr;
	        int csum=0;
	        getPath(root, rst, curr, csum, sum);
	        
	        return rst;
	    }
	    
	    void getPath(TreeNode* root, vector<vector<int> >& rst, vector<int>& curr, int csum, int sum)
	    {
	        curr.push_back(root->val);
	        csum+=root->val;
	        if (root->left==NULL && root->right==NULL)
	        {
	            if (csum==sum)
	                rst.push_back(curr);
	            return;
	        }

	        if (root->left!=NULL)
	        {
	            getPath(root->left,rst,curr,csum,sum);
	            curr.pop_back();
	        }

	        if (root->right!=NULL)
	        {
	            getPath(root->right,rst,curr,csum,sum);
	            curr.pop_back();
	        }
	        return;
	    }
	};

}

/****************************************************************************************************
                                             Note
it could be negtive, so be carefull about this
****************************************************************************************************/