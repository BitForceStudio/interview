/****************************************************************************************************
                                   31. Next Permutation          
-----------------------------------------------------------------------------------------------------
Implement next permutation, which rearranges numbers into the lexicographically next greater
permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in 
ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the 
right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
****************************************************************************************************/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the current one greater than following one
        if (nums.size()<=1) return;
        
        int len=nums.size();
        bool found=false;
        for(int i=len;i>1;i--)
        {
            if (nums[i-2]<nums[i-1])
            {
                if (i<len)
                    std::sort(nums.begin()+i-1,nums.end());
                int tmp=nums[i-2];                       // item need to be exchanged
                int isw = i-1;
                while (nums[isw]<=tmp && isw<len) isw++; // find the next greater value ***
                nums[i-2]=nums[isw];
                nums[isw]=tmp;
                found=true;
                break;
            }
        }
        if (!found) std::sort(nums.begin(),nums.end());
    }
};
/****************************************************************************************************
                                             Note
Need to be careful about find next greater one. 
****************************************************************************************************/