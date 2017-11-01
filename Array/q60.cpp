/****************************************************************************************************
                                    60. Permutation Sequence         
-----------------------------------------------------------------------------------------------------
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string getPermutation(int n, int k) {
            string rst;
            vector<int> arr(n,0);
            int m=1;
            for(int i=0;i<n;i++)
            {
                arr[i]=i+1;
                if (i>1) m*=i;
            }
            k--;
            for(int i=0;i<n-1;i++)
            {
                int c = k/m;
                rst+=arr[c]+'0';
                arr.erase(arr.begin()+c);
                k%=m;
                m/=(n-i-1);
            }
            rst+=arr[0]+'0';
            return rst;
	    }
	};

}

////////////////////// another solution
class Solution {
public:
    string getPermutation(int n, int k) {
        string rst;
        if (n==0 || k>tmult(n)) return rst;
        if (n==1) return "1";
        rst="";
        vector<int> seed; seed.resize(n);
        vector<bool> qseed; qseed.resize(n,true);
        for(int i=1;i<=n;i++)
        {
            seed[i-1]=i;
        }
        int m=0,d=0;
        int c = tmult(n-1);
        int curr = 0;
        k=k-1;
        for(int i=0;i<n-1;i++)
        {
            d = index(qseed, int(k/c));
            curr = seed[d];
            rst+=char(curr+'0');
            //return rst;
            qseed[d]=false;
            
            k=k%c;
            c/=(n-i-1);
        }
        d = index(qseed, 0);
        rst+=char(seed[d]+'0');
        return rst;
    }
    
    int index(vector<bool>& qs, int d)
    {
        int tmp=-1;
        int rst=0;
        for(int i=0;i<qs.size();i++)
        {   
            if (!qs[i]) continue;
            if (qs[i]) tmp++;
            if (d==tmp) { rst=i; break;}
        }
        return rst;
    }
    
    int tmult(int n)
    {
        int rst = 1;
        for(int i=1;i<=n;i++)
            rst*=i;
        return rst;
    }
};

/****************************************************************************************************
                                             Note
It should be ok right away, but:

** need to be careful. 
****************************************************************************************************/