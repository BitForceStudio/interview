/****************************************************************************************************
                                496. Next Greater Element I             
-----------------------------------------------------------------------------------------------------
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of 
nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second 
    array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, 
    so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so 
    output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
	        int lenf=findNums.size();
	        int len = nums.size();
	        if (lenf==0 || len==0) return findNums;
	        vector<int> rst(lenf,-1);
	        
	        map<int,int> mp;
	        for(int i=0;i<len;i++)
	        {
	            mp[nums[i]]=i;
	        }
	        
	        for(int i=0;i<lenf;i++)
	        {
	            for(int j=mp[findNums[i]]+1;j<len;j++)
	            {
	                if (nums[j]>findNums[i]) 
	                {
	                    rst[i]=nums[j];
	                    break;
	                }
	            }
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
better solution:
the same idea with using stack/deque to keep the greater one on top
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};
****************************************************************************************************/