/****************************************************************************************************
                106. Construct Binary Tree from Inorder and Postorder Traversal                
-----------------------------------------------------------------------------------------------------
Given inorder and postorder traversal of a tree, construct the binary tree.

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
	    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	        int leni = inorder.size();
	        int lenp = postorder.size();
	        
	        if(leni==0 || leni!=lenp) return NULL;
	        
	        int pindex = lenp-1;
	        
	        return gtree(inorder, postorder, pindex, 0, leni-1);
	    }
	    
	    TreeNode* gtree(vector<int>& io, vector<int>& po, int& pindex, int s, int t)
	    {
	        if (s>t) return NULL;
	        TreeNode* root = new TreeNode(po[pindex--]);
	        if (s==t) return root;
	        
	        int indexio = find(io,root->val,s,t);
	        if(indexio>=0)
	        {
	            root->right = gtree(io,po,pindex,indexio+1,t);   // ***
	            root->left = gtree(io,po,pindex,s,indexio-1);
	        }
	        return root;
	    }
	    
	    int find(vector<int>& io, int val, int s, int t)
	    {
	        for(int i=s;i<=t;i++)
	        {
	            if (io[i]==val) return i;
	        }
	        return -1;
	    }
	};

	class Solution2 {
	public:
	    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	        int len = inorder.size();
	        if(len==0) return NULL;
	        
	        unordered_map<int,int> idind;
	        for(int i=0;i<len;i++)
	        {
	            idind[inorder[i]]=i;
	        }
	        int pindex=len-1;
	        return helper(postorder, idind,pindex,0,len-1);
	    }
	    
	    TreeNode* helper(vector<int>& postorder,unordered_map<int,int>& idind, int& pindex, int s, int t)
	    {
	        if(s>t) return NULL;
	        TreeNode* root = new TreeNode(postorder[pindex--]);
	        if(s==t) return root;
	        
	        if(idind.find(root->val)!=idind.end())
	        {
	            int rootindex = idind[root->val];
	            if(rootindex>=s && rootindex<=t)
	            {
	                root->right = helper(postorder,idind,pindex,rootindex+1,t);
	                root->left = helper(postorder,idind,pindex,s,rootindex-1);
	            }
	        }

	        return root;
	    }
	};

}

/****************************************************************************************************
                                             Note
it has to travel the right first. 
****************************************************************************************************/