/****************************************************************************************************
                                     53. Maximum Subarray       
-----------------------------------------------------------------------------------------------------
Find the contiguous subarray within an array (containing at least one number) which has the largest 
sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer 
approach, which is more subtle.
****************************************************************************************************/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if (len==0) return NULL;
        if (len==1) return nums[0];
        int max = -2147483648;
        int currsum = 0;
        for(int i=0;i<len;i++)
        {
            if (currsum<0) currsum=nums[i];  // if all negtive
            else currsum+=nums[i];
            max=currsum>max?currsum:max;
            currsum=(currsum<0 && max>0)?0:currsum;
        }
        return max;
    }
};

/****************************************************************************************************
                                             Note
if all negtive, need to get the largest. 

divide and conquer solution? 

middle: the max sum solutiom must include the middle points. so, it will be linear problem. expand on
both ways and sum the max. 
****************************************************************************************************/