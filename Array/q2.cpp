/****************************************************************************************************
                                        2. Add Two Numbers
-----------------------------------------------------------------------------------------------------
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse 
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked 
list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode* addlist = new ListNode(0);
        addlist->val = 0;
        addlist->next=NULL;
        ListNode* addhead=addlist;
        int next = 0;
        while(1)
        {
            int add = l1->val+l2->val+next;
            if (add>9) next = 1;
            else       next = 0;
            
            add = add - next*10;
            addlist->val = add;
            
            if (l1->next==NULL && l2->next==NULL)
            {
                if (next>0)
                {
                    ListNode * nextnode = new ListNode(next);
                    addlist->next = nextnode;
                }
                break;
            }
            
            if (l1->next==NULL) 
            {
                l2=l2->next;
                addlist->next=l2;
                
                while(1)
                {
                    if (l2->val+next>9)
                    {
                        next = 1;
                        l2->val = 0;
                    }
                    else
                    {
                        l2->val+=next;
                        next = 0;
                        break;
                    }
                    if (l2->next==NULL)
                    {
                        ListNode * nextnode = new ListNode(1);
                        l2->next = nextnode;
                        break;
                    }
                    l2=l2->next;
                }
                break;
            }
            
            if (l2->next==NULL) 
            {
                l1=l1->next;
                addlist->next=l1;
                
                while(1)
                {
                    if (l1->val+next>9)
                    {
                        next = 1;
                        l1->val = 0;
                    }
                    else
                    {
                        l1->val+=next;
                        next = 0;
                        break;
                    }
                    if (l1->next==NULL)
                    {
                        ListNode * nextnode = new ListNode(1);
                        l1->next = nextnode;
                        break;
                    }
                    l1=l1->next;
                }
                break;
            }
            l1=l1->next;
            l2=l2->next;
            ListNode * nextnode = new ListNode(0);
            addlist->next = nextnode;
            addlist = addlist->next;
        }
        return addhead;
    }
};

/****************************************************************************************************
                                             Note
Careful about the carrier. think about the better solution.
****************************************************************************************************/