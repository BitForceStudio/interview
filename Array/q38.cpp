/****************************************************************************************************
                                       38. Count and Say        
-----------------------------------------------------------------------------------------------------
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
****************************************************************************************************/

class Solution {
public:
    string countAndSay(int n) {
        // DP
        string rst;
        if (n<=0) return rst;
        rst="1";
        if (n==1) return rst;
        
        vector<int> item;
        vector<int> count;
        for(int i=0;i<n-1;i++)
        {
            int len=rst.size();
            item.push_back(rst[0]-'0');
            count.push_back(1);
            for(int i=1;i<len;i++)
            {
                if (rst[i]==rst[i-1]) count.back()=count.back()+1;
                else
                {
                    item.push_back(rst[i]-'0');
                    count.push_back(1);
                }
            }
            rst=trans(item,count);
            item.clear();
            count.clear();
        }
        return rst;
    }
    
    string trans(vector<int> item, vector<int> count)
    {
        string rst="";
        int len=item.size();
        stringstream ss;
        for(int i=0;i<len;i++)
        {
            ss<<count[i];
            ss<<item[i];
        }
        return ss.str();
    }
};

/****************************************************************************************************
                                             Note
Key: using stringstream
remember to clear the vector
****************************************************************************************************/