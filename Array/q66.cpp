/****************************************************************************************************
                                         66. Plus One    
-----------------------------------------------------------------------------------------------------
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
****************************************************************************************************/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits[0]==0) 
        {
            digits[0]=1; 
            return digits;
        }
        
        int len = digits.size();
        for(int i=len-1;i>=0;i--)
        {
            int rst=digits[i]+1;
            if (rst<=9) 
            {
                digits[i] = rst;
                break;
            }
            else if (rst>9 && i>0)
            {
                digits[i]=0;
            }
            else if (rst>9 && i==0)
            {
                digits[0]=1;
                digits.push_back(0);
            }
        }
        return digits;
    }
};

/****************************************************************************************************
                                             Note
be careful about the i-- and i++
****************************************************************************************************/