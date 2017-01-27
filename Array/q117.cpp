/****************************************************************************************************
                      117. Populating Next Right Pointers in Each Node II            
-----------------------------------------------------------------------------------------------------
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
	        if (root==NULL || (root->left==NULL && root->right==NULL)) return;
	        if (root->left!=NULL && root->right!=NULL)
	        {
	            root->left->next = root->right;
	            TreeLinkNode* leftfr = new TreeLinkNode(0);
	            TreeLinkNode* rightfl = new TreeLinkNode(0);
	            int lvl=1;
	            while(1)
	            {
	                leftfr=leftFarRight(root->left,0,lvl);
	                rightfl=rightFarLeft(root->right,0,lvl);
	                if (leftfr!=NULL && rightfl!=NULL) leftfr->next = rightfl;
	                else break;
	                lvl++;
	            }
	        }
	        if(root->left!=NULL)  connect(root->left);
	        if(root->right!=NULL) connect(root->right);
	    }
	    
	    TreeLinkNode* leftFarRight(TreeLinkNode* root, int clv, int lv)
	    {
	        if (root==NULL) return NULL;
	        if (clv==lv) return root;
	        TreeLinkNode* right = leftFarRight(root->right,clv+1,lv);
	        if (right==NULL)
	            right = leftFarRight(root->left,clv+1,lv);
	        return right;
	    }
	    
	    TreeLinkNode* rightFarLeft(TreeLinkNode* root, int clv, int lv)
	    {
	        if (root==NULL) return NULL;
	        if (clv==lv) return root;
	        TreeLinkNode* left = rightFarLeft(root->left,clv+1,lv);
	        if (left==NULL)
	            left = rightFarLeft(root->right,clv+1,lv);
	        return left;
	    }
	};


	class BetterSolution {
	public:
	    void connect(TreeLinkNode *root) {
	        if (root==NULL || (root->left==NULL && root->right==NULL)) return;
	        
	        // init three pointers
	        TreeLinkNode* curr=NULL;
	        TreeLinkNode* above=root;
	        TreeLinkNode* currHead=NULL;
	        
	        while(above!=NULL)
	        {
	            while(above!=NULL)
	            {
	                //left
	                if (above->left!=NULL) 
	                {
	                    if (curr==NULL)
	                    {
	                        currHead=above->left;
	                    }
	                    else
	                    {
	                        curr->next = above->left;
	                    }
	                    curr = above->left;
	                }
	                
	                // right
	                if (above->right!=NULL)
	                {
	                    if(curr==NULL)
	                    {
	                        currHead=above->right;
	                    }
	                    else
	                    {
	                        curr->next = above->right;
	                    }
	                    curr = above->right;
	                }
	                // move to next node.
	                above=above->next;
	            }
	            // next level
	            above=currHead;
	            curr=NULL;
	            currHead=NULL;
	        }
	    }

	};

}

/****************************************************************************************************
                                             Note
My idea is bad, because it uses lots of travel. The better idea is travel the connected level and 
connected the next level. it was much better.
****************************************************************************************************/