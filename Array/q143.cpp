/****************************************************************************************************
                                    143. Reorder List               
-----------------------------------------------------------------------------------------------------
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
	    void reorderList(ListNode* head) {
	        if (head==NULL || head->next==NULL || head->next->next==NULL) return;
	        
	        ListNode* dphead = new ListNode(0);
	        dphead->next = head;
	        
	        // two runner
	        ListNode* slow = head;
	        ListNode* fast = head;
	        while(fast->next!=NULL)
	        {
	            slow=slow->next;
	            if(fast->next->next==NULL)  // even nodes
	            {
	                fast=fast->next; 
	                break;
	            }
	            fast=fast->next->next;
	        }

	        // revert direction from slow->next;
	        ListNode* cs = slow;
	        ListNode* csn = slow->next;
	        ListNode* csnn = slow->next->next;
	        cs->next = NULL;

	        while(1)
	        {
	            csn->next=cs;
	            cs = csn;
	            csn=csnn;
	            if (csnn==NULL) break;
	            csnn=csnn->next;
	        }
	        // fast is new head from the tail
	        head = dphead->next;
	        ListNode* nfast = fast->next;
	        while(head->next!=NULL && nfast!=NULL)  // ***
	        {
	            fast->next=head->next;
	            head->next=fast;
	            head=head->next->next;
	            fast=nfast;
	            nfast=nfast->next;
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
Draw a picture it will be very clear. 
****************************************************************************************************/