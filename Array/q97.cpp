/****************************************************************************************************
                                   97. Interleaving String       
-----------------------------------------------------------------------------------------------------
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isInterleave(string s1, string s2, string s3) {
	        // dp problem
	        int len1=s1.size();
	        int len2=s2.size();
	        int len3=s3.size();
	        
	        if (len1==0 && len2==0 && len3==0) return true;
	        if (len1+len2!=len3) return false;
	        
	        vector<vector<bool> > dp(len1+1,vector<bool>(len2+1,false));
	        
	        int i3=1;
	        int i2=0;
	        dp[0][0]=true;
	        // dp[i1][i2] true: s1[<i1] & s2[<i2] = s3[<i1+i2]
	        while(i3<=len3)
	        {
	            for(int i1=max(i3-len2,0);i1<=len1 && i1<=i3;i1++)
	            {
	                i2=i3-i1;
	                dp[i1][i2] = (i1>=1 && dp[i1-1][i2] && s1[i1-1]==s3[i3-1]) ||
	                             (i2>=1 && dp[i1][i2-1] && s2[i2-1]==s3[i3-1]);
	            }
	            i3++;
	        }
	        return dp[len1][len2];
	    }
	};

}

/****************************************************************************************************
                                             Note
Get the idea from the solution...
the summary is:
BFS solution (6ms)

Imagine a grid, which x-axis and y-axis are s1 and s2, matching s3 is the same as
finding a path from (0,0) to (len1, len2). It actually becomes a
BFS on grid. Since we don't need exact paths, a HashSet of
coordinates is used to eliminate duplicated paths.

public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length(),
            len2 = s2.length(),
            len3 = s3.length();
        if (len1 + len2 != len3) return false;
        Deque<Integer> queue = new LinkedList<>();
        int matched = 0;
        queue.offer(0);
        Set<Integer> set = new HashSet<>();
        while (queue.size() > 0 && matched < len3) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int p1 = queue.peek() / len3,
                    p2 = queue.peek() % len3;
                queue.poll();
                if (p1 < len1 && s1.charAt(p1) == s3.charAt(matched)) {
                    int key = (p1 + 1) * len3 + p2;
                    if (!set.contains(key)) {
                        set.add(key);
                        queue.offer(key);
                    }
                }
                if (p2 < len2 && s2.charAt(p2) == s3.charAt(matched)) {
                    int key = p1 * len3 + (p2 + 1);
                    if (!set.contains(key)) {
                        set.add(key);
                        queue.offer(key);
                    }
                }
            }
            matched++;
        }
        return queue.size() > 0 && matched == len3;
    }
}
DFS solution with memorization (2ms)

This looks slow but is actually faster than BFS! Think about it carefully, in this
particular problem, search always ends at the same depth. DFS with memorization
searches about the same amount of paths with the same length as BFS, if it is doesn't
terminate on the first path found. Without the queue operations, the overall cost
is only smaller if we don't count call stack. The most significant runtime reducer is
probably the early termination

public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        HashSet<Integer> cache = new HashSet<Integer>();
        return isInterleave0(s1, s2, s3, 0, 0, cache);
    }

    private boolean isInterleave0(String s1, String s2, String s3, int p1, int p2, HashSet<Integer> cache) {
        if (p1 + p2 == s3.length())
            return true;
        if (cache.contains(p1 * s3.length() + p2))
            return false;
        // no need to store actual result.
        // if we found the path, we have already terminated.
        cache.add(p1 * s3.length() + p2);
        boolean match1 = p1 < s1.length() && s3.charAt(p1 + p2) == s1.charAt(p1);
        boolean match2 = p2 < s2.length() && s3.charAt(p1 + p2) == s2.charAt(p2);
        if (match1 && match2)
            return isInterleave0(s1, s2, s3, p1 + 1, p2, cache) ||
                   isInterleave0(s1, s2, s3, p1, p2 + 1, cache);
        else if (match1)
            return isInterleave0(s1, s2, s3, p1 + 1, p2, cache);
        else if (match2)
            return isInterleave0(s1, s2, s3, p1, p2 + 1, cache);
        else
            return false;
    }
}
2d DP solution (6ms)

It's an interesting practice. There are further optimization could be done to
reduce cache matrix to 1d. However doing DP for this problem is tedious and not
seem to worth the trouble.

public class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int len1 = s1.length(),
            len2 = s2.length(),
            len3 = s3.length();
        if (len1 + len2 != len3) return false;
        // cache[i][j] == true means first i + j chars are matched by
        // first j chars from s1 and first i chars from s2
        boolean[][] cache = new boolean[len2 + 1][len1 + 1];
        cache[0][0] = true; // empty and empty matches empty
        int m3 = 1; // matched length, m1 and m2 are similar
        while (m3 <= len3) {
            // this loop fill in cache matrix from left-top to right-bottom, diagonally.
            // note that loop conditions are pretty tricky here.
            for (int m1 = Math.max(m3 - len2, 0); m1 <= len1 && m1 <= m3; m1++) {
                int m2 = m3 - m1;
                cache[m2][m1] =
                    m1 > 0 && cache[m2][m1 - 1] && s3.charAt(m3 - 1) == s1.charAt(m1 - 1) ||
                    m2 > 0 && cache[m2 - 1][m1] && s3.charAt(m3 - 1) == s2.charAt(m2 - 1);
            }
            m3++;
        }
        return cache[len2][len1];
    }
}
****************************************************************************************************/