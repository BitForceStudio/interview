/****************************************************************************************************
                                646. Maximum Length of Pair Chain             
-----------------------------------------------------------------------------------------------------
You are given n pairs of numbers. In every pair, the first number is always smaller than the second 
number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can 
be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the 
given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    static bool compare(vector<int>& i,vector<int>& j) { return (i[1]<j[1]); }
	    
	    int findLongestChain(vector<vector<int>>& pairs) {
	        // sort the pairs based on the second element
	        int len=pairs.size();
	        if (len<=1) return len;
	        
	        sort(pairs.begin(),pairs.end(),compare);
	        int rst=1;
	        int curr=pairs[0][1];
	        for(int i=1;i<len;i++)
	        {
	            if (pairs[i][0]>curr)
	            {
	                rst++;
	                curr = pairs[i][1];
	            }
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
it is interval greedy problem. 
the compare have to be static
****************************************************************************************************/