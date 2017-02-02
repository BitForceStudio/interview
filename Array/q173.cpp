/****************************************************************************************************
                                    173. Binary Search Tree Iterator         
-----------------------------------------------------------------------------------------------------
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root 
node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the 
height of the tree.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	/**
	 * Definition for binary tree
	 * struct TreeNode {
	 *     int val;
	 *     TreeNode *left;
	 *     TreeNode *right;
	 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 * };
	 */
	class BSTIterator {
	public:
	    BSTIterator(TreeNode *root) {
	        pushLeftBranch(root);
	    }

	    /** @return whether we have a next smallest number */
	    bool hasNext() {
	        return !m_tree.empty();
	    }

	    /** @return the next smallest number */
	    int next() {
	        TreeNode* tmp=m_tree.top();
	        m_tree.pop();
	        if (tmp->right!=NULL) pushLeftBranch(tmp->right);
	        return tmp->val;
	    }
	private:
	    stack<TreeNode*> m_tree;
	    void pushLeftBranch(TreeNode* root)
	    {
	        while(root!=NULL)
	        {
	            m_tree.push(root);
	            root=root->left;
	        }
	    }
	};

	/**
	 * Your BSTIterator will be called like this:
	 * BSTIterator i = BSTIterator(root);
	 * while (i.hasNext()) cout << i.next();
	 */

}

/****************************************************************************************************
                                             Note
The tricky part is the average run time O(1), it means it could use more. so, just store the left of
each subtree. 
****************************************************************************************************/