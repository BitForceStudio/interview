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

	        unordered_map<int,int> idind;
	        for(int i=0;i<leni;i++) idind[inorder[i]]=i;
	        
	        int pindex=0;
	        return gtree(preorder, inorder,pindex, idind, 0,lenp-1);
	    }

	    TreeNode* gtree(vector<int>& po, vector<int>& io, int& pindex, unordered_map<int,int>& idind, int s, int t)
	    {
	        if (s>t) return NULL;
	        TreeNode* root=new TreeNode(po[pindex++]);
	        if (s==t) return root;

	        int indexio =-1;
	        if (idind.find(root->val)!=idind.end())
	        {
	            indexio=idind[root->val];
	            root->left = gtree(po,io,pindex,idind,s,indexio-1);
	            root->right = gtree(po,io,pindex,idind,indexio+1,t);
	        }
	        return root;
	    }
	};

	class Solution {
	public:
	    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	        int len = inorder.size();
	        if(len==0) return NULL;
	        map<int,TreeNode*> treeind; // value tree
	        map<int,int> idind;  // inorder index
	        set<int> visited; // visited val idind
	        for(int i=0;i<len;i++)
	        {
	            TreeNode* nt = new TreeNode(inorder[i]);
	            treeind[inorder[i]]=nt;
	            idind[inorder[i]]=i;
	        }
	        
	        visited.insert(idind[preorder[0]]);
	        for(int i=1;i<len;i++)
	        {
	            visited.insert(idind[preorder[i]]);
	            if(idind[preorder[i]]<idind[preorder[i-1]])
	            {
	                // first visited right hand
	                set<int>::iterator t = visited.find(idind[preorder[i]]);t++;
	                treeind[inorder[*t]]->left=treeind[preorder[i]];
	            }
	            else
	            {
	                // first visited left hand
	                set<int>::iterator t = visited.find(idind[preorder[i]]);t--;
	                treeind[inorder[*t]]->right = treeind[preorder[i]];
	            }
	        }
	        return treeind[preorder[0]];
	    }
	};

}

/****************************************************************************************************
                                             Note
This is the tradictional question. remember the method
****************************************************************************************************/