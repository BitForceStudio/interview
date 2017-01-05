/****************************************************************************************************
                                     27. Remove Element        
-----------------------------------------------------------------------------------------------------
Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
****************************************************************************************************/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()==0) return 0;
        int len=nums.size();
        while(nums[len-1]==val && len>1) len--;
        
        int irp=len-1;
        for(int i=0;i<=irp;i++)  // used to <len, which contains bug
        {
            if (nums[i]==val)
            {
                nums[i]=nums[irp]; irp--;
                if(irp<=i) break;
                while(nums[irp]==val && irp>i) irp--;
            }
        }
        nums.resize(irp+1);  // has to add one. 
        return irp+1;
    }
};

/****************************************************************************************************
                                             Note
Be careful about the irp, it causes the problem. 
****************************************************************************************************/