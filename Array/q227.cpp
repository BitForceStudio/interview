/****************************************************************************************************
                                227. Basic Calculator II             
-----------------------------------------------------------------------------------------------------
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int calculate(string s) {
	        int len=s.size();
	        if (len==0) return 0;
	        
	        vector<int> rst;
	        vector<string> calc; // **
	        for(int i=0;i<len;i++)
	        {
	            if (s[i]==' ') continue;
	            if (s[i]=='+') calc.push_back("+");
	            else if (s[i]=='-') calc.push_back("-");
	            else if (s[i]=='*') calc.push_back("*");
	            else if (s[i]=='/') calc.push_back("/");
	            else
	            {
	                string curr="";
	                while(s[i]!=' ' && s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && i<len)
	                {
	                    curr+=s[i];
	                    i++;
	                }
	                calc.push_back(curr);
	                i--;
	            }
	        }
	        
	        int icurr=0; rst.push_back(stoi(calc[0]));  // ***
	        for(int i=1;i<calc.size();i++)
	        {
	            if (calc[i]=="-") 
	            {
	                icurr=-stoi(calc[i+1]);
	                rst.push_back(icurr);
	                i++;
	            }
	            else if (calc[i]=="+")
	            {
	                icurr=stoi(calc[i+1]);
	                rst.push_back(icurr);
	                i++;
	            }
	            else if (calc[i]=="*")
	            {
	                icurr=stoi(calc[i+1]);
	                icurr*=rst.back();
	                rst.back()=icurr;
	                i++;
	            }
	            else if (calc[i]=="/")
	            {
	                icurr=stoi(calc[i+1]);
	                icurr=rst.back()/icurr;
	                rst.back()=icurr;
	                i++;
	            }
	        }
	        
	        int irst=0;
	        for(int i=0;i<rst.size();i++)
	            irst+=rst[i];
	        
	        return irst;
	    }
	};

}

/****************************************************************************************************
                                             Note
** it has to be vector of string
*** need to push the first to the rst first.
There is the better one:

int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
        if (op == '+' or op == '-') {
            total += term;
            in >> term;
            term *= 44 - op;
        } else {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

****************************************************************************************************/