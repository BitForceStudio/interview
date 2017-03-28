/****************************************************************************************************
                                      44. Wildcard Matching       
-----------------------------------------------------------------------------------------------------
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isMatch(string s, string p) {
	        int lens = s.size();
	        int lenp = p.size();
	        if (lenp==0) return false;
	        vector<vector<bool> > mat(lens+1,vector<bool>(lenp,false));
	        mat[0][0]=true;

	        if(p[0]=='*')
	        {
	            mat[0][1]=true;
	        }

	        
	        for(int i=1;i<=lens;i++)
	        {
	            for(int j=1;j<=lenp;j++)
	            {
	                if (s[i-1]==p[j-1] || p[j-1]=='?')
	                {
	                    mat[i][j]=mat[i-1][j-1];
	                }
	                else if (p[j-1]=='*')
	                {
	                    mat[i][j]=mat[i][j-1] || mat[i-1][j];
	                }
	            }
	        }
	        
	        return mat[lens][lenp];
	    }
	};

}

/****************************************************************************************************
                                             Note
DP problem
****************************************************************************************************/