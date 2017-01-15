/****************************************************************************************************
                                    10. Regular Expression Matching       
-----------------------------------------------------------------------------------------------------
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isMatch(string s, string p) {
	/*
	This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:

	P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
	P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
	P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
	*/
	        int lens=s.size();
	        int lenp=p.size();
	        if (lens==0 && lenp==0) return true;
	        vector<vector<bool> > qMatch(lens+1,vector<bool>(lenp+1,false));
	        qMatch[0][0]=true;
	        
	        for(int i=0;i<=lens;i++)
	        {
	            for(int j=1;j<=lenp;j++)
	            {
	                if (p[j-1]=='*')
	                {
	                    qMatch[i][j] = qMatch[i][j-2] || (i>0 && qMatch[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.'));
	                }
	                else
	                {
	                    //                
	                    qMatch[i][j] = i>0 && (s[i-1]==p[j-1] || p[j-1]=='.') && qMatch[i-1][j-1];
	                }
	            }
	        }
	        
	        return qMatch[lens][lenp];
	    }
	};

}

/****************************************************************************************************
                                             Note
I don't understand this question... need to review it some time...

****************************************************************************************************/