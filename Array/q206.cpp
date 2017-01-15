/****************************************************************************************************
                                   206. Reverse Linked List          
-----------------------------------------------------------------------------------------------------
Reverse a singly linked list.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
	///////////////////  Iterative Solution //////////////////////
	class IterSolution {
	public:
	    ListNode* reverseList(ListNode* head) {
	        if (head==NULL || head->next==NULL) return head;
	        ListNode* nx = head->next;
	        ListNode* nnx = head->next->next;
	        head->next = NULL;
	        while(nnx!=NULL)
	        {
	            nx->next = head;
	            head = nx;
	            nx = nnx;
	            nnx=nnx->next;
	        }
	        nx->next = head;     // **
	        return nx;
	    }
	};

	/////////////////// Recursive Solution /////////////////////
	class RecurSolution {
	public:
	    ListNode* reverseList(ListNode* head) {
	           if (head==NULL || head->next==NULL) return head;
	           return reverse(head,NULL); 
	    }
	    
	    ListNode* reverse(ListNode* head, ListNode* newHead)   // ***
	    {
	        if (head==NULL)
	            return newHead;
	        ListNode* next = head->next;
	        head->next = newHead;
	        return reverse(next,head);
	    }
	};

}

/****************************************************************************************************
                                             Note
** don't forget this one, draw the picture, it will be obviously. 
better iterative solution: 
public ListNode reverseList(ListNode head) {
    ListNode newHead = null;
    while (head != null) {
        ListNode next = head.next;
        head.next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

*** get this idea from the others solution. understand it and remember it. 

****************************************************************************************************/