/****************************************************************************************************
                                  445. Add Two Numbers II           
-----------------------------------------------------------------------------------------------------
You are given two non-empty linked lists representing two non-negative integers. The most significant 
digit comes first and each of their nodes contain a single digit. Add the two numbers and return it 
as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	        if (l1->val==0) return l2;
	        if (l2->val==0) return l1;
	        
	        stack<int> left;
	        stack<int> right;
	        
	        while(l1!=NULL)
	        {
	            left.push(l1->val);
	            l1=l1->next;
	        }
	        
	        while(l2!=NULL)
	        {
	            right.push(l2->val);
	            l2=l2->next;
	        }
	        
	        int carry = 0;
	        ListNode* dp = new ListNode(0);
	        while(!left.empty() || !right.empty())
	        {
	            int curr = (left.empty()?0:left.top())+(right.empty()?0:right.top())+carry;  // ****
	            if (!left.empty()) left.pop();
	            if (!right.empty()) right.pop();
	            ListNode* lc = new ListNode(curr%10);
	            carry = curr/10;
	            lc->next=dp->next;
	            dp->next=lc;
	        }
	        
	        if (carry>0)
	        {
	            ListNode* lc = new ListNode(1);
	            lc->next=dp->next;
	            dp->next=lc;
	        }
	        return dp->next;
	        
	    }
	};

}

/****************************************************************************************************
                                             Note
needs the blacket
****************************************************************************************************/