/****************************************************************************************************
                            241. Different Ways to Add Parentheses                 
-----------------------------------------------------------------------------------------------------
Given a string of numbers and operators, return all possible results from computing all the different
 possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> diffWaysToCompute(string input) {
	        int len=input.size();
	        vector<int> rst;
	        if (len==0) return rst;
	        
	        for(int i=0;i<len;i++)
	        {
	            if (input[i]=='+' ||input[i]=='-'||input[i]=='*')
	            {
	                vector<int> r1 = diffWaysToCompute(input.substr(0,i));
	                vector<int> r2 = diffWaysToCompute(input.substr(i+1));
	            
	                for(int j=0;j<r1.size();j++)
	                {
	                    for(int k=0;k<r2.size();k++)
	                    {
	                        if(input[i]=='+') rst.push_back(r1[j]+r2[k]);
	                        if(input[i]=='-') rst.push_back(r1[j]-r2[k]);
	                        if(input[i]=='*') rst.push_back(r1[j]*r2[k]);
	                    }
	                }
	            }
	        }
	        
	        if (rst.size()==0) rst.push_back(stoi(input));
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
from the solution. divided and concer.
****************************************************************************************************/