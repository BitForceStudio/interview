/****************************************************************************************************
                                  148. Sort List           
-----------------------------------------------------------------------------------------------------
Sort a linked list in O(n log n) time using constant space complexity.
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
	    ListNode* merge(ListNode* h1, ListNode* h2){
	        if(h1 == NULL){
	            return h2;
	        }
	        if(h2 == NULL){
	            return h1;
	        }
	        
	        if(h1->val < h2->val){
	            h1->next = merge(h1->next, h2);
	            return h1;
	        }
	        else{
	            h2->next = merge(h1, h2->next);
	            return h2;
	        }
	        
	    }

	    ListNode* sortList(ListNode* head) {
	        // iterative merge sort
	        
	        // if NULL or just one value, return.
	        if (head==NULL || head->next==NULL) return head;
	        ListNode* pre = head;
	        ListNode* p1 = head;
	        ListNode* p2 = head;
	        
	        while(p2!=NULL && p2->next!=NULL)
	        {
	            pre=p1;
	            p1=p1->next;
	            p2=p2->next->next;
	        }
	        pre->next=NULL;
	        
	        pre=sortList(head);
	        p2=sortList(p1);
	        
	        return merge(pre,p2);
	    }
	};

}

/****************************************************************************************************
                                             Note
Followed the solution. 
the merge function is the key, and sortList need to break the list into two part and then merge them.
****************************************************************************************************/