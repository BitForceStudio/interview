/****************************************************************************************************
                                      86. Partition List       
-----------------------------------------------------------------------------------------------------
Given a linked list and a value x, partition it such that all nodes less than x come before nodes 
greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
	class MySolution {
	public:
	    ListNode* partition(ListNode* head, int x) {
	        if (head==NULL || head->next==NULL) return head;
	        
	        ListNode* dphead = new ListNode(0);
	        dphead->next = head;
	        ListNode* cphead=dphead;
	        
	        ListNode* slow=dphead;
	        
	        // find first node that greater than or equals to x;
	        while(slow->next!=NULL && slow->next->val<x) slow=slow->next;
	        if (slow->next==NULL) return head;
	        ListNode* fast=slow;
	        while(fast->next!=NULL)
	        {
	            if (fast->next->val<x)
	            {
	                ListNode* insert = fast->next;
	                fast->next = insert->next;
	                insert->next=slow->next;
	                slow->next=insert;
	                slow=insert;
	            }
	            else
	            {
	                fast=fast->next;
	            }
	        }
	        
	        return cphead->next;
	    }
	};

}

/****************************************************************************************************
                                             Note
MySolution: find and insert
others solution: reform two linked list and connect them together at end. 
****************************************************************************************************/