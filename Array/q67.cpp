/****************************************************************************************************
                                        67. Add Binary       
-----------------------------------------------------------------------------------------------------
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
****************************************************************************************************/

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size()==0) return b;
        if (b.size()==0) return a;
        
        int l1 = a.size()-1;
        int l2 = b.size()-1;
        string rst;
        int carry=0;
        while(l1>-1 && l2>-1)
        {
            int c = a[l1]+b[l2] + carry-'0'-'0';
            
            if (c==0)
            {
                carry=0;
                rst='0'+rst;
            }
            else if (c==1)
            {
                carry=0;
                rst='1'+rst;
            }
            else if (c==2)
            {
                carry=1;
                rst='0'+rst;
            }
            else
            {
                carry=1;
                rst='1'+rst;
            }
            
            l1--;
            l2--;
        }
        
        if (l1<0)
        {
            if(carry==1)
            {
                while (l2>=0)
                {
                    int c = carry+b[l2]-'0';
                    if (c==0)
                    {
                        carry=0;
                        rst='0'+rst;
                    }
                    else if (c==1)
                    {
                        carry=0;
                        rst='1'+rst;
                    }
                    else
                    {
                        carry=1;
                        rst='0'+rst;
                    }
                    l2--;
                }
            }
            else
            {
                while (l2>=0)
                {
                    rst=b[l2]+rst;
                    l2--;
                }
            }
        }
        
        if (l2<0)
        {
            if(carry==1)
            {
                while (l1>=0)
                {
                    int c = carry+a[l1]-'0';
                    if (c==0)
                    {
                        carry=0;
                        rst='0'+rst;
                    }
                    else if (c==1)
                    {
                        carry=0;
                        rst='1'+rst;
                    }
                    else
                    {
                        carry=1;
                        rst='0'+rst;
                    }
                    l1--;
                }
            }
            else
            {
                while (l1>=0)
                {
                    rst=a[l1]+rst;
                    l1--;
                }
            }
        }
        if (carry==1) rst='1'+rst;
        return rst;
    } 
};

/****************************************************************************************************
                                             Note
Be careful about adding one string. and considering the all possibility of the results.
****************************************************************************************************/