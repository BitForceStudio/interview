/****************************************************************************************************
                              19. Remove Nth Node From End of List                 
-----------------------------------------------------------------------------------------------------
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dphead=new ListNode(0);
        dphead->next = head;
        ListNode* cphead=dphead;
        int t=nextnode(dphead,n);
        return cphead->next;
    }
    
    int nextnode(ListNode* curr,int n)
    {
        if (curr->next==NULL)
        {
            return 1;
        }
        int ic=nextnode(curr->next,n);
        if (ic==n) 
        {
            // remove the next node
            curr->next=curr->next->next;
        }
        
        return ic+1;
    }
};
/****************************************************************************************************
                                             Note
Another approach is using two runners, one fast and one slow, fast - slow = n. Since fast reached the
end, remove slow. 

****************************************************************************************************/