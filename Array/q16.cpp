/****************************************************************************************************
                                        16. 3Sum Closest     
-----------------------------------------------------------------------------------------------------
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, 
target. Return the sum of the three integers. You may assume that each input would have exactly one s
olution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
****************************************************************************************************/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=nums.size();
        if (len<3) return 0;
        int sum=0;
        std::sort(nums.begin(),nums.end());
        std::map<int,int> dup;
        vector<int> unique;
        int dist = nums[0]+nums[1]+nums[2];
        for(int i=0;i<len;i++)
        {
            dup[nums[i]]++;
            if (dup[nums[i]]==1) unique.push_back(nums[i]); 
        }
        
        for(int i=0;i<len;i++)
        {
            if (i>0) if (nums[i]==nums[i-1]) continue;
            if (nums[i]>=target && nums[i]>0) 
            {
                if (i==0) dist=nums[i]+nums[i+1]+nums[i+2];
                break;
            }
            
            bool qend=false;
            for(int j=i+1;j<len-1;j++)
            {
                if (nums[j]==nums[i] && j>i+2) continue;
                int tmp = 2147483647;
                int minus = target-nums[i]-nums[j]; if (minus<nums[j]) continue;
                int rst = findindex(unique,minus);
                if ((rst==nums[j] && dup[nums[j]]>2) || (rst==nums[j] && nums[j]!=nums[i] && dup[nums[j]]>1) || (rst>nums[j]))
                {
                    tmp = nums[i]+nums[j]+rst;
                }
                else if (rst<=nums[j])
                {
                    if (dup[nums[j]]>1 && nums[i]!=nums[j]) tmp = nums[i]+nums[j]*2;
                    else                tmp = nums[i]+nums[j]+nums[j+1];
                }
               
                if (tmp-target==0) {qend=true;dist=tmp;break;}
                if (abs(tmp-target)<abs(dist-target)) dist=tmp;
            }
            if(qend) break;
        }
        return dist;
    }
    
    int findindex(vector<int> unique, int val)
    {
        int start= 0;
        int end  = unique.size()-1;
        if (unique.size()==1) return unique[0];
        while(end-start>1)
        {
            int mid = (start+end)/2;
            if (val > unique[mid]) start=mid;
            else                   end = mid;
        }

        return val-unique[start]>unique[end]-val?unique[end]:unique[start];
    }


    public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(),nums.end());

        int rst=nums[0]+nums[1]+nums[2];
        for(int i=0;i<len-2;i++)
        {
            int s=i+1,t=len-1;
            long minsum=nums[i]+nums[s]+nums[t];
            while(s<t)
            {
                long tmp = nums[t]+nums[s]+nums[i];
                minsum=abs(minsum-target)>abs(tmp-target)?tmp:minsum;
                if (tmp-target>0) t--;
                else if(tmp-target<0) s++;
                else return target;
            }
            rst=abs(rst-target)>abs(minsum-target)?minsum:rst;
            while (i<len-2 && nums[i]==nums[i+1]) i++;
        }
        return rst;
    }
};

/****************************************************************************************************
                                             Note
Using map to do this things. However, the three pointer may be better. Try this way next time.
****************************************************************************************************/