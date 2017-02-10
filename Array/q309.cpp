/****************************************************************************************************
                 309. Best Time to Buy and Sell Stock with Cooldown           
-----------------------------------------------------------------------------------------------------
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
(ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before 
you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maxProfit(vector<int>& prices) {
	        int len=prices.size();
	        if (len<=1) return 0;
	        vector<int> buy(len,0);
	        vector<int> rst(len,0);
	        vector<int> sel(len,0);
	        
	        buy[0]=-prices[0];
	        rst[0]=0;
	        sel[0]=-prices[0]-1;
	        for(int i=1;i<len;i++)
	        {
	            buy[i]=max((rst[i-1]-prices[i]),buy[i-1]);
	            sel[i]=buy[i-1]+prices[i];
	            rst[i]=max(sel[i-1],rst[i-1]);
	        }
	        
	        return max(max(buy[len-1],rst[len-1]),sel[len-1]);
	    }
	};

}

/****************************************************************************************************
                                             Note
there are 3 stages: 
      __
     |  | 
     ->[rst]<
      /       \
 _   /         \
| | v           \
->[buy] -----> [sell]

the code represent the the process, just keep the max for the current stage.
****************************************************************************************************/