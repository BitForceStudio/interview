/****************************************************************************************************
                                   224. Basic Calculator       
-----------------------------------------------------------------------------------------------------
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, 
non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int calculate(string s) {
	        int len=s.size();
	        if (len==0) return 0;

	        vector<string> calc;
	        
	        for(int i=0;i<len;i++)
	        {
	            if (s[i]=='(') calc.push_back("(");
	            else if (s[i]==')') calc.push_back(")");
	            else if (s[i]=='+') calc.push_back("+");
	            else if (s[i]=='-') calc.push_back("-");
	            else if (s[i]==' ') continue;
	            else
	            {
	                string curr="";
	                while(i<len && s[i]>='0' && s[i]<='9') 
	                {
	                    curr+=s[i];
	                    i++;
	                }
	                i--;
	                calc.push_back(curr);
	            }
	        }

	        int e=0;
	        int rst=helper(calc,0,e);
	        return rst;
	    }
	    
	    int helper(vector<string>& calc, int b, int& e)
	    {
	        int rst=0;

	        for(int i=b;i<calc.size();i++)
	        {
	            if (calc[i][0]=='(') 
	            {
	                rst+=helper(calc,i+1,e);
	                i=e;
	            }
	            else if (calc[i][0]==')')
	            {
	                e=i;
	                return rst;
	            }
	            else
	            {
	                if (calc[i][0]=='-') 
	                {
	                    if (calc[i+1][0]=='(') 
	                    {
	                        rst-=helper(calc,i+2,e);
	                        i=e;
	                    }
	                    else
	                    {
	                        rst-=stoi(calc[i+1]);
	                        i++;
	                    }
	                }
	                else if (calc[i][0]=='+') 
	                {
	                    if (calc[i+1][0]=='(') 
	                    {
	                        rst+=helper(calc,i+2,e);
	                        i=e;
	                    }
	                    else
	                    {
	                        rst+=stoi(calc[i+1]);
	                        i++;
	                    }
	                }
	                else
	                    rst+=stoi(calc[i]);
	            }
	        }
	        
	        e=calc.size();
	        return rst;
	        
	    }
	};

}

/****************************************************************************************************
                                             Note
Becare full about the detail.
Better solution:

class Solution {
public:
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }
};
****************************************************************************************************/