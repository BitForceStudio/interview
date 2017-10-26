/****************************************************************************************************
                                   25. Reverse Nodes in k-Group          
-----------------------------------------------------------------------------------------------------
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head==NULL || head->next==NULL || k==1) return head;
            
            ListNode* dphead=new ListNode(0);
            dphead->next=head; 
            ListNode* cphead = dphead;
            ListNode* kth = head;
            
            // first k, in order to get head
            int j=0;
            while(j<k && kth!=NULL)
            {
                kth=kth->next;
                j++;
            }
            if (j<k && kth==NULL) return cphead->next;
            
            ListNode* tmp = dphead;
            ListNode* ntmp = dphead; ntmp=ntmp->next->next;
            dphead=dphead->next; dphead->next=kth;

            for(int i=1;i<k;i++)
            {
                tmp = ntmp->next;
                ntmp->next=dphead;
                dphead=ntmp;
                ntmp=tmp;
            }
            
            // get head
            cphead->next = dphead;
            
            for(int i=1;i<k;i++) dphead=dphead->next;
            
            while(1)
            {
                kth = dphead;  
                j=0;
                while(j<k && kth!=NULL)
                {
                    kth=kth->next;
                    j++;
                }
                if (kth==NULL) break;
                
                dphead->next=kth; 
                dphead = tmp;
                ntmp=tmp->next;
                for(int i=1;i<k;i++)
                {
                    tmp = ntmp->next;
                    ntmp->next=dphead;
                    dphead=ntmp;
                    ntmp=tmp;
                }
                
                for(int i=1;i<k;i++) dphead=dphead->next;
                dphead->next=tmp;
            }
            
            
            return cphead->next;
        }
    };

    class Solution2 {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head==NULL || head->next==NULL || k<=1) return head;
            
            ListNode* dp = new ListNode(0);
            dp->next = head;
            ListNode* h=dp;
            ListNode* rt=head;
            while(rt!=NULL)
            {
                int i=1;
                ListNode* rh=rt;
                while(i<k && rt!=NULL)
                {
                    rt=rt->next;
                    i++;
                }
                
                if (i<k || rt==NULL) break;
                
                ListNode* n=rt->next;
                // reverse link from rh to rt
                ListNode* crh = rh;
                ListNode* crt = rt;
                ListNode* nx = crh->next;
                while(crh!=crt)
                {
                    ListNode* nnx = nx->next;
                    nx->next = crh;
                    crh=nx;
                    nx=nnx;
                }
                
                // prepare for the next run
                h->next = rt;
                rh->next = n;
                h=rh;
                rt=n;
            }
            
            return dp->next;
        }
    };
}
/****************************************************************************************************
                                             Note
finished this by trying and debugging. the idea is simple. three pointers, copy the ->next->next ,
reverse the curr and ->next, then move all to prepare next loop.
****************************************************************************************************/