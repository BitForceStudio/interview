/****************************************************************************************************
                          109. Convert Sorted List to Binary Search Tree           
-----------------------------------------------------------------------------------------------------
Given a singly linked list where elements are sorted in ascending order, convert it to a height 
balanced BST.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     ListNode *next;
	 *     ListNode(int x) : val(x), next(NULL) {}
	 * };
	 */
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
	    TreeNode* sortedListToBST(ListNode* head) {
	        if (head==NULL) return NULL;
	        
	        vector<int> nums;
	        while(head!=NULL) 
	        {
	            nums.push_back(head->val);
	            head=head->next;
	        }
	        
	        return gtree(nums,0,nums.size()-1);
	    }
	    
	    TreeNode* gtree(vector<int>& nums, int s, int t)
	    {
	        if (s>t) return NULL;
	        if (s==t)
	        {
	            TreeNode* root=new TreeNode(nums[s]);
	            return root;
	        }
	        
	        int mid=int((s+t+1)/2);
	        TreeNode* root=new TreeNode(nums[mid]);
	        
	        root->left = gtree(nums,s,mid-1);
	        root->right = gtree(nums,mid+1,t);
	        return root;
	    }
	};

}

/****************************************************************************************************
                                             Note
Is there any other solution? slow and fast runner, just for O(1) space sack.
****************************************************************************************************/