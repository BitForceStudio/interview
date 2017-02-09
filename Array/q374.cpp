/****************************************************************************************************
                                374. Guess Number Higher or Lower             
-----------------------------------------------------------------------------------------------------
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
Example:
n = 10, I pick 6.

Return 6.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	// Forward declaration of guess API.
	// @param num, your guess
	// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
	int guess(int num);

	class Solution {
	public:
	    int guessNumber(int n) {
	        int s=1,t=n;
	        int mid;
	        while(s<t)
	        {
	            mid=s+(t-s)/2;
	            if (guess(mid)<0) t=mid;
	            else if (guess(mid)>0) s=mid+1;
	            else return mid;
	        }
	        return s;
	    }
	};

}

/****************************************************************************************************
                                             Note
be careful about the conditions. 
****************************************************************************************************/