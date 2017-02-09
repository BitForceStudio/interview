/****************************************************************************************************
                                   313. Super Ugly Number          
-----------------------------------------------------------------------------------------------------
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of 
size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 
super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int nthSuperUglyNumber(int n, vector<int>& primes) {
	        int len=primes.size();
	        if (len==0) return 1;
	        
	        vector<int> tmp(len,0);
	        
	        //sort(primes.begin(),primes.end());
	        vector<int> rst(n,0); rst[0]=1;
	        int minVal=2147483647,curr=0;
	        vector<int> minInd;
	        for(int i=1;i<n;i++)
	        {
	            // find min
	            minVal=2147483647;
	            minInd.clear();
	            for(int j=0;j<len;j++)
	            {
	                curr=rst[tmp[j]]*primes[j];
	                if (curr==minVal) minInd.push_back(j);
	                else if (curr<minVal)
	                {
	                    minInd.clear();
	                    minInd.push_back(j);  // ***
	                    minVal=curr;
	                }
	            }
	            rst[i]=minVal;
	            for(int j=0;j<minInd.size();j++) 
	                tmp[minInd[j]]++;
	        }
	        return rst[n-1];
	    }
	};

}

/****************************************************************************************************
                                             Note
*** here may be more than one... remember it. 
****************************************************************************************************/