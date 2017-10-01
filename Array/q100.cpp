/****************************************************************************************************
                                        100. Same Tree         
-----------------------------------------------------------------------------------------------------
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
        bool isSameTree(TreeNode* p, TreeNode* q) {
            return checktree(p,q);
        }
        
        bool checktree(TreeNode* p, TreeNode* q)
        {
            if (p==NULL && q==NULL) return true;
            if ((p==NULL && q!=NULL) || (p!=NULL && q==NULL)) return false;
            if (p->val!=q->val) return false;
            bool qleft = checktree(p->left,q->left);
            bool qright = checktree(p->right,q->right);
            return qleft&&qright;
        }
    };

    class Solution2 {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if (p==NULL && q==NULL) return true;
            if (p!=NULL && q!=NULL && p->val==q->val)
            {
                return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
            }
            else return false;
        }
    };

}

/****************************************************************************************************
                                             Note
there may be some improvements. but basic idea is here.

****************************************************************************************************/