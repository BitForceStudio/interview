/****************************************************************************************************
                                    110. Balanced Binary Tree         
-----------------------------------------------------------------------------------------------------
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of 
the two subtrees of every node never differ by more than 1.
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
#include "problems\problems\Header.h"

namespace std
{
    class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            if (root == NULL) return true;
            int rst = htree(root);
            return rst!=-1;
        }
        
        int htree(TreeNode* nt)
        {
            if (nt==NULL) return 0;
            int left = htree(nt->left);  // here should be +1.
            int right=htree(nt->right);
            
            if (left!=-1 && right != -1 && abs(left-right)<=1) return max(left,right)+1;
            else return -1;
        }
    };

    class Solution2 {
    public:
        bool isBalanced(TreeNode* root) {
            if (root==NULL) return true;
            
            return helper(root)>=0;
        }
        
        int helper(TreeNode* root)
        {
            if (root==NULL) return 0;
            int dleft = helper(root->left);
            if (dleft==-1) return -1;
            int dright = helper(root->right);
            if (dright==-1) return -1;
            if (abs(dleft-dright)>1) return -1;
            
            return (dleft>dright?dleft:dright)+1;
        }
    };
}
/****************************************************************************************************
                                             Note
just remember do not plus 1 on that place. or it wont be -1...
****************************************************************************************************/