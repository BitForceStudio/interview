/****************************************************************************************************
                                    506. Relative Ranks         
-----------------------------------------------------------------------------------------------------
Given scores of N athletes, find their relative ranks and the people with the top three highest 
scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", 
"Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.
Note:
N is a positive integer and won't exceed 10,000.
All the scores of athletes are guaranteed to be unique.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> findRelativeRanks(vector<int>& nums) {
	        int len=nums.size();
	        vector<string> rst;
	        if (len==0) return rst;
	        rst.resize(len);
	        map<int,int> rank;
	        vector<int> score = nums;
	        sort(score.begin(),score.end());
	        
	        for(int i=0;i<len;i++)
	        {
	            rank[score[i]]=i;
	        }
	        
	        for(int i=len-1;i>=0;i--)
	        {
	            if (rank[nums[i]]==len-1) rst[i]="Gold Medal";
	            else if (rank[nums[i]]==len-2) rst[i]="Silver Medal";
	            else if (rank[nums[i]]==len-3) rst[i]="Bronze Medal";
	            else rst[i]=to_string((len-rank[nums[i]]));
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Better solution
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank;
        for(int i=0; i<nums.size(); ++i) rank.push_back(i);
        
        sort(rank.begin(), rank.end(), [&](int a, int b){return nums[a] > nums[b];});
        vector<string> ranks(nums.size());
        
        for(int i=3; i<nums.size(); ++i){
            ranks[rank[i]] = std::to_string(i+1);
        }
        
        if(nums.size() > 0) ranks[rank[0]] = "Gold Medal";
        if(nums.size() > 1) ranks[rank[1]] = "Silver Medal";
        if(nums.size() > 2) ranks[rank[2]] = "Bronze Medal";
        
        return ranks;
    }
};
****************************************************************************************************/