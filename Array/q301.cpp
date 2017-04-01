/****************************************************************************************************
                                   301. Remove Invalid Parentheses          
-----------------------------------------------------------------------------------------------------
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all 
possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string p="()";
	    vector<string> removeInvalidParentheses(string s) {
	        vector<string> rst;
	        //
	        // special cases
	        //
	        int len = s.size();
	        if (len<1)
	        {
	            rst.push_back("");
	            return rst;
	        }
	        
	        int i=0;
	        // remove ')' in the begining
	        while(s[i]==')') i++;
	        s=s.substr(i);
	        // remove '(' in the end
	        len=s.size();
	        while(len>0 && s[len-1]=='(') len--;
	        s=s.substr(0,len);
	        if (s=="") 
	        {
	            rst.push_back("");
	            return rst;
	        }
	        
	        // 
	        // recursively find all the solution
	        //
	        remove(s,0,0,rst,0);
	        
	        
	        return rst;
	    }
	    
	    
	    void remove(string s,int last_i, int last_j, vector<string>& rst,int ind)
	    {
	        if (s.size()==0) return;
	        int counter=0;
	        for(int i=last_i;i<s.size();i++)
	        {
	            if (s[i]==p[ind]) counter++;
	            if (s[i]==p[1-ind]) counter--;
	            
	            if (counter<0)
	            {
	                // fix the prefix
	                for(int j=last_j;j<=i;j++)
	                {
	                    if (s[j]==p[1-ind] && (j==last_j || s[j-1]!=p[1-ind]))
	                    {
	                        string t = s.substr(0,j) + s.substr(j+1);
	                        // sort out the rest
	                        remove(t,i,j,rst,ind);
	                    }
	                }
	                return;
	            }
	        }
	        string rs = s;
	        reverse(rs.begin(),rs.end());
	        
	        if (p[1-ind]==')')
	        {
	            remove(rs,0,0,rst,1-ind);
	        }
	        else
	        {
	            rst.push_back(rs);
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
Get the idea from the solution.
Remove one and then sort out the rest. The key is not to repeat. 

Key Points:

Generate unique answer once and only once, do not rely on Set.
Do not need preprocess.
Runtime 3 ms.
Explanation:
We all know how to check a string of parentheses is valid using a stack. Or even simpler use a counter.
The counter will increase when it is ‘(‘ and decrease when it is ‘)’. Whenever the counter is negative, 
we have more ‘)’ than ‘(‘ in the prefix.

To make the prefix valid, we need to remove a ‘)’. The problem is: which one? The answer is any one in 
the prefix. However, if we remove any one, we will generate duplicate results, for example: s = ()), 
we can remove s[1] or s[2] but the result is the same (). Thus, we restrict ourself to remove the first 
) in a series of concecutive )s.

After the removal, the prefix is then valid. We then call the function recursively to solve the rest 
of the string. However, we need to keep another information: the last removal position. If we do not 
have this position, we will generate duplicate by removing two ‘)’ in two steps only with a different 
order.

For this, we keep tracking the last removal position and only remove ‘)’ after that.

Now one may ask. What about ‘(‘? What if s = ‘(()(()’ in which we need remove ‘(‘?
The answer is: do the same from right to left.
However a cleverer idea is: reverse the string and reuse the code!
****************************************************************************************************/