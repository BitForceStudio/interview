/****************************************************************************************************
                                551. Student Attendance Record I        
-----------------------------------------------------------------------------------------------------
You are given a string representing an attendance record for a student. The record only contains the 
following three characters:

'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or 
more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool checkRecord(string s) {
	        int len = s.size();
	        if (len==0) return true;
	        
	        int na=0;
	        int cl = 0;
	        for(int i=0;i<len;i++)
	        {
	            if (s[i]=='A') na++;
	            if (s[i]=='L')
	                cl++;
	            else cl=0;
	            if (cl>2 || na>1) return false;
	            
	        }
	        return true;
	    }
	};

}

/****************************************************************************************************
                                             Note

****************************************************************************************************/