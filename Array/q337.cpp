/****************************************************************************************************
                                    337. House Robber III         
-----------------------------------------------------------------------------------------------------
The thief has found himself a new place for his thievery again. There is only one entrance to this 
area, called the "root." Besides the root, each house has one and only one parent house. After a tour, 
the smart thief realized that "all houses in this place forms a binary tree". It will automatically 
contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

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
	    int rob(TreeNode* root) {
	        if (root==NULL) return 0;
	        
	        vector<int> rst=robhelper(root);
	        return max(rst[0],rst[1]);
	    }
	    
	    vector<int> robhelper(TreeNode* root)
	    {
	        vector<int> rst(2,0);
	        if (root==NULL) return rst;
	        
	        vector<int> left  = robhelper(root->left);
	        vector<int> right = robhelper(root->right);
	        
	        rst[0] = max((left[1]+right[1]),max((left[1]+right[0]),max((left[0]+right[0]),(left[0]+right[1])))); // ***
	        rst[1] = left[0]+right[0]+root->val;
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
need to consider not rob this one. and not rob its child. 
****************************************************************************************************/