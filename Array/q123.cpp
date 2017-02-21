/****************************************************************************************************
                               123. Best Time to Buy and Sell Stock III              
-----------------------------------------------------------------------------------------------------
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you 
buy again).
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maxProfit(vector<int>& prices) {
	        // DP problem
	        // dp[k][i]: max profit until ith price using at most k transaction
	        // dp[k][i] = max(dp[k][i-1],prices[i]+max(dp[k-1][j]-price[j]))
	        //                do nothing   sell at i while buy from j
	        int len = prices.size();
	        if (len<=1) return 0;
	        int maxprof = 0;
	        int KK=2;
	        int rst=0;
	        vector<vector<int> > dp(KK+1,vector<int>(len+1,0));
	        for(int k=1;k<=KK;k++)
	        {
	            int tmpmax = dp[k-1][0]-prices[0];
	            for(int i=1;i<len;i++)
	            {
	                dp[k][i] = max(dp[k][i-1],prices[i]+tmpmax);
	                tmpmax=max(tmpmax,dp[k-1][i]-prices[i]);
	                rst=max(rst,dp[k][i]);
	            }
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Get this idea from the solution. DP problem is my short leg...need to do more practice...
****************************************************************************************************/