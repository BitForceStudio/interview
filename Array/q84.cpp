/****************************************************************************************************
                                84. Largest Rectangle in Histogram               
-----------------------------------------------------------------------------------------------------
Given n non-negative integers representing the histogram's bar height where the width of each bar is 
1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class D&CSolution {
	public:
	    int largestRectangleArea(vector<int>& heights) {
	        int len=heights.size();
	        if(len==0) return 0;
	        if(len==1) return heights[0];
	        
	        int rst=helper(heights, 0,len-1);
	        return rst;
	    }
	    
	    int helper(vector<int>& h, int s, int t)
	    {
	        if(s>t) 
	        {
	            return 0;
	        }
	        if(t-s==0) 
	        {
	            return h[s];
	        }
	        if(t-s==1)
	        {
	            return max(2*min(h[s],h[t]),max(h[s],h[t])); 
	        }
	        
	        int mid = (s+t)/2;
	        int maxall = maxCombineArea(h,s,mid,t);
	        int maxleft = helper(h,s,mid);
	        int maxright = helper(h,mid+1,t);

	        return max(maxleft,max(maxright,maxall));
	    }
	    
	    int maxCombineArea(const vector<int> &height, int s, int m, int e) {
	        // Expand from the middle to find the max area containing height[m] and height[m+1]
	        int i = m, j = m+1;
	        int area = 0, h = min(height[i], height[j]);
	        while(i >= s && j <= e) {
	            h = min(h, min(height[i], height[j]));
	            area = max(area, (j-i+1) * h);
	            if (i == s) {
	                ++j;
	            }
	            else if (j == e) {
	                --i;
	            }
	            else {
	                // if both sides have not reached the boundary,
	                // compare the outer bars and expand towards the bigger side
	                if (height[i-1] > height[j+1]) {
	                    --i;
	                }
	                else {
	                    ++j;
	                }
	            }
	        }
	        return area;
	    }
	};

	class StackSolution {
	public:
	    int largestRectangleArea(vector<int>& heights) {
	        int len=heights.size();
	        if (len==0) return 0;
	        if (len==1) return heights[0];
	        
	        // Create an empty stack. The stack holds indexes of hist[] array
	        // The bars stored in stack are always in increasing order of their
	        // heights.
	        stack<int> s;
	     
	        int max_area = 0; // Initalize max area
	        int tp;  // To store top of stack
	        int area_with_top; // To store area with top bar as the smallest bar
	     
	        // Run through all bars of given histogram
	        int i = 0;
	        while (i < len)
	        {
	            // If this bar is higher than the bar on top stack, push it to stack
	            if (s.empty() || heights[s.top()] <= heights[i])
	                s.push(i++);
	     
	            // If this bar is lower than top of stack, then calculate area of rectangle 
	            // with stack top as the smallest (or minimum height) bar. 'i' is 
	            // 'right index' for the top and element before top in stack is 'left index'
	            else
	            {
	                tp = s.top();  // store the top index
	                s.pop();  // pop the top
	     
	                // Calculate the area with hist[tp] stack as smallest bar
	                area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);
	     
	                // update max area, if needed
	                if (max_area < area_with_top)
	                    max_area = area_with_top;
	            }
	        }
	     
	        // Now pop the remaining bars from stack and calculate area with every
	        // popped bar as the smallest bar
	        while (s.empty() == false)
	        {
	            tp = s.top();
	            s.pop();
	            area_with_top = heights[tp] * (s.empty() ? i : i - s.top() - 1);
	     
	            if (max_area < area_with_top)
	                max_area = area_with_top;
	        }
	     
	        return max_area;
	    }
	};

}

/****************************************************************************************************
                                             Note
1: divide and conqure
	find the min and there are three values
	left max, min*len, right max. return max
	problem: how to find min effictively. 
2: stack
	I don't understand the detail...why it works? 
	I think it was store the increasing element <= current. between two index in stack, all heights 
	are greater than both. 
****************************************************************************************************/