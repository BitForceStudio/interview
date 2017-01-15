/****************************************************************************************************
                                 42. Trapping Rain Water            
-----------------------------------------------------------------------------------------------------
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.


****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int trap(vector<int>& height) {
	        int len = height.size();
	        if (len<=2) return 0;
	        
	        int rst=0;
	        int maxleft=0,maxright=0;
	        int left=0,right=len-1;
	        while(left<=right)
	        {
	            if (height[left]<=height[right])
	            {
	                // calculate the area
	                if (height[left]>=maxleft) maxleft=height[left];
	                else rst+=maxleft-height[left];
	                left++;
	            }
	            else
	            {
	                // calculate the area
	                if (height[right]>=maxright) maxright=height[right];
	                else rst+=maxright-height[right];
	                right--;
	            }
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Got this idea from the solution. 
The basic idea is two pointers from left and right. keep the greater one between these two pointers. 
and move another one. and update the max of the moving one. it make sure the moving one always get
the right answer. 

** how get this idea is the problem...From two pointer? need to remember this one...
****************************************************************************************************/