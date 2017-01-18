/****************************************************************************************************
                               82. Remove Duplicates from Sorted List II         
-----------------------------------------------------------------------------------------------------
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers 
from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
	    ListNode* deleteDuplicates(ListNode* head) {
	        if (head==NULL || head->next==NULL) return head;
	        
	        ListNode* dphead = new ListNode(0);
	        dphead->next=head;
	        ListNode* cphead = dphead;
	        
	        bool qdup = false;
	        while(head->next!=NULL)
	        {
	            if (head->val==head->next->val) 
	            {
	                qdup=true;
	                head->next = head->next->next;
	            }
	            else
	            {
	                if (qdup)
	                {
	                    head->val = head->next->val;
	                    head->next=head->next->next;
	                    qdup=false;
	                }
	                else
	                {
	                    head=head->next;
	                    cphead=cphead->next;  // ***
	                }
	            }
	        }
	        if(qdup) cphead->next=NULL;  // ***
	        return dphead->next;
	    }
	};

}

/****************************************************************************************************
                                             Note
the cphead is the one step slower than the head, so, if in the end there is duplication, the cphead
is used to set the NULL in the end. 
****************************************************************************************************/