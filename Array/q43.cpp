/****************************************************************************************************
                                      43. Multiply Strings              
-----------------------------------------------------------------------------------------------------
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and 
num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
****************************************************************************************************/

class Solution {
public:
// another solution: maxnum integer is 2147483647 so it can hold 9999*9999 maxnum. so, divided the strings into 4 digits blocks, then solve the problem.
    string multiply(string num1, string num2) {
        string rst="";
        int len1=num1.size()-1;
        int len2=num2.size()-1;
        if (len1<0 || len2<0) return rst;
        
        for(int i=len1;i>=0;i--)
        {
            string tmp;
            if (num1[i]!='0')
            {
                tmp=times(num2,num1[i],len1-i);
            }
            else tmp="0";
            rst=add(rst,tmp);
        }
        int i=0;
        while(rst[i]=='0' && i<rst.size()-1) i++;   // ***1
        rst=rst.substr(i,rst.size()-i);
        return rst;
    }
    string times(string nums, char s, int c)
    {
        // return the string of s multiply nums and add c's zeros after 
        string rst; 
        int ml = s-'0';
        if (ml==0) return rst;
        rst.resize(nums.size()+1+c,'0');
        int len=nums.size()-1;
        int carry = 0;
        for(int i=len;i>=0;i--)
        {
            int cml = nums[i]-'0';
            int cur = cml*ml+carry;
            rst[i+1] = cur%10+'0';
            carry = int(cur/10);
        }
        if (carry>0) rst[0] = carry+'0';
        return rst;
    }
    string add(string num1, string num2)
    {
        // return the string of num1+num2
        int ic1=num1.size()-1;
        int ic2=num2.size()-1;
        int maxlen = ic1>ic2?ic1:ic2; maxlen++;
        string rst=""; rst.resize(maxlen,'0'); 
        maxlen--;
        int carry=0;
        while(ic1>=0 && ic2>=0)
        {
            int n1=num1[ic1]-'0';
            int n2=num2[ic2]-'0';
            int r=n1+n2+carry;
            rst[maxlen]=r%10+'0';
            carry=r>=10;                       // ***2
            ic1--; ic2--; maxlen--;
        }
        if (ic1<0)
        {
            while(ic2>=0)
            {
                int n2=num2[ic2]-'0';
                int r=n2+carry;
                rst[maxlen]=r%10+'0';
                carry=r>=10;
                ic2--; maxlen--;
            }
        }
        else if (ic2<0)
        {
            while(ic1>=0)
            {
                int n1=num1[ic1]-'0';
                int r=n1+carry;
                rst[maxlen]=r%10+'0';
                carry=r>=10;
                ic1--; maxlen--;
            }
        }
        if (carry>0) rst[0]=carry;
        return rst;
    }
};

/****************************************************************************************************
                                             Note
***1: because I used a method to count maxnum lenth, so the head may contain a zero. remove them
***2: it must be greater or equal to!!!! that just be stupid. 
****************************************************************************************************/