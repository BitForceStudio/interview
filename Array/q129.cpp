/****************************************************************************************************
                                  129. Sum Root to Leaf Numbers                 
-----------------------------------------------------------------------------------------------------
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
	    int sumNumbers(TreeNode* root) {
	        if (root==NULL) return 0;
	        int sum=0;
	        sumTree(root, 0, sum);
	        return sum;
	    }
	    
	    void sumTree(TreeNode* root, int curr, int& sum)
	    {
	        if (root->left==NULL && root->right==NULL)
	        {
	            curr=curr*10+root->val;
	            sum+=curr;
	        }
	        
	        curr=curr*10+root->val;
	        if(root->left!=NULL) sumTree(root->left,curr,sum);
	        if(root->right!=NULL) sumTree(root->right,curr,sum);
	    }
	};

}

/****************************************************************************************************
                                             Note
nothing special, don't forget root==NULL.
****************************************************************************************************/