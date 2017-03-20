/****************************************************************************************************
                                132. Palindrome Partitioning II          
-----------------------------------------------------------------------------------------------------
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class MySolution {
	public:
	    int minCut(string s) {
	        if (s.size()==1) return 0;
	        int maxmin=s.size()-1;
	        int rst=helper(s,0,maxmin);
	        return rst;
	    }
	    
	    int helper(string s, int bg, int& maxmin) 
	    {
	        int cmin=s.size()-1-bg;
	        if (cmin<=0) return 0;
	        for(int i=bg;i<s.size();i++)
	        {
	            if (isPalindrome(s,bg,i)) 
	            {
	                if (i==s.size()-1) return 0;     // if bg to end is palindrome, return 0
	                int currmin = 1+helper(s,i+1);
	                cmin=min(cmin,currmin);
	            }
	        }
	        return cmin;
	    }
	    
	    bool isPalindrome(string s,int i,int j)
	    {
	        if (i==j) return true;
	        while (i<j) // ***
	        {
	            if (s[i]!=s[j]) return false;
	            i++;j--;
	        }
	        return true;
	    }
	};

	class BetterSolution {
	public:
	    int minCut(string s) {
	        if (s.size()==1) return 0;
	        int len=s.size();
	        vector< vector<bool> > pal(len,vector<bool>(len,false));
	        vector< int > dp(len); // min value on i
	        for(int i=0;i<len;i++)
	        {
	            dp[i]=i;
	            for(int j=0;j<=i;j++)
	            {
	                if (s[i]==s[j] && (i-j<2 || pal[i-1][j+1]))  // ****
	                {
	                    pal[i][j] = true;
	                    
	                    if (j==0) dp[i]=0;
	                    else
	                    {
	                        dp[i] = min(dp[i],1+dp[j-1]);    // ****
	                    }
	                }
	            }
	        }
	        
	        return dp[len-1];
	    }
	};

}

/****************************************************************************************************
                                             Note
***: the problem is that i should less than j. 
My solution is too slow. the better one is dp. dp matrix store the boolean value of s(i->j) is 
palindrome or not. 
Then the min is min(current min, dp[i][j]+d[j+1]) where d[j+1] store the min cut <=i
**** here is clever part, use the matrix to find the palindrome quickly
**** 
The better soluiton is follows, where I don't fully understand.  

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};
****************************************************************************************************/