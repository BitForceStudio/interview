/****************************************************************************************************
                                   169. Majority Element            
-----------------------------------------------------------------------------------------------------
Given an array of size n, find the majority element. The majority element is the element that appears 
more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int majorityElement(vector<int>& nums) {
	        int len = nums.size();
	        if (len==0) return 0;
	        
	        map<int,int> elem;
	        for(int i=0;i<len/2;i++)
	        {
	            elem[nums[i]]++;
	        }
	        for(int i=len/2;i<len;i++)
	        {
	            elem[nums[i]]++;
	            if (elem[nums[i]]>len/2) return nums[i];
	        }
	        
	        return 0;
	    }
	};


	public class OthersSolution {
	    public int majorityElement(int[] num) {

	        int major=num[0], count = 1;
	        for(int i=1; i<num.length;i++){
	            if(count==0){
	                count++;
	                major=num[i];
	            }else if(major==num[i]){
	                count++;
	            }else count--;
	            
	        }
	        return major;
	    }
	};
}

/****************************************************************************************************
                                             Note
others: it uses the fact that one is more than half. so, exist and only exist one majority value that
count greator than one.  
****************************************************************************************************/