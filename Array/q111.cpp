/****************************************************************************************************
                               111. Minimum Depth of Binary Tree       
-----------------------------------------------------------------------------------------------------
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the 
nearest leaf node.
****************************************************************************************************/

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
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        int left=minDepth(root->left); 
        int right=minDepth(root->right);
        return min(left>0?left:right,right>0?right:left)+1;
    }
};

/****************************************************************************************************
                                             Note
if one side is empty, it has to return the un-empty one. 
should use level travel. first node has two null children, return it's level.  
****************************************************************************************************/