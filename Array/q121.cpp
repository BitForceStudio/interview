/****************************************************************************************************
                              121. Best Time to Buy and Sell Stock               
-----------------------------------------------------------------------------------------------------
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the 
stock), design an algorithm to find the maximum profit.
****************************************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // keep the min, go through the array
        int len=prices.size();
        if (len<=1) return 0;
        int minval = 2147483647;
        int maxpro = 0;
        for(int i=0;i<len;i++)
        {
            minval = minval<prices[i]?minval:prices[i];
            maxpro = maxpro>(prices[i]-minval)?maxpro:prices[i]-minval;
        }
        return maxpro;
    }
};

/****************************************************************************************************
                                             Note
Go through the array and keep the min value, use current - min, keep the max. 
****************************************************************************************************/