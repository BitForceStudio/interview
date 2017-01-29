/****************************************************************************************************
                                 142. Linked List Cycle II              
-----------------------------------------------------------------------------------------------------
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
	    ListNode *detectCycle(ListNode *head) {
	        if (head==NULL || head->next == NULL) return NULL;
	        if (head->next==head) return head;
	        
	        ListNode* slow = head;
	        ListNode* fast = head;
	        while(1)
	        {
	            slow=slow->next;
	            fast=fast->next->next;
	            if ( fast==NULL || fast->next==NULL) return NULL;
	            if (slow==fast) break;
	        }
	        fast=fast->next;
	        int i=0;
	        while(fast!=slow)
	        {
	            fast=fast->next;
	            i++;
	        }
	        
	        fast=head;
	        slow=head;
	        while(i>=0)
	        {
	            fast=fast->next;
	            i--;
	        }
	        
	        while(slow!=fast)
	        {
	            slow=slow->next;
	            fast=fast->next;
	        }
	        
	        return slow;
	    }
	};

}

/****************************************************************************************************
                                             Note
find the circle length. then fast and slow runner fast is circle length ahead.
****************************************************************************************************/