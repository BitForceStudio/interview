/****************************************************************************************************
                                   29. Divide Two Integers          
-----------------------------------------------------------------------------------------------------
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
****************************************************************************************************/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor==0) return 2147483647;                                // special case
        bool sign=((dividend<0&&divisor<0) ||(dividend>0&&divisor>0));    // get sign
        // one special case:  divisor==-1 or 1
        if (divisor==1) return dividend;                                  // special case
        if (divisor==-1)          
        {
            if (dividend==-2147483648) return 2147483647;                 // overflowed, take care of this only problem 
            return -dividend;
        }
        long long dvd=labs(dividend);                                     // here may be tricky, need to use long long, and labs(long abs) to define this. 
        long long dvs=labs(divisor);
        int rst=0;
        while(dvd>=dvs)
        {
            long long mult=1;
            long long temp=dvs;
            while(dvd>=(temp<<1))
            {
                temp<<=1;
                mult<<=1;
            }
            dvd-=temp;
            rst+=mult;
        }
        if (!sign) rst=-rst;
        return rst;
    }
};

/****************************************************************************************************
                                             Note
Remember that, <<1 means *2. 
****************************************************************************************************/