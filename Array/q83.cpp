/****************************************************************************************************
                                83. Remove Duplicates from Sorted List         
-----------------------------------------------------------------------------------------------------
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
****************************************************************************************************/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* dphead=new ListNode(0); dphead->next=head;
        ListNode* curr=head;
        ListNode* fast=head->next;
        while(fast!=NULL)
        {
            if (curr->val==fast->val)
            {
                fast=fast->next;
            }
            else
            {
                curr->next=fast;
                curr=curr->next;
                fast=fast->next;
            }
        }
        curr->next=NULL;
        return dphead->next;
    }
};

/****************************************************************************************************
                                             Note
Just be careful for some bugs...
****************************************************************************************************/