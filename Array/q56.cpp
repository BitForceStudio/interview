/****************************************************************************************************
                                        56. Merge Intervals     
-----------------------------------------------------------------------------------------------------
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
****************************************************************************************************/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int len=intervals.size();
        if (len==0 || len==1) return intervals; 
        
        vector<Interval> rst;
        sort(intervals.begin(),intervals.end(),sortInterval);
        Interval curr = intervals[0];
        for(int i=1;i<len;i++)
        {
            if (curr.end>=intervals[i].start) curr.end=curr.end>intervals[i].end?curr.end:intervals[i].end;  // *
            else 
            {
                rst.push_back(curr);
                curr=intervals[i];
            }
            if (i==len-1) rst.push_back(curr);   // **
        }
        return rst;
    }
    
    static bool sortInterval(const Interval i, const Interval j)  // ***
    {
        return i.start < j.start;
    }
};

/****************************************************************************************************
                                             Note
*:   don't forget current end may greater than ith end
**:  here is the tricky part, need to push_back the curr if it was to the end
***: self defined sort function, has to be static and inputs to be const. 
****************************************************************************************************/