/****************************************************************************************************
                                   71. Simplify Path          
-----------------------------------------------------------------------------------------------------
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string simplifyPath(string path) {
	        // use stack. from begining.
	        int len=path.size();
	        if (len<=1) return path;
	        
	        stack<string> sPath;   // *
	        
	        for(int i=0;i<len;i++)
	        {
	            // if .. : pop front if has
	            // if .  : do nothing
	            // if ab : push to stack
	            string tmp="";
	            if (path[i]=='/')
	            {
	                i++;
	                while(path[i]!='/' && i<len) { tmp+=path[i]; i++;}
	            }
	            if (tmp!="")
	            {
	                if (tmp=="..") 
	                { 
	                    if(!sPath.empty()) sPath.pop();  // *****
	                }
	                else if (tmp==".") {}  // **
	                else sPath.push(tmp);
	            }
	            i--;
	        }
	        
	        string npath="";
	        if (sPath.empty()) return "/";  // ***
	        while(!sPath.empty())
	        {
	            npath="/"+sPath.top()+npath;   // ****
	            sPath.pop();
	        }
	        
	        return npath;
	        
	    }
	};

}

/****************************************************************************************************
                                             Note
*:      using stack, because there is '..', stack will make it much easier
**:     remember '.' means do nothing
***:    careful: if empty path, return '/'
****:   careful: the order, stack pop the last one first
*****:  careful: empty should be inside of ==".." logic
****************************************************************************************************/