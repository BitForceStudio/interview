/****************************************************************************************************
                             150. Evaluate Reverse Polish Notation                
-----------------------------------------------------------------------------------------------------
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int evalRPN(vector<string>& tokens) {
	        int len=tokens.size();
	        if (len==0) return 0;
	        
	        // stack
	        vector<int> calc;
	        for(int i=0;i<len;i++)
	        {
	            string s = tokens[i];
	            if (s!="+" && s!="-" && s!="*" && s!="/")
	            {
	                int curr = stoi(s);
	                calc.push_back(curr);
	            }
	            else
	            {
	                int one = calc.back(); calc.pop_back();
	                int two = calc.back(); calc.pop_back();
	                int rst = 0;
	                if      (s=="+") rst=one+two;
	                else if (s=="-") rst=two-one;
	                else if (s=="*") rst=one*two;
	                else if (s=="/") rst=two/one;   
	                
	                calc.push_back(rst);
	            }
	        }
	        return calc.back();
	    }
	};

}

/****************************************************************************************************
                                             Note
becareful about the signs... don't be stupic smart...
****************************************************************************************************/