/****************************************************************************************************
                              149. Max Points on a Line               
-----------------------------------------------------------------------------------------------------
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	/**
	 * Definition for a point.
	 * struct Point {
	 *     int x;
	 *     int y;
	 *     Point() : x(0), y(0) {}
	 *     Point(int a, int b) : x(a), y(b) {}
	 * };
	 */
	class Solution {
	public:
	    int maxPoints(vector<Point>& points) {
	        int len=points.size();
	        if (len<=2) return len;
	        int maxnum=0;
	        for(int i=0;i<len;i++)
	        {
	            int nsame=1;
	            int inf=0;
	            int localmax=0;
	            map<double,int> counter;
	            for(int j=i+1;j<len;j++)
	            {
	                if (points[i].y==points[j].y && points[i].x==points[j].x)
	                {
	                    nsame++;
	                }
	                else if (points[i].x==points[j].x)
	                {
	                    inf++;  
	                }
	                else
	                {
	                    double slop = double(points[i].y-points[j].y) / double(points[i].x-points[j].x);
	                    counter[slop]++;
	                }
	            }
	            
	            for(auto it = counter.begin(); it != counter.end(); it++)
	            {
	                localmax=localmax<it->second?it->second:localmax;
	            }
	            localmax+=nsame;
	            inf+=nsame;
	            
	            maxnum=localmax<maxnum?maxnum:localmax;
	            maxnum=inf<maxnum?maxnum:inf;
	        }

	        return maxnum;
	    }
	};

}

/****************************************************************************************************
                                             Note
Here I use double to store. However, it shows that slop accuracy problem. Then here is the better one.
I had the same idea but didn't implement yet
The key to this problem is how to characterize "slope" determined by two points. I see many posts here 
using either a doubleto represent slope or pair<int,int>with GCD process to make it unique. But this 
either has issues with numerical accuracy or having to do recursive calculation.

The idea here is to simply define an order of slope in the representation of pair<int,int>:

Define slope a:=(a.x, a.y)is less than slope b:=(b.x, b.y) if

(a.y*b.y > 0)? a.x*b.y < a.y*b.x : a.x*b.y > a.y*b.x.
Note that this formulation is actually an extension to the traditional slope calculation x/y which 
not only needs to deal with y == 0as corner case but also unavoidably involves floating point numerical 
comparison.

Once the order is defined, it can be used as a key in std::map for counting purpose to gather points 
along the same line with a reference point, i.e.,

define map<Point, int> count with count[Point(x,y)] being the number of points with slope (x,y) to 
the reference point.
Note that we count singular slope (0,0) (i.e., duplicated points) separately since this "special" 
slope is essentially undefined.

Since an ordered container std::mapis used, the time complexity is O(N^2*logN). The space complexity 
is O(N)to store map<Point, int> count.

    int maxPoints(vector<Point>& pts) {
        int maxPts = 0;
        for (auto& i:pts) {
          map<Point, int, Comp> count; int dup = 0;
          for (auto& j:pts) maxPts = max(maxPts, i.x==j.x && i.y==j.y? ++dup : (++count[Point(i.x-j.x,i.y-j.y)]+dup));
        }
        return maxPts;
    }
    
    // comparator for key (slope) in map
    struct Comp { 
        bool operator()(const Point& a, const Point& b) { 
          int64_t diff = (int64_t)a.x*b.y - (int64_t)a.y*b.x; // convert to 64bit int for int overflow
          return (int64_t)a.y*b.y>0? diff > 0 : diff < 0;
        } 
    };
****************************************************************************************************/