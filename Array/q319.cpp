/****************************************************************************************************
                                    319. Bulb Switcher            
-----------------------------------------------------------------------------------------------------
There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every 
second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off 
if it's on). For the ith round, you toggle every i bulb. For the nth round, you only toggle the last 
bulb. Find how many bulbs are on after n rounds.

Example:

Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int bulbSwitch(int n) {
	        return int(sqrt(n));
	        
	        /*
	        if (n<=1) return n;
	        vector<bool> bulb(n,true); // after first round;
	        
	        for(int i=1;i<n;i++)
	        {
	            if (i<=n/2)
	            {
	                for(int j=i;j<n;j+=(i+1))
	                {
	                    bulb[j]=!bulb[j];
	                }
	            }
	            else
	            {
	                bulb[i]=!bulb[i];
	            }
	        }
	        
	        int rst=0;
	        for(int i=0;i<n;i++)
	        {
	            if (bulb[i]) rst++;
	        }
	        
	        return rst;
	        */
	    }
	};

}

/****************************************************************************************************
                                             Note
It is a math problem. I got the idea, but didn't continue...
****************************************************************************************************/