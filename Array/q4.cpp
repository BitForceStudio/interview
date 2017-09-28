/****************************************************************************************************
                                   4. Median of Two Sorted Arrays          
-----------------------------------------------------------------------------------------------------
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	        int len1=nums1.size();
	        int len2=nums2.size();
	        
	        // make sure len1<len2;
	        if (len1>len2)
	        {
	            vector<int> tmp = nums2;
	            nums2 = nums1;
	            nums1 = tmp;
	            len1=nums1.size();
	            len2=nums2.size();
	        }

	        int s=0,t=len1;
	        int hf = (len1+len2+1)/2;
	        int i = 0;
	        int j=0;
	        while(s<=t)
	        {
	            i = (s+t)/2;
	            j = hf-i;
	            if (i<len1 && nums1[i]<nums2[j-1])
	            {
	                s=i+1;
	            }
	            else if (i>0 && nums1[i-1]>nums2[j])
	            {
	                t=i-1;
	            }
	            else
	            {
	                int maxLeft = 0;
	                if (i==0) {maxLeft = nums2[j-1];}
	                else if (j==0) {maxLeft = nums1[i-1];}
	                else {maxLeft = max(nums2[j-1],nums1[i-1]);}
	                if ((len1+len2)%2==1) {return maxLeft;}
	                
	                int minRight=0;
	                if (i==len1) minRight = nums2[j];
	                else if (j==len2) minRight = nums1[i];
	                else minRight = min(nums1[i],nums2[j]);
	                
	                return (maxLeft+minRight)/2.0;
	                
	            }
	        }
	        return 0.0;
	    }
	};

}

/****************************************************************************************************
                                             Note
cut A, B into two parts ,i & j
if i & j santisfy the following
A[i-1] <= B[j]
B[j-1] <= A[i]
i+j=(m+n+1)/2

then i,j is the middle
****************************************************************************************************/