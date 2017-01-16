/****************************************************************************************************
                                      231. Power of Two       
-----------------------------------------------------------------------------------------------------
Given an integer, write a function to determine if it is a power of two.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isPowerOfTwo(int n) {
	        if (n<=0) return false;
	        if (n==1) return true;

	        while(n>1)
	        {
	            if (n%2!=0) return false;
	            n/=2;
	        }
	        return true;
	    }
	};

	class Solution {
	public:
	    bool isPowerOfTwo(int n) {
	        if (n<=0) return false;
	        if (n==1) return true;
	        if (n%2!=0) return false;
	        
	        vector<int> twopn(5,0);
	        twopn[0]=65536;
	        twopn[1]=256;
	        twopn[2]=16;
	        twopn[3]=4;
	        twopn[4]=2;
	        for(int i=0;i<5;i++)
	        {
	            if (n==n%twopn[i]) continue;
	            if (n%twopn[i]!=0) return false;  
	            n/=twopn[i];
	        }
	        return n==1;
	    }
	};

}

/****************************************************************************************************
                                             Note
second one need to be careful designed. 
****************************************************************************************************/