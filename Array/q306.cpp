/****************************************************************************************************
                                    306. Additive Number           
-----------------------------------------------------------------------------------------------------
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, 
each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is 
invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive 
number.

Follow up:
How would you handle overflow for very large input integers?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isAdditiveNumber(string num) {
	        int len = num.size();
	        if (len<3) return false;
	        
	        for(int i=1;i<=len/2;i++)
	        {
	            for(int j=1;j<=(len-i)/2;j++)  // **
	            {
	                if (check(num.substr(0,i),num.substr(i,j),num.substr(i+j))) return true;
	            }
	        }
	        return false;
	    }
	    
	    bool check(string num1, string num2, string rest)
	    {
	        if ((num1[0]=='0' && num1.size()>1) || (num2[0]=='0' && num2.size()>1) || (rest[0]=='0' && rest.size()>1) || rest.size()<num2.size()) return false;  // ***
	        string addRst = strAdd(num1,num2);
	        int len=rest.size();
	        int rlen = addRst.size();
	        if (rlen>len) return false;
	        if (rest.substr(0,rlen)!=addRst) return false;
	        if (rlen==len) return true;
	        return check(num2,addRst,rest.substr(rlen));
	    }
	    
	    string strAdd(string num1, string num2)  // ****
	    {
	        int curr=0;
	        string rst;
	        int len1=num1.size()-1;
	        int len2=num2.size()-1;
	        
	        while(len1>=0 && len2>=0)
	        {
	            int add = num1[len1]+num2[len2]-'0'-'0'+curr;
	            if (add>9) curr=1;
	            else curr=0;
	            rst=char(add%10+'0')+rst;
	            len1--;
	            len2--;
	        }
	        
	        while(len1>=0)
	        {
	            if (curr>0)
	            {
	                int add = num1[len1]-'0'+curr;
	                if (add>9) curr=1;
	                else curr=0;
	                rst=char(add%10+'0')+rst;
	            }
	            else rst=num1[len1]+rst;
	            len1--;
	        }
	        
	        while(len2>=0)
	        {
	            if (curr>0)
	            {
	                int add = num2[len2]-'0'+curr;
	                if (add>9) curr=1;
	                else curr=0;
	                rst=char(add%10+'0')+rst;
	            }
	            else rst=num2[len2]+rst;
	            len2--;
	        }
	        
	        if (curr==1) rst="1"+rst;
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
**    the first j could be 1, less than i
***   if num1 or num2 =='0', it is possible
****  string add, it need to be remembered.
****************************************************************************************************/