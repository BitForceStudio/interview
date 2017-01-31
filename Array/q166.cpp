/****************************************************************************************************
                               166. Fraction to Recurring Decimal              
-----------------------------------------------------------------------------------------------------
Given two integers representing the numerator and denominator of a fraction, return the fraction in 
string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string fractionToDecimal(int numerator, int denominator) {
	        if (denominator==0) return "inf";
	        
	        string rst="";
	        if (numerator==-2147483648 && denominator==-1)   // ***
	        {
	            rst=to_string(numerator);
	            rst=rst.substr(1,rst.size()-1);
	            return rst;
	        }
	        
	        int left = numerator/denominator;
	        rst = to_string(left);
	        long long right = 0;   // ***
	        long long rpt = 0;
	        long long mod = numerator%denominator;
	        if (mod==0) return rst;
	        
	        if (left==0)   // ***
	        {
	            if((numerator<0 && denominator>0) ||(numerator>0 && denominator<0))
	                rst='-'+rst;
	        }
	        
	        set<int> vmod; vmod.insert(mod);
	        long long curr = mod;
	        rst+='.';
	        while(curr!=0)
	        {
	            right=(curr*10)/denominator;
	            if(right<0) right*=-1;
	            rst+=to_string(right);
	            curr = (curr*10)%denominator;

	            if (vmod.find(curr)!=vmod.end()) 
	            {
	                // found repeat;
	                vmod.clear();
	                long long nrpt=0;
	                while(vmod.find(curr)==vmod.end())
	                {
	                    vmod.insert(curr);
	                    curr = (curr*10)%denominator;
	                    nrpt++;
	                }
	                
	                rst.insert(rst.size()-nrpt,"(");
	                rst+=')';
	                return rst;
	            }
	            vmod.insert(curr);
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Lots of catches... 
****************************************************************************************************/