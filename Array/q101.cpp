/****************************************************************************************************
                                    101. Symmetric Tree         
-----------------------------------------------------------------------------------------------------
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        //return isSym(root->left,root->right);
        queue<TreeNode*> ql,qr;
        ql.push(root->left);
        qr.push(root->right);
        while(!ql.empty() && !qr.empty())
        {
            TreeNode* left  = ql.front(); ql.pop();
            TreeNode* right = qr.front(); qr.pop();
            
            if (left==NULL && right==NULL) continue;
            if (left==NULL || right==NULL) return false;
            if (left->val != right->val) return false;
            
            ql.push(left->left); ql.push(left->right);
            qr.push(right->right); qr.push(right->left);
        }
        
        return ql.empty() && qr.empty();
    }
    
    bool isSym(TreeNode* left, TreeNode* right)
    {
        if (left==NULL && right==NULL) return true;
        if (left==NULL || right==NULL) return false;
        if (left->val != right->val)   return false;
        
        return isSym(left->left,right->right) && isSym(left->right,right->left);
    }
};

/****************************************************************************************************
                                             Note
Remember this one, I didn't know how to solve it on the first try. it very clever to use two queue
and push the node on compare order. it won't over lap. very clever. 
****************************************************************************************************/