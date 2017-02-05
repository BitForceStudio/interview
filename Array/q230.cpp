/****************************************************************************************************
                                  230. Kth Smallest Element in a BST       
-----------------------------------------------------------------------------------------------------
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest 
frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).

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
	    int kthSmallest(TreeNode* root, int k) {
	        if (root==NULL) return 0; 
	        int icurr=0;
	        int rst=0;
	        bool qfound = inorder(root,icurr,k,rst);
	        return rst;
	    }
	    
	    bool inorder(TreeNode* root,int& icurr, int k, int& rst)
	    {
	        if (root->left==NULL && root->right==NULL)
	        {
	            icurr++;
	            if (icurr==k) 
	            {
	                rst=root->val;
	                return true;
	            }
	            else return false;
	        }

	        if (root->left!=NULL && inorder(root->left,icurr,k,rst)) return true;
	        icurr++;
	        if(icurr==k)
	        {
	            rst=root->val; 
	            return true;
	        }
	        if(root->right!=NULL && inorder(root->right,icurr,k,rst)) return true;
	        
	        return false;
	    }
	};

}

/****************************************************************************************************
                                             Note
if modify the tree node stucture, it could be number of its child node.
****************************************************************************************************/