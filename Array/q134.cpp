/****************************************************************************************************
                                134. Gas Station             
-----------------------------------------------------------------------------------------------------
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its 
next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	        // current min value. if fault start from there
	        int len=gas.size();
	        int index = 0;

	        for(;index<len;index++)
	        {
	            int gasleft = 0;
	            bool qfound=true;
	            for(int i=index;i<len+index;i++)
	            {
	                int curr=i<len?i:i-len;
	                gasleft+=gas[curr]-cost[curr];
	                if (gasleft<0) 
	                {
	                    index=i;
	                    qfound=false;
	                    break;
	                }
	                
	            }
	            if (qfound) return index;
	        }
	        
	        return -1;
	    }
	};

}

/****************************************************************************************************
                                             Note
keep the minimum one, and use it as the new start.
*** 
acturally, if one cannot reach, then start from next one. because it cannot reach so the sum of 
previous ones are not enough.
****************************************************************************************************/