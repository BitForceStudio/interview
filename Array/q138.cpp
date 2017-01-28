/****************************************************************************************************
                              138. Copy List with Random Pointer               
-----------------------------------------------------------------------------------------------------
A linked list is given such that each node contains an additional random pointer which could point to 
any node in the list or null.

Return a deep copy of the list.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	/**
	 * Definition for singly-linked list with a random pointer.
	 * struct RandomListNode {
	 *     int label;
	 *     RandomListNode *next, *random;
	 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	 * };
	 */
	class Solution {
	public:
	    RandomListNode *copyRandomList(RandomListNode *head) {
	        if (head==NULL) return NULL;
	        RandomListNode* dphead = new RandomListNode(0);
	        dphead->next = head;
	        // copy next
	        while(head!=NULL)
	        {
	            RandomListNode* cpNode = new RandomListNode(head->label);
	            cpNode->next = head->next;
	            head->next = cpNode;
	            head = head->next->next;
	        }
	        
	        // copy random
	        head = dphead->next;           // ****
	        while (head!=NULL)
	        {
	            if (head->random!=NULL)
	            {
	                head->next->random = head->random->next;
	            }
	            head=head->next->next;
	        }
	        
	        // break the linked list
	        head = dphead->next;
	        RandomListNode* cphead = head->next;
	        RandomListNode* dchead = head->next;
	        while(head!=NULL)
	        {
	            dchead = head->next;
	            head->next = dchead->next;
	            if (dchead->next!=NULL)
	                dchead->next = dchead->next->next;
	            head = head->next;
	        }
	        return cphead;
	    }
	};

}

/****************************************************************************************************
                                             Note
DO not forget to reset the head.
****************************************************************************************************/