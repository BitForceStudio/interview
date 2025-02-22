/****************************************************************************************************
                                 350. Intersection of Two Arrays II          
-----------------------------------------------------------------------------------------------------
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load 
all elements into the memory at once?
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
	        int len1=nums1.size();
	        int len2=nums2.size();
	        
	        vector<int> rst;
	        if (len1==0 || len2==0) return rst;
	        
	        map<int,int> maps;
	        for(int i=0;i<len1;i++) maps[nums1[i]]++;
	        
	        for(int i=0;i<len2;i++)
	        {
	            if (maps[nums2[i]]>0)
	            {
	                rst.push_back(nums2[i]);
	                maps[nums2[i]]--;
	            }
	        }
	        
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
the follow up questions
Hash table solution:
Time: O(m + n) Space: O(m + n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};
Hash table solution2:
Time: O(m + n) Space: O(m)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for(int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
        for(int i = 0; i < (int)nums2.size(); i++)
            if(dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0) res.push_back(nums2[i]);
        return res;
    }
};
Sort and two pointers Solution:
Time: O(max(m, n) log(max(m, n))) Space: O(m + n)

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = (int)nums1.size(), n2 = (int)nums2.size();
        int i1 = 0, i2 = 0;
        vector<int> res;
        while(i1 < n1 && i2 < n2){
            if(nums1[i1] == nums2[i2]) {
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(nums1[i1] > nums2[i2]){
                i2++;
            }
            else{
                i1++;
            }
        }
        return res;
    }
};
****************************************************************************************************/