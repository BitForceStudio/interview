/****************************************************************************************************
                                     222. Count Complete Tree Nodes        
-----------------------------------------------------------------------------------------------------
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes 
in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the 
last level h.
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
	    int countNodes(TreeNode* root) {
	        if (root==NULL) return 0;
	        int hl=0,hr=0;
	        TreeNode* l=root;
	        TreeNode* r=root;
	        while(l) {hl++;l=l->left;}
	        while(r) {hr++;r=r->right;}
	        if (hl==hr) return pow(2,hl)-1;
	        return countHelper(root->left,hl-1,-1) + countHelper(root->right,-1,hr-1)+1;
	    }
	    
	    int countHelper(TreeNode* root, int hl, int hr)
	    {
	        if(root==NULL) return 0;
	        TreeNode* c=root;
	        if (hl<0)
	        {
	            hl=0;
	            while(c) {hl++;c=c->left;}
	        }
	        else
	        {
	            hr=0;
	            while(c) {hr++;c=c->right;}
	        }
	        
	        if (hl==hr) return pow(2,hl)-1;
	        return countHelper(root->left,hl-1,-1) + countHelper(root->right,-1,hr-1)+1;
	    }
	};

}

/****************************************************************************************************
                                             Note
Nothing Special. if it was the full-full tree(sub tree), it has to be hl==hr, then it can return. 
Improvement: if it go through the left or right already, give it the indicator which side need to 
explore to avoid the duplication travel.
****************************************************************************************************/