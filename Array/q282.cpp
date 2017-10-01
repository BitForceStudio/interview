/****************************************************************************************************
                                  282. Expression Add Operators           
-----------------------------------------------------------------------------------------------------
Given a string that contains only digits 0-9 and a target value, return all possibilities to add 
binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> addOperators(string num, int target) {
	        vector<string> rst;
	        if (num.size()==0) return rst;
	        string curr="";
	        
	        for(int i=1;i<=num.size();i++)
	        {
	            string stmp = num.substr(0,i);
	            long tmp = stol(stmp);
	            if (to_string(tmp)!=stmp) continue;
	            dfs(rst,num,stmp,target,i,tmp,tmp,'^');
	        }
	        
	        return rst;
	    }
	    
	    void dfs(vector<string>& rst, string num, string curr, long target, int pos, long cv, long pv, char op)
	    {
	        if (pos==num.size() && cv==target)
	        {
	            rst.push_back(curr);
	            return;
	        }
	        
	        for(int i=pos+1;i<=num.size();i++)
	        {
	            string stmp = num.substr(pos,i-pos);
	            long tmp = stol(stmp);
	            if (to_string(tmp)!=stmp) continue;
	            
	            dfs(rst,num,curr+"+"+stmp,target,i,cv+tmp,tmp,'+');
	            dfs(rst,num,curr+"-"+stmp,target,i,cv-tmp,tmp,'-');
	            
	            long mtmp=0;
	            if (op=='+')  // ***
	            {
	                mtmp=cv-pv+tmp*pv;
	            }
	            else if (op=='-')
	            {
	                mtmp=cv+pv-tmp*pv;
	            }
	            else
	            {
	                mtmp=tmp*pv;
	            }
	            
	            dfs(rst,num,curr+"*"+stmp,target,i,mtmp,tmp*pv,op);
	        }
	    }
	};

	class Solution2 {
	public:
	    vector<string> addOperators(string num, int target) {
	        string sol="";
	        vector<string> rst;
	        int len =num.size();
	        if (len==0) return rst;
	        for(int sz=0;sz<len;sz++)
	        {
	            string subnc = num.substr(0,sz+1);
	            if (subnc.size()>1 && subnc[0]=='0') break;
	            long nc = stol(subnc);
	            dfs(num,rst,subnc,target,nc,sz+1,nc);
	        }
	        return rst;
	    }
	    
	    void dfs(string num, vector<string>& rst, string sol, int target, long curr, int start, long pre)
	    {
	        if (start==num.size())
	        {
	            if (curr == target) rst.push_back(sol);
	            else return;
	        }
	        for(int sz=start;sz<num.size();sz++)
	        {
	            string subnc = num.substr(start,sz-start+1);
	            if (subnc.size()>1 && subnc[0]=='0') break;
	            long nc = stol(subnc);
	            // +
	            dfs(num,rst,sol+"+"+subnc,target,curr+nc,sz+1,nc);
	            // -
	            dfs(num,rst,sol+"-"+subnc,target,curr-nc,sz+1,-nc);
	            // *
	            dfs(num,rst,sol+"*"+subnc,target,curr-pre+pre*nc,sz+1,pre*nc);
	        }
	    }
	};

}

/****************************************************************************************************
                                             Note
Just the dfs, no trick except the *, which minus the previous value and plus current. Just do the 
search. 

solution 2:  need to write it down and just dfs
****************************************************************************************************/