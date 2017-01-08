/****************************************************************************************************
                                   32. Longest Valid Parentheses          
-----------------------------------------------------------------------------------------------------
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
****************************************************************************************************/

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

/****************************************************************************************************
                                             Note
Finished this one by getting help from others' solution. However, it was real clever. 
Need to draw the sample and consider all the special cases. 
original one just push the index, using s[index] to do the trick. very clever. 
****************************************************************************************************/