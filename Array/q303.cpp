/****************************************************************************************************
                                  303. Range Sum Query - Immutable           
-----------------------------------------------------------------------------------------------------
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class NumArray {
	public:
	    NumArray(vector<int> nums) {
	        if(nums.size()==0) return;
	        m_len=nums.size();
	        m_nums.resize(m_len,0);
	        m_nums[0]=nums[0];
	        for(int i=1;i<m_len;i++)
	        {
	            m_nums[i]=nums[i]+m_nums[i-1];
	        }
	    }
	    
	    int sumRange(int i, int j) {
	        if (i<m_len && j<m_len && i<=j) return m_nums[j]- ((i>0)?m_nums[i-1]:0);
	    }
	    
	private:
	    vector<int> m_nums;
	    int m_len;
	};

	/**
	 * Your NumArray object will be instantiated and called as such:
	 * NumArray obj = new NumArray(nums);
	 * int param_1 = obj.sumRange(i,j);
	 */

}

/****************************************************************************************************
                                             Note
Don't be stupid...
****************************************************************************************************/