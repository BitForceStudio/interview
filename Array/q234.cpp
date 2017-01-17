/****************************************************************************************************
                                   234. Palindrome Linked List          
-----------------------------------------------------------------------------------------------------
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
	    bool isPalindrome(ListNode* head) {
	        if (head==NULL || head->next==NULL) return true;
	        ListNode* slow=head;
	        ListNode* fast=head;
	        ListNode* rev = head;
	        ListNode* tmp = NULL; 
	        
	        while(fast!=NULL && fast->next!=NULL) 
	        {
	            slow=slow->next;
	            fast=fast->next->next;
	            
	            rev->next=tmp;
	            tmp=rev;
	            rev=slow;
	        }
	        
	        if (fast!=NULL) 
	            slow=slow->next;
	        
	        while(tmp!=NULL && slow!=NULL)
	        {
	            if (slow->val!=tmp->val) return false;
	            slow=slow->next;
	            tmp=tmp->next;
	        }
	        return true;
	    }
	};

}

/****************************************************************************************************
                                             Note
It is easy, need to remember how to reverse a linked list
and be careful the difference of double in middle case. 
****************************************************************************************************/