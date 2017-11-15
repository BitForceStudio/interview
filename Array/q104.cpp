/****************************************************************************************************
                                104. Maximum Depth of Binary Tree          
-----------------------------------------------------------------------------------------------------
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the 
farthest leaf node.
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
        int maxDepth(TreeNode* root) {
            if (root==NULL) return 0;
            if (root->left==NULL && root->right==NULL) return 1;
            
            int rst = maxdp(root);
            return rst;
        }
        
        int maxdp(TreeNode* tnode)
        {
            if (tnode==NULL) return 0;
            int dpleft = maxdp(tnode->left);
            int dpright=maxdp(tnode->right);
            return dpleft>dpright?(dpleft+1):(dpright+1); // cannot use function twice. that was stupic
        }
    };

    class Solution2 {
    public:
        int maxDepth(TreeNode* root) {
            if (root==NULL) return 0;
            
            return max(maxDepth(root->left),maxDepth(root->right))+1;
        }
    };
}
/****************************************************************************************************
                                             Note
Nothing to say really. just don't be stupid...
****************************************************************************************************/