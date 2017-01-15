/****************************************************************************************************
                                 203. Remove Linked List Elements           
-----------------------------------------------------------------------------------------------------
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
	class Solution {
	public:
	    ListNode* removeElements(ListNode* head, int val) {
	        if (head==NULL) return head;
	        ListNode* dphead = new ListNode(0);
	        dphead->next = head;
	        ListNode* cphead = dphead;
	        
	        while(dphead->next!=NULL)
	        {
	            if (dphead->next->val == val)
	            {
	                dphead->next=dphead->next->next;
	            }
	            else  // ***
	            {
	                dphead=dphead->next;
	            }
	        }
	        return cphead->next;
	    }
	};

}

/****************************************************************************************************
                                             Note
just be careful about the ***, there may has several val in place. 
****************************************************************************************************/