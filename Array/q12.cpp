/****************************************************************************************************
                                     12. Integer to Roman        
-----------------------------------------------------------------------------------------------------
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	/*
	        1000='M';
	        500 ='D';
	        100 ='C';
	        50  ='L';
	        10  ='X';
	        5   ='V';
	        1   ='I';
	*/
	    string intToRoman(int num) {
	        vector<int> order; order.resize(7);
	        vector<char> strOrder; strOrder.resize(7);
	        order[0]=1000; strOrder[0]='M';
	        order[1] =500; strOrder[1]='D'; 
	        order[2] =100; strOrder[2]='C';
	        order[3]  =50; strOrder[3]='L';
	        order[4]  =10; strOrder[4]='X';
	        order[5]   =5; strOrder[5]='V';
	        order[6]   =1; strOrder[6]='I';
	        string rst="";
	        // count 1000s first
	        int ntd = num/1000;
	        for(int i=0;i<ntd;i++) rst=rst+'M';
	        num%=1000;
	        for (int i=2;i<7;i+=2)
	        {
	            int ngk=num/order[i];
	            if (ngk==4)
	            {
	                rst+=strOrder[i];
	                rst+=strOrder[i-1];
	            }
	            else if (ngk==9)
	            {
	                rst+=strOrder[i];
	                rst+=strOrder[i-2];
	            }
	            else if (ngk>=5)
	            {
	                rst+=strOrder[i-1];
	                for(int j=0;j<ngk-5;j++) rst+=strOrder[i];
	            }
	            else
	            {
	                for(int j=0;j<ngk;j++) rst+=strOrder[i];
	            }
	            num%=order[i];
	        }
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
just divided the problem into different conditions. it would be realy easy.

****************************************************************************************************/