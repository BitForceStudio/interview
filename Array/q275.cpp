/****************************************************************************************************
                                      275. H-Index II       
-----------------------------------------------------------------------------------------------------
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize 
your algorithm?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int hIndex(vector<int>& citations) {
	        int len=citations.size();
	        if(len==0) return 0;
	        
	        int i=len-1;
	        for(;i>=0;i--) 
	            if (citations[i]<(len-i)) break;  // ***
	        
	        return len-i-1;
	    }
	};

}

/****************************************************************************************************
                                             Note
*** should less than len-i.
****************************************************************************************************/