/****************************************************************************************************
                                 147. Insertion Sort List                  
-----------------------------------------------------------------------------------------------------
Sort a linked list using insertion sort.
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
	    ListNode* insertionSortList(ListNode* head) {
	        if (head==NULL || head->next==NULL) return head;
	        
	        ListNode* dphead = new ListNode(-2147483648);
	        dphead->next = head;
	        
	        while(head->next!=NULL)  //***
	        {
	            if (head->next->val < head->val)
	            {
	                // find the right place
	                ListNode* it = dphead;
	                while(it->next->val<=head->next->val) it=it->next;
	                ListNode* curr = head->next;
	                head->next=head->next->next;
	                curr->next = it->next;
	                it->next = curr;
	            }
	            else
	                head=head->next;
	        }
	        return dphead->next;
	    }
	};
}

/****************************************************************************************************
                                             Note
Nothing special...
*** it should be next because we need to use it. 
****************************************************************************************************/