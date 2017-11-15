/****************************************************************************************************
                                 95. Unique Binary Search Trees II          
-----------------------------------------------------------------------------------------------------
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
	    vector<TreeNode*> generateTrees(int n) {
	        vector<TreeNode*> rst;
	        if (n==0) return rst;
	        
	        return gtree(1,n);
	    }
	    
	    vector<TreeNode*> gtree(int s, int t)
	    {
	        vector<TreeNode*> rst;
	        if (s>t)
	        {
	            rst.push_back(NULL);
	            return rst;
	        }
	        
	        if (t==s) 
	        {
	            TreeNode* root = new TreeNode(t);
	            rst.push_back(root);
	            return rst;
	        }
	        
	        for(int i=s;i<=t;i++)
	        {
	            vector<TreeNode*> left=gtree(s,i-1);
	            vector<TreeNode*> right=gtree(i+1,t);
	            for(int j=0;j<left.size();j++)
	            {
	                for(int k=0;k<right.size();k++)
	                {
	                    TreeNode* root = new TreeNode(i);
	                    root->right=cloneTree(right[k]);
	                    root->left=cloneTree(left[j]);
	                    rst.push_back(root);
	                }
	            }
	        }
	        return rst;
	    }
	    
	    TreeNode* cloneTree(TreeNode* root)
	    {
	        if (root==NULL) return NULL;
	        
	        TreeNode* newRoot = new TreeNode(root->val);
	        newRoot->left=cloneTree(root->left);
	        newRoot->right=cloneTree(root->right);
	        return newRoot;
	    }
	};

	class Solution {
	public:
	    vector<TreeNode*> generateTrees(int n) {
	        vector<TreeNode*> rst;
	        if(n==0) return rst;
	        
	        TreeNode* first=new TreeNode(1);
	        rst.push_back(first);
	        for(int i=2;i<=n;i++)
	        {
	            int len = rst.size();
	            for(int j=0;j<len;j++)
	            {
	                // insert the current node to the right side
	                TreeNode* root = copytree(rst[j]);
	                TreeNode* rt=root;
	                while(rt->right!=NULL)
	                {
	                    TreeNode* rc = rt->right;
	                    TreeNode* tmp = new TreeNode(i);
	                    rt->right=tmp;
	                    tmp->left=rc;
	                    TreeNode* nt = copytree(root);
	                    rst.push_back(nt);
	                    tmp->left=NULL;
	                    rt->right=rc;
	                    rt=rt->right;
	                }
	                TreeNode* tmp = new TreeNode(i);
	                rt->right=tmp;
	                rst.push_back(root);
	                // the current tree is the new node left child
	                TreeNode* nt = new TreeNode(i);
	                nt->left=rst[j];
	                rst[j]=nt;
	            }
	        }
	        
	        return rst;
	    }
	    
	    // copy the tree
	    TreeNode* copytree(TreeNode* root)
	    {
	        if (root==NULL) return NULL;
	        TreeNode* nrt = new TreeNode(root->val);

	        TreeNode* nl = copytree(root->left);    
	        nrt->left = nl;
	        
	        TreeNode* nr = copytree(root->right);
	        nrt->right = nr;
	        
	        return nrt;
	    }
	};

}

/****************************************************************************************************
                                             Note
This can be considered as following:
1: clone tree: if find one, need to clone it 
2: function return the vector of the tree, so it could be list of left sub tree and right sub tree. 
   then conqure them together. 
3: return: if s>t, then return vector contain NULL. is s==t, return root with value s/t.
****************************************************************************************************/