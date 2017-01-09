/****************************************************************************************************
                                102. Binary Tree Level Order Traversal             
-----------------------------------------------------------------------------------------------------
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > rst;
        if (root==NULL) return rst;
        if (root->left==NULL && root->right==NULL) 
        {
            vector<int> tmp; 
            tmp.push_back(root->val); 
            rst.push_back(tmp); 
            return rst;
        }
        
        queue<TreeNode*> qt;
        qt.push(root); qt.push(NULL);
        vector<int> levelvec;
        while(!qt.empty())
        {
            TreeNode* tmp = qt.front();
            qt.pop();
            if (tmp==NULL)                            // end of the current level
            {
                rst.push_back(levelvec);
                levelvec.clear();
                if (qt.size()>0) qt.push(NULL);  // end of child of current level 
            }
            else
            {
                levelvec.push_back(tmp->val);
                if (tmp->left!=NULL) qt.push(tmp->left);
                if (tmp->right!=NULL) qt.push(tmp->right);
            }
        }
        
        return rst;
    }
};

/****************************************************************************************************
                                             Note
This is the basic way to travel binary tree on level order. remember to use queue and some thing like
NULL as separator/ indice. 

****************************************************************************************************/