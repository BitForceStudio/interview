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
#include "problems\problems\Header.h"

namespace std
{

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

  class Solution2 {
  public:
      vector<string> generateParenthesis(int n) {
          vector<string> rst;
          if (n<1) return rst;
          
          string curr="";
          int left=n,right=n;
          
          helper(left,right,curr,rst);
          return rst;
      }
      
      void helper(int left, int right, string curr, vector<string>& rst)
      {
          if (left>right) return;
          if (left==0 && right==0) rst.push_back(curr);
          else
          {
              if (left>0) helper(left-1,right,curr+'(',rst);
              if (right>0) helper(left,right-1,curr+')',rst);
          }
      }
  };

}
/****************************************************************************************************
                                             Note
I am not fully understand how to come up this clever solution from begining. May be need to remember
it. 

solution 2, understood solution, count the rest left and right blacket. if illigal, return.
****************************************************************************************************/