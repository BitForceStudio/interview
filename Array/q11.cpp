/****************************************************************************************************
                                      11. Container With Most Water       
-----------------------------------------------------------------------------------------------------
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n 
vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two 
lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
****************************************************************************************************/

class Solution {
public:
    int maxArea(vector<int>& height) {
        // move the smaller one.
        if (height.size()<2) return 0;
        int len = height.size();
        int left=0,right=len-1;
        int maxarea = 0;
        while(left<right)
        {
            int currarea = (right-left)*(height[left]>height[right]?height[right]:height[left]);
            maxarea=currarea>maxarea?currarea:maxarea;
            
            if (height[left]<height[right]) left++;
            else right--;
        }
        return maxarea;
    }
};

/****************************************************************************************************
                                             Note
Think straight. it's not that difficult. Move the smaller one, it will find the maxnum. 
****************************************************************************************************/