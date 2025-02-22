/****************************************************************************************************
                                 165. Compare Version Numbers           
-----------------------------------------------------------------------------------------------------
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level 
revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    
	    int compareVersion(string version1, string version2) {
	        vector<int> v1,v2;
	        
	        getversion(v1,version1);
	        getversion(v2,version2);
	        
	        int len1=v1.size();
	        int len2=v2.size();
	        
	        int len=len1<len2?len2:len1;
	        for(int i=0;i<len;i++)
	        {
	            int curr1=i<len1?v1[i]:0;
	            int curr2=i<len2?v2[i]:0;
	            if(curr1<curr2) return -1;
	            if(curr1>curr2) return 1;
	        }
	        return 0;
	    }
	    
	    void getversion(vector<int>& v, string s)
	    {
	        int len = s.size();
	        int curr = 0;
	        for(int i=0;i<len;i++)
	        {
	            if(s[i]=='.')
	            {
	                v.push_back(curr);
	                curr=0;
	            }
	            else
	            {
	                curr=curr*10+s[i]-'0';
	            }
	        }
	        v.push_back(curr);   // **
	    }
	};


	class Solution2 {
	public:
	    int compareVersion(string version1, string version2) {
	        // remove the heading '0's
	        int iz=0;
	        while(version1[iz]=='0') iz++;
	        version1=version1.substr(iz);
	        iz=0;
	        while(version2[iz]=='0') iz++;
	        version2=version2.substr(iz);
	        
	        // find the dot
	        int dot1 = version1.find('.');
	        int dot2 = version2.find('.');
	        
	        if (dot1==-1) dot1 = version1.size();
	        if (dot2==-1) dot2 = version2.size();
	        
	        if (dot1<dot2) return -1;
	        if (dot1>dot2) return 1;
	        for(int i=0;i<dot1;i++)
	        {
	            if (version1[i]<version2[i]) return -1;
	            if (version1[i]>version2[i]) return 1;
	        }

	        if (dot1==version1.size()) return dot2==version2.size()?0:compareVersion("0",version2.substr(dot2+1));
	        if (dot2==version2.size()) return dot1==version1.size()?0:compareVersion(version1.substr(dot1+1),"0");
	        
	        return compareVersion(version1.substr(dot1+1),version2.substr(dot2+1));
	    }
	};


}

/****************************************************************************************************
                                             Note
version can be more than 1 dot. 
there is another one, just compare the left side of dot

** be careful about here, need to push back curr at end.

solution 2
Be careful about the corner cases:

1: heading '0's
2: 1 vs 1.0 ...
****************************************************************************************************/