/****************************************************************************************************
                                        135. Candy     
-----------------------------------------------------------------------------------------------------
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int candy(vector<int>& ratings) {
	        // find the local minimum, then add the candy on both ways, meet the peek, peek pick the greator one. 
	        
	        int len=ratings.size();
	        if (len<=1) return len;
	        int rst=0;
	        int s=0,t=1; // s: peak, t: villy
	        // find first peak
	        vector<int> cd(len,1);
	        while(s<len-1 && ratings[s+1]>ratings[s]) 
	        {
	            cd[s+1]=cd[s]+1;
	            s++;
	        }
	        t=s+1;
	        
	        while(s<len && t<len)
	        {
	            // homo decreasing
	            while(t<len-1 && ratings[t+1]<ratings[t]) t++;
	            for(int i=t-1;i>s;i--) 
	            {
	                cd[i]=cd[i+1]+1;
	            }
	            
	            // check peak
	            if (s+1<len)
	            {
	                if(ratings[s+1]!=ratings[s])
	                    cd[s]=max(cd[s+1]+1,cd[s]);  
	            }

	            // check equals
	            while(t<len-1 && ratings[t+1]==ratings[t])
	            {
	                cd[t+1]=1;
	                t++;
	            }
	            
	            // find next peak, homo increasing
	            s=t;
	            while(s<len-1 && ratings[s+1]>ratings[s])
	            {
	                cd[s+1]=cd[s]+1;
	                s++;
	            }
	            t=s+1;
	        }
	        for(int c:cd) rst+=c;
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
equal: if equals, it could be peak, or villy for next. 
peak: pick the greater one. 
****************************************************************************************************/