/****************************************************************************************************
                                   57. Insert Interval         
-----------------------------------------------------------------------------------------------------
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

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
	    static bool sortInterval(const Interval i, const Interval j)
	    {
	        return i.start<j.start;
	    }
	    
	    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	        int len=intervals.size();
	        if (len==0) { intervals.push_back(newInterval); return intervals; }
	        sort(intervals.begin(),intervals.end(),sortInterval);
	        // find the overlaping first
	        int is=0;
	        if (newInterval.end<intervals[0].start)
	        {
	            intervals.insert(intervals.begin(),newInterval);
	            return intervals;
	        }
	        if (newInterval.start > intervals.back().end)
	        {
	            intervals.insert(intervals.end(),newInterval);
	            return intervals;
	        }
	        
	        vector<Interval> rst;
	        int i=0;
	        bool qadd = false;
	        while(i<len)
	        {
	            if (i==0 && !qadd) // deal with first one;
	            {
	                Interval curr;
	                if (newInterval.start<intervals[i].start) curr.start = newInterval.start;
	                else if (newInterval.start<=intervals[i].end) curr.start = intervals[i].start;
	                else {rst.push_back(intervals[i]); i++; continue;}
	                
	                // find end
	                curr.end=newInterval.end;
	                while(i<len)
	                {
	                    if (newInterval.end <= intervals[i].end)
	                    {
	                        // 2.2.1   new.e < i.s
	                        if (curr.end>=intervals[i].start)
	                            curr.end=intervals[i].end;
	                        else
	                        {
	                            curr.end=newInterval.end;
	                            i--;
	                        }
	                        break;
	                    }
	                    i++;
	                }
	                rst.push_back(curr);
	                qadd = true;
	                i++;
	                continue;
	            }

	            if (newInterval.start<intervals[i].start && !qadd && i>0)
	            {
	                Interval curr;
	                // set curr.start
	                //  1.1   new.s < i-1.e
	                if (newInterval.start <= intervals[i-1].end)
	                {
	                    curr.start = intervals[i-1].start;
	                    rst.pop_back();
	                    i--;
	                }
	                else curr.start = newInterval.start;

	                // set curr.end
	                // 2.1   new.e < i.s
	                if (newInterval.end<intervals[i].start)
	                {
	                    curr.end = newInterval.end;
	                    rst.push_back(curr);
	                    rst.push_back(intervals[i]);
	                    qadd = true;
	                }
	                else
	                {
	                    // find first i.end >= new.end
	                    curr.end=newInterval.end;
	                    while(i<len)
	                    {
	                        if (newInterval.end <= intervals[i].end)
	                        {
	                            // 2.2.1   new.e < i.s
	                            if (newInterval.end >= intervals[i].start)
	                            {
	                                curr.end=intervals[i].end;
	                            }
	                            else
	                            {
	                                i--;
	                            }
	                            break;
	                        }
	                        i++;
	                    }
	                    rst.push_back(curr);
	                    qadd = true;
	                }
	                i++;
	            }
	            else
	            {
	                rst.push_back(intervals[i]);
	                i++;
	            }
	        }
	        
	        // last one
	        if (!qadd)
	        {
	            Interval curr;
	            curr.start = intervals[len-1].start;
	            curr.end = intervals[len-1].end>newInterval.end?intervals[len-1].end:newInterval.end;
	            rst.pop_back();
	            rst.push_back(curr);
	        }
	        return rst;
	    }
	};


	////////// same idea but better coding

	/**
	 * Definition for an interval.
	 * struct Interval {
	 *     int start;
	 *     int end;
	 *     Interval() : start(0), end(0) {}
	 *     Interval(int s, int e) : start(s), end(e) {}
	 * };
	 */
	class OtherSolution {
	public:
	    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	        int len=intervals.size();
	        if (len==0) { intervals.push_back(newInterval); return intervals; }
	        // get the left side of the interval, the merged interval, and right side of interval. put them together
	        vector<Interval> rst;
	        Interval curr = newInterval;
	        bool qadd = false;
	        for(int i=0;i<len;i++)
	        {
	            if (intervals[i].end < curr.start)
	            {
	                rst.push_back(intervals[i]);
	            }
	            else if (intervals[i].start > curr.end) 
	            {
	                if (!qadd)
	                {
	                    rst.push_back(curr);
	                    qadd=true;
	                }
	                rst.push_back(intervals[i]);
	            }
	            else
	            {
	                curr.start=intervals[i].start<curr.start?intervals[i].start:curr.start;
	                curr.end=intervals[i].end>curr.end?intervals[i].end:curr.end;
	            }
	        }
	        if (!qadd) rst.push_back(curr);
	        return rst;
	    }
	};


	class Solution2 {
	public:
	    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
	        int len=intervals.size();
	        if(len==0)
	        {
	            intervals.push_back(newInterval);
	            return intervals;
	        }
	        if(newInterval.start > intervals[len-1].end) 
	        {
	            intervals.push_back(newInterval);
	            return intervals;
	        }
	        if(newInterval.end < intervals[0].start)
	        {
	            intervals.insert(intervals.begin(),newInterval);
	            return intervals;
	        }
	        
	        vector<Interval> rst;
	        bool qadded = false;
	        for(int i=0;i<len;i++)
	        {
	            if(qadded) rst.push_back(intervals[i]);
	            else if(newInterval.start > intervals[i].end)
	            {
	                rst.push_back(intervals[i]);
	            }
	            else
	            {
	                if(newInterval.end<intervals[i].start)
	                {
	                    rst.push_back(newInterval);
	                    rst.push_back(intervals[i]);
	                    qadded = true;
	                }
	                else
	                {
	                    newInterval.start = min(newInterval.start,intervals[i].start);
	                    newInterval.end = max(newInterval.end,intervals[i].end);
	                }
	            }
	        }
	        if(!qadded) rst.push_back(newInterval);
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
finished it by debugging. is there any good ways to do this? 
****************************************************************************************************/