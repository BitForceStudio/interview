/****************************************************************************************************
                                   32. Longest Valid Parentheses          
-----------------------------------------------------------------------------------------------------
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{
    class Solution {
    public:
        int longestValidParentheses(string s) {
            if (s.size()==0) return 0;
            vector<char> stack; stack.push_back(s[0]);
            vector<int> istack; istack.push_back(0);
            for(int i=1;i<s.size();i++)
            {
                if (stack.back()=='(' && s[i]==')') 
                {
                    stack.pop_back();
                    istack.pop_back();
                }
                else
                {
                    stack.push_back(s[i]);
                    istack.push_back(i);
                }
            }

            if (istack.size()==0) return s.size();
            if (istack.size()==s.size()) return 0;
            
            int max = istack[0]>(s.size()-istack.back()-1)?istack[0]:(s.size()-istack.back()-1);      
            if (istack.size()==1) return max;
            
            for(int i=1;i<istack.size();i++)
            {
                max=max>(istack[i]-istack[i-1]-1)?max:(istack[i]-istack[i-1]-1);
            }
            return max;
        }
    };

    class Solution2 {
    public:
        int longestValidParentheses(string s) {
            int len=s.size();
            if (len<=1) return 0;
            
            stack<int> index;
            index.push(-1);
            index.push(0);
            for(int i=1;i<len;i++)
            {
                if(!index.top()!=-1 && s[i]==')' && s[index.top()]=='(')
                {
                    index.pop();
                }
                else
                {
                    index.push(i);
                }
            }
            
            int rst=0;
            int curr=len;
            while(index.top()!=-1)
            {
                rst=(curr-index.top())>rst?(curr-index.top()):rst;
                curr = index.top();
                index.pop();
            }
            rst=(curr+1)>rst?(curr+1):rst;
            return rst-1;
        }
    };
}
/****************************************************************************************************
                                             Note
Finished this one by getting help from others' solution. However, it was real clever. 
Need to draw the sample and consider all the special cases. 
original one just push the index, using s[index] to do the trick. very clever. 
****************************************************************************************************/