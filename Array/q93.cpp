/****************************************************************************************************
                                 93. Restore IP Addresses            
-----------------------------------------------------------------------------------------------------
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> restoreIpAddresses(string s) {
	        int len=s.size();
	        vector<string> rst;
	        if (len<4 || len>12) return rst;
	        
	        vector<string> curr;
	        bool tmp = findIp(s, len, 0,curr,rst);
	        
	        return rst;
	    }
	    
	    bool findIp(string s, int len, int st, vector<string>& curr, vector<string>& rst)
	    {
	        if (curr.size()==4 && st==s.size())
	        {
	            string crst = "";
	            for(int i=0;i<3;i++)
	                crst+=curr[i]+".";
	            crst+=curr[3];
	            rst.push_back(crst);
	            return true;
	        }
	        else if (curr.size()==4 && st!=s.size()) return false;
	        
	        bool qfound = false;
	        for(int ic = 1;ic<=3;ic++)
	        {
	            if (st+ic<=len)                      // ***
	            {
	                string stmp = s.substr(st,ic);
	                int itmp = stoi(stmp);
	                if (itmp>=0 && itmp<=255)
	                {
	                    curr.push_back(s.substr(st,ic));
	                    bool tmp = findIp(s,len,st+ic,curr,rst);
	                    if (tmp) qfound = true;
	                    curr.pop_back();
	                }
	                else break;
	            }
	            else break;
	        }
	        
	        return qfound;
	    }
	};

}

/****************************************************************************************************
                                             Note
*** here has to be less or equal to. think about why.
****************************************************************************************************/