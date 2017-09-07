/****************************************************************************************************
                         659. Split Array into Consecutive Subsequences            
-----------------------------------------------------------------------------------------------------
You are given an integer array sorted in ascending order (may contain duplicates), you need to split 
them into several subsequences, where each subsequences consist of at least 3 consecutive integers. 
Return whether you can make such a split.

Example 1:
Input: [1,2,3,3,4,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
Example 2:
Input: [1,2,3,3,4,4,5,5]
Output: True
Explanation:
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
Example 3:
Input: [1,2,3,4,4,5]
Output: False
Note:
The length of the input is in range of [1, 10000]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool isPossible(vector<int>& nums) {
	        int len=nums.size();
	        if (len<3) return false;
	        
	        map<int,int> counter;
	        for(int i=0;i<len;i++) counter[nums[i]]++;
	        
	        int p1=0,p2=0,p3m=0,pre=0;
	        int c1=0,c2=0,c3m=0;
	        map<int,int>::iterator it=counter.begin();
	        p1=it->second;
	        pre=it->first;
	        it++;
	        for(;it!=counter.end();++it)
	        {
	            if(it->first-pre!=1 && (p1!=0 || p2!=0)) return false;
	            if (it->first-pre!=1 && p1==0 && p2==0)
	            {
	                p3m = 0;
	                p1=it->second;
	                pre=it->first;
	            }
	            else
	            {
	                if (it->second<(p1+p2)) return false;
	                c2 = p1;
	                c3m = p2+min(p3m,it->second-p1-p2);
	                c1 = it->second-c2-c3m;
	                p1= c1;
	                p2=c2;
	                p3m=c3m;
	                pre=it->first;
	            }
	        }
	        
	        return (p1==0 && p2==0);
	    }
	};

}

/****************************************************************************************************
                                             Note
it is the greedy and DP problem. understand this. 
basically, for current one, the counter need to fulfil p1, p2 and p3. the rest was used for p1 for next
****************************************************************************************************/