/****************************************************************************************************
                                       20. Valid Parentheses      
-----------------------------------------------------------------------------------------------------
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input 
string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are 
not.
****************************************************************************************************/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        if (s.size()==0) return true;
        if (s[0]==')' || s[0]==']' || s[0]=='}') return false;
        stack.push_back(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') stack.push_back(s[i]);
            else
            {
                char tmp = stack.back();
                if((s[i]==')' && tmp!='(') ||(s[i]==']' && tmp!='[')||(s[i]=='}' && tmp!='{'))
                    return false;
                stack.pop_back();
            }
        }
        if (stack.size()==0) return true;
        return false;
    }
};
/****************************************************************************************************
                                             Note
Nothing to say... just be careful. 
vector function: 

empty()
Test whether vector is empty (public member function )

front()
Access first element (public member function )
back()
Access last element (public member function )

push_back(val)
Add element at the end (public member function )
pop_back()
Delete last element (public member function )

insert
Insert elements (public member function )
erase
Erase elements (public member function )
swap
Swap content (public member function )
clear
Clear content (public member function )
emplace 
Construct and insert element (public member function )
emplace_back 
Construct and insert element at the end (public member function )
****************************************************************************************************/