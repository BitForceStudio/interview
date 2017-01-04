/****************************************************************************************************
                                 21. Merge Two Sorted Lists              
-----------------------------------------------------------------------------------------------------
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing 
together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        
        ListNode* dphead = new ListNode(0);
        ListNode* cphead = dphead;
        
        while(1)
        {
            if (l1->val>l2->val)
            {
                dphead->next=l2;
                if(l2->next==NULL)
                {
                    dphead->next->next=l1;
                    break;
                }
                l2=l2->next;
            }
            else
            {
                dphead->next=l1;
                if(l1->next==NULL)
                {
                    dphead->next->next=l2;
                    break;
                }
                l1=l1->next;
            }
            dphead=dphead->next;
        }
        
        return cphead->next;
    }
};

/****************************************************************************************************
                                             Note
NULL, just be careful. If one is null, just point to the other one, don't need to go through.
****************************************************************************************************/