/****************************************************************************************************
                             453. Minimum Moves to Equal Array Elements                
-----------------------------------------------------------------------------------------------------
Given a non-empty integer array of size n, find the minimum number of moves required to make all array 
elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int minMoves(vector<int>& nums) {
	        int len=nums.size();
	        if (len==1) return 0;
	        sort(nums.begin(),nums.end());
	        int rst=0;
	        for(int i=len-2;i>=0;i--) rst+=(nums[i+1]-nums[i])*(len-i-1);
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
My solution:
sort it then, find the pattern.

Better solution
let's define sum as the sum of all the numbers, before any moves; minNum as the min number int the 
list; n is the length of the list;

After, say m moves, we get all the numbers as x , and we will get the following equation

 sum + m * (n - 1) = x * n
and actually,

  x = minNum + m
and finally, we will get

  sum - minNum * n = m
So, it is clear and easy now.
****************************************************************************************************/