/****************************************************************************************************
                                  273. Integer to English Words           
-----------------------------------------------------------------------------------------------------
Convert a non-negative integer to its english words representation. Given input is guaranteed to be 
less than 2^31 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less 
than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? 
Or 1000010? (middle chunk is zero and should not be printed out)
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string numberToWords(int num) {
	        if (num==0) return "Zero";   // **
	        map<int,string> numberstr;
	        numberstr[0]="Zero";   numberstr[10]="Ten";
	        numberstr[1]="One";    numberstr[11]="Eleven";
	        numberstr[2]="Two";    numberstr[12]="Twelve";      numberstr[20]="Twenty";
	        numberstr[3]="Three";  numberstr[13]="Thirteen";    numberstr[30]="Thirty";
	        numberstr[4]="Four";   numberstr[14]="Fourteen";    numberstr[40]="Forty";
	        numberstr[5]="Five";   numberstr[15]="Fifteen";     numberstr[50]="Fifty";
	        numberstr[6]="Six";    numberstr[16]="Sixteen";     numberstr[60]="Sixty";
	        numberstr[7]="Seven";  numberstr[17]="Seventeen";   numberstr[70]="Seventy";
	        numberstr[8]="Eight";  numberstr[18]="Eighteen";    numberstr[80]="Eighty";
	        numberstr[9]="Nine";   numberstr[19]="Nineteen";    numberstr[90]="Ninety";
	        numberstr[100] ="Hundred";
	        numberstr[1000]="Thousand";
	        numberstr[1000000]="Million";
	        numberstr[1000000000]="Billion";
	        
	        string rst="";
	        int b=1;
	        while (num>0)
	        {
	            int curr=num%1000;
	            if (curr!=0)                              // ***
	            {
	                if (b>1) rst=numberstr[b] +" "+rst;
	    
	                if (curr<=20) 
	                    rst=(curr==0?"":(numberstr[curr] + " "))+rst;
	                else if (curr >20 && curr <=99) 
	                {
	                    int it=curr%10;
	                    curr-=it;
	                    rst=numberstr[curr] + " " + (it==0?"":(numberstr[it] + " ")) + rst;
	                }
	                else
	                {
	                    int tt=curr%100;
	                    curr=curr/100;
	                    if (tt<=20) rst=(tt==0?"":(numberstr[tt] + " "))+rst;
	                    else
	                    {
	                        int it=tt%10;
	                        tt-=it;
	                        rst=numberstr[tt] + " " + (it==0?"":(numberstr[it] + " ")) + rst;
	                    }
	                    rst=numberstr[curr] + " " + numberstr[100] + " "+rst;
	                    
	                }
	            }
	            num/=1000;
	            b*=1000;
	        }
	        return rst.substr(0,rst.size()-1);
	    }
	};

}

/****************************************************************************************************
                                             Note
**  output Zero
*** here need to be careful. 
and the space, 
****************************************************************************************************/