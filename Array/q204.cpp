/****************************************************************************************************
                                       204. Count Primes      
-----------------------------------------------------------------------------------------------------
Description:

Count the number of prime numbers less than a non-negative number, n.

****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int countPrimes(int n) {
	        if (n<2) return 0;
	        int sqn = int(sqrt(n-1));
	        vector<bool> qPrime; qPrime.resize(n-1,true);
	        for(int i=2;i<=sqn;i++)
	        {
	            if (!qPrime[i-2]) continue;
	            for(int j=2*i;j<=n-1;j+=i)   // ***
	            {
	                qPrime[j-2]=false;
	            }
	        }
	        int rst=0;
	        for(int i=0;i<n-1;i++ )
	        {
	            if(qPrime[i]) rst++;
	        }
	        return rst-1;
	    }
	};


	class Solution2 {
	public:
	    int countPrimes(int n) {
	        if(n<=3) return (n-2)>0?(n-2):0;
	        int rst=1;
	        vector<bool> passed(n,false);
	        int tr = sqrt(n);
	        for(int i=3;i<=tr;i+=2)
	        {
	            if(passed[i]) continue;
	            for(int j=i*i;j<n;j+=i)
	            {
	                passed[j]=true;
	            }
	        }
	        for(int i=3;i<n;i+=2) if(!passed[i]) rst++;
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
The idea is simple, be careful about the details. like ***

****************************************************************************************************/