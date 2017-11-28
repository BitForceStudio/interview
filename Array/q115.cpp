/****************************************************************************************************
                               115. Distinct Subsequences              
-----------------------------------------------------------------------------------------------------
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int numDistinct(string s, string t) {
	        // dp problem
	        int lens = s.size();
	        int lent = t.size();
	        if (lens==0) return 0;
	        if (lent==0) return 1;
	        
	        vector<vector<int> > matrix(lent+1,vector<int>(lens+1,0));
	        
	        for(int j=0;j<lens+1;j++) matrix[0][j]=1;  // first row, all ones
	        
	        for(int i=0;i<lent;i++)
	        {
	            for(int j=i;j<lens;j++)
	            {
	                matrix[i+1][j+1]=matrix[i+1][j];
	                if (s[j]==t[i])
	                    matrix[i+1][j+1]+=matrix[i][j];
	            }
	        }
	        return matrix[lent][lens];
	    }
	};

	class TLE_Solution {
	public:
	    int numDistinct(string s, string t) {
	        if(t.size()>s.size()) return 0;
	        int rst=0;
	        
	        for(int i=0;i<s.size();i++)
	        {
	            if(s[i]==t[0]) helper(s,t,i+1,1,rst);
	        }
	        return rst;
	    }
	    
	    void helper(string& s,string& t, int ss, int st, int& rst)
	    {
	        if(st==t.size())
	        {
	            rst++;
	            return;
	        }
	        if(ss>=s.size()) return;   
	        for(int i=ss;i<s.size();i++)
	        {
	            if(s[i]==t[st])
	            {
	                helper(s,t,i+1,st+1,rst);
	            }
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
The idea is dp. but store the number of matches. explain as follows:
The idea is the following:

we will build an array mem where mem[i+1][j+1] means that S[0..j] contains T[0..i] that many times 
as distinct subsequences. Therefor the result will be mem[T.length()][S.length()].
we can build this array rows-by-rows:
the first row must be filled with 1. That's because the empty string is a subsequence of any string 
but only 1 time. So mem[0][j] = 1 for every j. So with this we not only make our lives easier, but 
we also return correct value if T is an empty string.
the first column of every rows except the first must be 0. This is because an empty string cannot 
contain a non-empty string as a substring -- the very first item of the array: mem[0][0] = 1, because 
an empty string contains the empty string 1 time.
So the matrix looks like this:

  S 0123....j
T +----------+
  |1111111111|
0 |0         |
1 |0         |
2 |0         |
. |0         |
. |0         |
i |0         |
From here we can easily fill the whole grid: for each (x, y), we check if S[x] == T[y] we add the 
previous item and the previous item in the previous row, otherwise we copy the previous item in the 
same row. The reason is simple:

if the current character in S doesn't equal to current character T, then we have the same number of 
distinct subsequences as we had without the new character.
if the current character in S equal to the current character T, then the distinct number of 
subsequences: the number we had before plus the distinct number of subsequences we had with less 
longer T and less longer S.

An example:
S: [acdabefbc] and T: [ab]

first we check with a:

           *  *
      S = [acdabefbc]
mem[1] = [0111222222]
then we check with ab:

               *  * ]
      S = [acdabefbc]
mem[1] = [0111222222]
mem[2] = [0000022244]
And the result is 4, as the distinct subsequences are:

      S = [a   b    ]
      S = [a      b ]
      S = [   ab    ]
      S = [   a   b ]
****************************************************************************************************/