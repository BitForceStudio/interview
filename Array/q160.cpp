/****************************************************************************************************
                              160. Intersection of Two Linked Lists         
-----------------------------------------------------------------------------------------------------
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
	    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	        if (headA==NULL || headB==NULL) return NULL;
	        
	        ListNode* dpheadA = new ListNode(0); dpheadA->next=headA;
	        ListNode* dpheadB = new ListNode(0); dpheadB->next=headB;
	        
	        int lenA=0;
	        int lenB=0;
	        while (dpheadA->next!=NULL) {dpheadA=dpheadA->next; lenA++;}   // **
	        while (dpheadB->next!=NULL) {dpheadB=dpheadB->next; lenB++;}   // **
	        
	        if (lenA<lenB) 
	        {
	            while(lenA!=lenB) {headB=headB->next; lenA++;}
	        }
	        else if(lenA>lenB)
	        {
	            while(lenA!=lenB) {headA=headA->next; lenB++;}
	        }
	        
	        while(headA!=NULL && headB!=NULL)
	        {
	            if (headA==headB) return headA;
	            headA=headA->next;
	            headB=headB->next;
	        }
	        return NULL;
	    }
	};

}

/****************************************************************************************************
                                             Note
don't mess up here, it has to be the longer one to run. 
****************************************************************************************************/