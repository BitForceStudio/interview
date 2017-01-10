/****************************************************************************************************
                              107. Binary Tree Level Order Traversal II             
-----------------------------------------------------------------------------------------------------
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // use stack
        vector<vector<int> > rst;
        if (root==NULL) return rst;
        
        queue<TreeNode*> qt;
        qt.push(root); qt.push(NULL);
        vector<int> clevel;
        while(!qt.empty())
        {
            TreeNode* tmp=qt.front();
            qt.pop();
            if (tmp==NULL)
            {
                rst.push_back(clevel);
                if (qt.size()>0) qt.push(NULL);   // ***
                clevel.clear();
            }
            else
            {
                clevel.push_back(tmp->val);
                if (tmp->left!=NULL) qt.push(tmp->left);
                if (tmp->right!=NULL) qt.push(tmp->right);
            }
        }
        
        reverse(rst.begin(),rst.end());
        return rst;
    }
};

/****************************************************************************************************
                                             Note
*** need to be careful here, or it will be an infinat loop. 
****************************************************************************************************/