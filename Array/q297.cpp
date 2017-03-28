/****************************************************************************************************
                                             
-----------------------------------------------------------------------------------------------------
Serialization is the process of converting a data structure or object into a sequence of bits so that 
it can be stored in a file or memory buffer, or transmitted across a network connection link to be 
reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
serialization/deserialization algorithm should work. You just need to ensure that a binary tree can 
be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not 
necessarily need to follow this format, so please be creative and come up with different approaches 
yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and 
deserialize algorithms should be stateless.
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
	class Codec {
	public:

	    // Encodes a tree to a single string.
	    string serialize(TreeNode* root) {
	        // use '#' to represent null use ',' to seperate the numbers
	        string rst="";
	        if (root==NULL)
	        {
	            return rst;
	        }
	        queue<TreeNode*> qt;
	        qt.push(root);
	        while(!qt.empty())
	        {
	            TreeNode* tmp = qt.front();
	            qt.pop();
	            // constract the string
	            if(tmp==NULL) 
	            {
	                rst+="#,";
	            }
	            else
	            {
	                rst+=to_string(tmp->val)+",";
	                qt.push(tmp->left);
	                qt.push(tmp->right);
	            }
	        }
	        return rst;
	    }

	    // Decodes your encoded data to tree.
	    TreeNode* deserialize(string data) {
	        if (data.size()==0) return NULL;
	        int i=0;
	        // get root
	        int val=0;
	        int sign=1;
	        if (data[i]=='-')
	        {
	            sign=-1;
	            i++;
	        }
	        while(i<data.size() && data[i]!=',')
	        {
	            val=val*10+data[i]-'0';
	            i++;
	        }
	        i++;
	        TreeNode* root=new TreeNode(sign*val);
	        queue<TreeNode*> qt;
	        qt.push(root);
	        bool qleft=false; // if true, then right and set it to false
	        while(i<data.size())
	        {
	            TreeNode* curr = qt.front();
	            qt.pop();
	            // both side
	            for(int k=0;k<2;k++) // ***
	            {
	                val=0;
	                sign=1;
	                if (data[i]=='#')
	                {
	                    i+=2;
	                }
	                else
	                {
	                    if (data[i]=='-')
	                    {
	                        sign=-1;
	                        i++;
	                    }
	                    
	                    while(i<data.size() && data[i]!=',')
	                    {
	                        val=val*10+data[i]-'0';
	                        i++;
	                    }
	                    i++; // scape ','
	                    
	                    TreeNode* tmp=new TreeNode(val*sign);
	                    if(k==0) 
	                    {
	                        curr->left=tmp;
	                    }
	                    else
	                    {
	                        curr->right=tmp;
	                    }
	                    
	                    qt.push(tmp);
	                }
	            }
	        }
	        
	        return root;
	    }
	};

	// Your Codec object will be instantiated and called as such:
	// Codec codec;
	// codec.deserialize(codec.serialize(root));

}

/****************************************************************************************************
                                             Note
** left and right for curr. 
****************************************************************************************************/