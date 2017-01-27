/****************************************************************************************************
                         116. Populating Next Right Pointers in Each Node           
-----------------------------------------------------------------------------------------------------
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next 
pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every 
parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	/**
	 * Definition for binary tree with next pointer.
	 * struct TreeLinkNode {
	 *  int val;
	 *  TreeLinkNode *left, *right, *next;
	 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    void connect(TreeLinkNode *root) {
	        if (root==NULL) return;
	        
	        // connect the left and right child
	        if (root->left!=NULL && root->right!=NULL)
	        {
	            root->left->next = root->right;
	        }
	        else return;                           // ****
	        TreeLinkNode* rLeft  = root->left;
	        TreeLinkNode* rRight = root->right;
	        while(rLeft->right!=NULL && rRight->left!=NULL)
	        {
	            rLeft->right->next = rRight->left;
	            rLeft=rLeft->right;
	            rRight = rRight->left;
	        }
	        
	        connect(root->left);
	        connect(root->right);
	    }
	};
}

/****************************************************************************************************
                                             Note
****: if it was leaf node, return. 
****************************************************************************************************/