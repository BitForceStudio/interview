/****************************************************************************************************
                              122. Best Time to Buy and Sell Stock II              
-----------------------------------------------------------------------------------------------------
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, 
buy one and sell one share of the stock multiple times). However, you may not engage in multiple 
transactions at the same time (ie, you must sell the stock before you buy again).
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int maxProfit(vector<int>& prices) {
	        int rst=0;
	        if (prices.size()<=1) return rst;
	        for(int i=1;i<prices.size();i++)
	        {
	            rst+=max((prices[i]-prices[i-1]),0);
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
profit is high price - low price. so, just add when it increasing.
****************************************************************************************************/