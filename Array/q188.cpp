/****************************************************************************************************
                             188. Best Time to Buy and Sell Stock IV             
-----------------------------------------------------------------------------------------------------
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you 
buy again).
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if (len<=1 || k<1) return 0;
        // corner case. 
        int rst=0;
        if (k>=len/2)   // *** corner case
        {
            for(int i=1;i<len;i++)
            {
                if (prices[i]-prices[i-1]>0) rst+=(prices[i]-prices[i-1]);
            }
            return rst;
        }
        
        //vector<int> dpp(len,0);
        vector<int> dpc(len,0);

        for(int kk=1;kk<=k;kk++)
        {
            int tmpmax= -prices[0];
            for(int i=1;i<len;i++)
            {
                int pp = dpc[i];
                dpc[i] = max(dpc[i-1], prices[i]+tmpmax);
                tmpmax = max(tmpmax,pp-prices[i]);
                rst=max(rst,dpc[i]);
            }
            //dpp=dpc;
        }
        
        return rst;
    }
};

}

/****************************************************************************************************
                                             Note
Get this idea from the III. need to remember how to solve DP problem...
****************************************************************************************************/