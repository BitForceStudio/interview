/****************************************************************************************************
                                   239. Sliding Window Maximum         
-----------------------------------------------------------------------------------------------------
Given an array nums, there is a sliding window of size k which is moving from the very left of the 
array to the very right. You can only see the k numbers in the window. Each time the sliding window 
moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Hint:

How about using a data structure such as deque (double-ended queue)?
The queue size need not be the same as the window’s size.
Remove redundant elements and the queue should store only elements that need to be considered.

****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class OKNSolution {
	public:
	    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	        int len=nums.size();
	        vector<int> rst;
	        if (len==0 || k==0) return rst;
	        if (k==1) return nums;
	        
	        deque<int> window;
	        int i=0;
	        while(window.size()<k-1) window.push_back(nums[i++]); 
	        for(;i<len;i++)
	        {
	            window.push_back(nums[i]);
	            int max=window.front();
	            for(int itr:window)
	            {
	                if (itr>max) max=itr;
	            }
	            window.pop_front();
	            rst.push_back(max);
	        }
	        return rst;
	    }
	};

	class ONSolution {
	public:
	    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	        int len=nums.size();
	        vector<int> rst;
	        if (len==0 || k==0) return rst;
	        if (k==1) return nums;
	        rst.resize(len-k+1);
	        deque<int> window;
	        
	        // Monotonic deque
	        for(int i=0;i<len;i++)
	        {
	            while(!window.empty() && nums[i]>=nums[window.back()]) window.pop_back();
	            window.push_back(i);
	            
	            if (i>=k-1) rst[i-k+1]=nums[window.front()];
	            while (!window.empty() && window.front()<=i-k+1) window.pop_front();
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
O(n) solution: 
keep the potentially maximum to the front, key is to remove all element that less than current from 
back, then keep the front element in the window...more explain is here:

The basic idea is to use a deque (buffer) to save all currently potential "maximum" elements (i.e. 
the element in the current k-element window [i-k+1, i], and it is larger than the elements after 
itself). So for each i, we first pop up the elements that are no larger than nums[i] from buffer until 
we find one that is larger than nums[i] or the buffer is empty since those elements will be covered by 
nums[i] and can not be a maximum of any k-element window. Then we put nums[i] in the buffer. If i>=k-1, 
we need to ouput the maximum for window [i-k+1, i], which is the front element of buffer. At last, we 
will check if the front element is nums[i-k+1], if so, we have to pop it up since it will be out of 
the window [i-k+2, i+1] in the next iteration. Since all the elements will be pushed into/ popped out 
of the buffer only once, so the time complexity is O(N).
****************************************************************************************************/