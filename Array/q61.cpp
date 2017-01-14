/****************************************************************************************************
                                           61. Rotate List  
-----------------------------------------------------------------------------------------------------
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
	    ListNode* rotateRight(ListNode* head, int k) {
	        if (head==NULL || k==0) return head;
	        ListNode* dphead = new ListNode(0);
	        
	        dphead->next = head;
	        int len=0;
	        while(dphead->next!=NULL)
	        {
	            dphead=dphead->next;
	            len++;
	        }
	        k=k%len; if(k==0） return head;
	        dphead->next=head;
	        for(int i=0;i<len-k;i++)
	            dphead=dphead->next;
	        ListNode* newHead = dphead->next;
	        dphead->next = NULL;
	        return newHead;
	    }
	};

////////////////////// two runner solution.
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
	    ListNode* rotateRight(ListNode* head, int k) {
	        if (head==NULL || k==0) return head;
	        ListNode* dphead = new ListNode(0);
	        
	        dphead->next = head;
	        for(int i=0;i<k;i++)
	        {
	            if (dphead->next!=NULL) {dphead=dphead->next;}
	            else
	            {
	                dphead = new ListNode(0);
	                dphead->next = head;
	                k=k%i;
	                if (k==0) return head;
	                for(int j=0;j<k;j++)
	                {
	                    dphead=dphead->next;
	                }
	                break;
	            }
	        }
	        ListNode* slower = new ListNode(0);
	        slower->next = head;
	        if (dphead->next==NULL) return head;
	        while(dphead->next!=NULL)
	        {
	            slower=slower->next;
	            dphead=dphead->next;
	        }
	        
	        ListNode* newHead = slower->next;
	        dphead->next = head;
	        slower->next = NULL;
	        
	        return newHead;
	    }
	};

}

/****************************************************************************************************
                                             Note
draw pictures to help to solve it.
****************************************************************************************************/