/****************************************************************************************************
                   105. Construct Binary Tree from Preorder and Inorder Traversal                     
-----------------------------------------------------------------------------------------------------
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
	    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	        int lenp = preorder.size();
	        int leni = inorder.size();
	        if(lenp==0 || lenp!=leni) return NULL;
	        
	        int pindex=0;
	        return gtree(preorder, inorder,pindex, 0,lenp-1);
	    }
	    
	    TreeNode* gtree(vector<int>& po, vector<int>& io, int& pindex, int s, int t)
	    {
	        if (s>t) return NULL;
	        TreeNode* root=new TreeNode(po[pindex++]);
	        if (s==t) return root;
	        
	        int indexio = find(io,root->val);
	        if (indexio>=0)
	        {
	            root->left = gtree(po,io,pindex,s,indexio-1);
	            root->right = gtree(po,io,pindex,indexio+1,t);
	        }
	        return root;
	    }
	    
	    int find(vector<int>& io, int val)
	    {
	        for(int i=0;i<io.size();i++)
	        {
	            if (io[i]==val) return i;
	        }
	        return -1;
	    }
	};

}

/****************************************************************************************************
                                             Note
This is the tradictional question. remember the method
****************************************************************************************************/