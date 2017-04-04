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

class BetterLinearSolution {
public:
    int maxSubArray(vector<int>& nums){
        int len=nums.size();
        if(len<1) return 0;
        int currmax = nums[0];
        int allmax  = nums[0];
        for(int i=1;i<len;i++){
            if (currmax<0) currmax=0;
            currmax+=nums[i];
            allmax=allmax>currmax?allmax:currmax;
        }
        return allmax;
    }
};

class D_C_Solution{
public:
    int maxSubArray(vector<int>& nums){
        int len=nums.size();
        if(len<1) return 0;
        return helper(0,len-1,nums);  
    }

    int helper(int st,int ed,vector<int> nums){
        if(st==ed) return nums[st];
        int mid=(st+ed)/2;
        int leftmax = helper(st,mid,nums);
        int rightmax= helper(mid+1,ed,nums);
        int currmax = nums[mid];
        int currsum = nums[mid];

        for(int i=mid-1;i>=0;i--){
            currsum+=nums[i];
            if(currsum>currmax) currmax=currsum; 
        }  
        currsum=currmax;
        for(int i=mid+1;i<=ed;i++){
            currsum+=nums[i];
            if(currsum>currmax) currmax=currsum; 
        }
        return max(currmax,max(leftmax,rightmax));
    } 
};

/****************************************************************************************************
                                             Note
Linear solution: initial the max to be the first element. In the loop compare the the current max
with 0 first, then added the current element. Then compare the current max. 

divide and conquer: remember the end element should be considered. 
****************************************************************************************************/
