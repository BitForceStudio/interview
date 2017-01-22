/****************************************************************************************************
                                   92. Reverse Linked List II          
-----------------------------------------------------------------------------------------------------
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
	    ListNode* reverseBetween(ListNode* head, int m, int n) {
	        if (head==NULL || head->next==NULL || m==n) return head;
	        
	        ListNode* dphead = new ListNode(0); 
	        dphead->next = head;
	        ListNode* cphead = dphead;
	        // find m;
	        int ic=1;
	        while(ic<m) {dphead=dphead->next; ic++;}  // 1 based;
	        ListNode* beforeNode=dphead;
	        // reverse from m to n
	        ListNode* innerHead = dphead->next;
	        dphead=innerHead;
	        ListNode* curr=dphead->next;
	        ListNode* tmp=curr;
	        ic++;
	        while(ic<=n && dphead->next!=NULL) // **
	        {
	            tmp=curr->next;
	            curr->next=dphead;
	            dphead=curr;
	            curr=tmp;
	            ic++;   
	        }
	        innerHead->next=curr;
	        beforeNode->next=dphead;
	        return cphead->next;
	    }
	};

}

/****************************************************************************************************
                                             Note
Think about why ic has to be <=n ?
****************************************************************************************************/