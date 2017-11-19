/****************************************************************************************************
                        108. Convert Sorted Array to Binary Search Tree            
-----------------------------------------------------------------------------------------------------
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
	    TreeNode* sortedArrayToBST(vector<int>& nums) {
	        int len=nums.size();
	        if (len==0) return NULL;
	        
	        return gtree(nums,0,len-1);
	    }
	    
	    TreeNode* gtree(vector<int>& nums, int s, int t)
	    {
	        if (s>t) return NULL;
	        if(s==t)
	        {
	            TreeNode* root=new TreeNode(nums[s]);
	            return root;
	        }
	        int mid = int((s+t+1)/2);   // ***
	        TreeNode* root = new TreeNode(nums[mid]);
	        root->left=gtree(nums,s,mid-1);
	        root->right=gtree(nums,mid+1,t);
	        
	        return root;
	    }
	};


	class Solution2 {
	public:
	    TreeNode* sortedArrayToBST(vector<int>& nums) {
	        int len=nums.size();
	        if(len==0) return NULL;
	        
	        TreeNode* root = helper(nums,0,len-1);
	        return root;
	    }
	    
	    TreeNode* helper(vector<int>& nums,int s,int e)
	    {
	        int mid = (s+e)/2;
	        TreeNode* root = new TreeNode(nums[mid]);
	        
	        if(s<mid) root->left=helper(nums,s,mid-1);
	        if(e>mid) root->right =helper(nums,mid+1,e);
	        
	        return root;
	    }
	};

}

/****************************************************************************************************
                                             Note
*** why need to plus one? for now, remember it...
****************************************************************************************************/