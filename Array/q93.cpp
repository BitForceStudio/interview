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
	                if (stmp[0]=='0' && ic>1) break; // ***
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

	class Solution2 {
	public:
	    vector<string> restoreIpAddresses(string s) {
	        vector<string> rst;
	        if (s.size()<4 || s.size()>12) return rst;
	        
	        helper(s,rst,"",0,4);
	        return rst;
	    }
	    
	    void helper(string s, vector<string>& rst, string curr, int i, int left)
	    {
	        if (left==0 && i!=s.size()) return;
	        if (left==0 && i==s.size())
	        {
	            curr = curr.substr(0,curr.size()-1);
	            rst.push_back(curr);
	            return;
	        }
	        
	        if (s[i]=='0')
	        {
	            helper(s,rst,curr+"0.",i+1,left-1);
	        }
	        else if (s[i]=='1')
	        {
	            helper(s,rst,curr+s.substr(i,1)+".",i+1,left-1);
	            if (i+2<=s.size()) helper(s,rst,curr+s.substr(i,2)+".",i+2,left-1);
	            if (i+3<=s.size()) helper(s,rst,curr+s.substr(i,3)+".",i+3,left-1);
	        }
	        else if (s[i]>='3')
	        {
	            helper(s,rst,curr+s.substr(i,1)+".",i+1,left-1);
	            if (i+2<=s.size()) helper(s,rst,curr+s.substr(i,2)+".",i+2,left-1);
	        }
	        else if (s[i]=='2')
	        {
	            helper(s,rst,curr+s.substr(i,1)+".",i+1,left-1);
	            if (i+2<=s.size()) helper(s,rst,curr+s.substr(i,2)+".",i+2,left-1);
	            if (i+3<=s.size() && s[i+1]<'5') helper(s,rst,curr+s.substr(i,3)+".",i+3,left-1);
	            if (i+3<=s.size() && s[i+1]=='5' && s[i+2]<='5') helper(s,rst,curr+s.substr(i,3)+".",i+3,left-1);
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
*** here has to be less or equal to. think about why.
*** if it is zero, ic should just be 1. 
****************************************************************************************************/