/****************************************************************************************************
                                    24. Swap Nodes in Pairs         
-----------------------------------------------------------------------------------------------------
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
        ListNode* swapPairs(ListNode* head) {
            if (head==NULL || head->next==NULL) return head;
            ListNode* dphead = new ListNode(0);
            dphead->next=head;
            ListNode* cphead = dphead;
            while(dphead->next->next!=NULL)
            {
                ListNode* first=dphead->next;
                ListNode* second = first->next;
                if(second->next == NULL)
                {
                    dphead->next=second;
                    second->next=first;
                    first->next=NULL;
                    return cphead->next;
                }
                ListNode* cnext = second->next;
                
                dphead->next=second;
                second->next=first;
                first->next=cnext;
                
                dphead=first;
            }
            return cphead->next;
            
        }
    };

    class Solution2 {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (head==NULL || head->next==NULL) return head;
            
            ListNode* dp=new ListNode(0);
            dp->next = head;
            ListNode* h=dp;
            ListNode* c=head;
            ListNode* n=c->next;
            while(c!=NULL && n!=NULL)
            {
                ListNode* nn=n->next;
                c->next = nn;
                n->next = c;
                h->next = n;
                h=c;
                c=nn;
                if(c!=NULL) n=c->next;
            }
            return dp->next;
        }
    };
}
/****************************************************************************************************
                                             Note
in the first condition, be careful about ->next. at least two. 
and swaping order
****************************************************************************************************/