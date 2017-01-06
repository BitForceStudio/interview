/****************************************************************************************************
                                      22. Generate Parentheses       
-----------------------------------------------------------------------------------------------------
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
****************************************************************************************************/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        if (n==0) return rst;
        string str="";
        add(rst,str,n,0);
        
        return rst;
    }
    
    void add(vector<string>& rst,string str,int n,int m)
    {
        if(m==0 && n==0)
        {
            rst.push_back(str);
            return;
        }
        
        if (m>0) add(rst,str+')',n,m-1);
        if (n>0) add(rst,str+'(',n-1,m+1);
    }
};

/****************************************************************************************************
                                             Note
I am not fully understand how to come up this clever solution from begining. May be need to remember
it. 
****************************************************************************************************/