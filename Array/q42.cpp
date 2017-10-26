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

	class Solution2 {
	public:
	    int trap(vector<int>& height) {
	        // keep tracking the
	        int len = height.size();
	        if(len<=2) return 0;
	        
	        stack<int> index; index.push(0);
	        int rst=0;
	        for(int i=1;i<len;i++)
	        {
	            if (height[i]<=height[index.top()]) index.push(i);
	            else
	            {
	                while(index.size()>1 && height[index.top()]<height[i]) index.pop();

	                if (index.size()==1 && height[index.top()]<=height[i])
	                {                
	                    int left = index.top();
	                    int right = i;
	                    index.pop(); 
	                    int minval=min(height[left],height[right]);
	                    for(int j=left+1;j<right;j++)
	                    {
	                        rst+=(minval-height[j])>0?(minval-height[j]):0;
	                    }
	                }
	                index.push(i);
	            }
	        }
	        while(index.size()>1)
	        {
	            int right=index.top();
	            index.pop();
	            int left = index.top();
	            int minval=min(height[left],height[right]);
	            for(int j=left+1;j<right;j++)
	            {
	                rst+=(minval-height[j])>0?(minval-height[j]):0;
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

solution 2 is what I could understand. 
****************************************************************************************************/