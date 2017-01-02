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

// solution: merge two vector and then find the middle one
class Solution{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len = int(nums1.size()+nums2.size())
		vector<int> mergearr; mergearr.resize(len);
		int i1=0,i2=0,i=0;
		while(1){
			if (i1==nums1.size())
			{
				while(i2<nums2.size())
				{
					mergearr[i]=nums2[i2];
					i++;
					i2++;
				}
				break;
			}
			if (i2==nums2.size())
			{
				while(i1<nums1.size())
				{
					mergearr[i]=nums1[i1];
					i++;
					i1++;
				}
				break;
			}
			if (nums1[i1]<=nums2[i2]){
				mergearr[i] = nums1[i1];
				i1++;
			}
			else{
				mergearr[i]=nums2[i2];
				i2++;
			}
			i++;
		}
	}
	if (float(int((len+1)/2))*2!=float(len+1)) // odd
	{
		return float(mergearr[(len+1)/2]+mergearr[(len+1)/2+1])/2;
	}
	else
	{
		return float(mergearr[(len+1)/2]);
	}

};

// improvement: if reach the (m+n)/2, then break, it will be the answer

class Solution2
{
public:
	double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2)
	{
		int len = int(nums1.size()+nums2.size());
		vector<int> mergearr; mergearr.resize(len);
		int i1=0,i2=0,i=0;
		double qmid = int(len/2)*2==len;
		int lim = len/2;
		
		while(1)
		{
		    if (i>lim)
		        break;
			if (i1==nums1.size())
			{
				if(i2<nums2.size())
				{
					mergearr[i]=nums2[i2];
					i++;
					i2++;
				}
				continue;
			}
			if (i2==nums2.size())
			{
				if(i1<nums1.size())
				{
					mergearr[i]=nums1[i1];
					i++;
					i1++;
				}
				continue;
			}
			if (nums1[i1]<=nums2[i2]){
				mergearr[i] = nums1[i1];
				i1++;
			}
			else{
				mergearr[i]=nums2[i2];
				i2++;
			}
			i++;
		}

    	return qmid?float(mergearr[len/2]+mergearr[len/2-1])/2:mergearr[len/2];
    }
}