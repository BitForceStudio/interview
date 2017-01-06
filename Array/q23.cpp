/****************************************************************************************************
                                      23. Merge k Sorted Lists       
-----------------------------------------------------------------------------------------------------
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()<1) return NULL;
        if (lists.size()==1) return lists[0];
        
        int len=lists.size();
        for(int i=len-1;i>0;i--)
        {
            lists[i-1] = mergetwo(lists[i],lists[i-1]);
            lists.pop_back();
        }
        
        return lists[0];
    }
    
    ListNode* mergetwo(ListNode* l1, ListNode* l2)
    {
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        ListNode* dphead = new ListNode(0);
        ListNode* cphead = dphead;
        while(1)
        {
            if (l1->val>l2->val) 
            {
                dphead->next=l2;
                dphead=l2;
                l2=l2->next;
            }
            else
            {
                dphead->next=l1;
                dphead=l1;
                l1=l1->next;
            }
            if (l1==NULL)
            {
                dphead->next = l2;
                break;
            }
            if (l2==NULL)
            {
                dphead->next = l1;
                break;
            }
        }
        return cphead->next;
    }
};

/****************************************************************************************************
                                             Note
new function to merge two list. 
complexity is O(n+2n+3n+4n+...+(k-1)n) =O(n*(k^2))
****************************************************************************************************/