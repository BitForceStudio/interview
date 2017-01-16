/****************************************************************************************************
                                       223. Rectangle Area      
-----------------------------------------------------------------------------------------------------
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	        // overlapping problem
	        if (( C<E || A>G ) || ( B>H || D<F )) return area(A,B,C,D)+area(E,F,G,H);
	        
	        int lx = A>E?A:E;
	        int ly = B>F?B:F;
	        int rx = C>G?G:C;
	        int ry = D>H?H:D;
	        return area(A,B,C,D)+area(E,F,G,H)-area(lx,ly,rx,ry);
	    }
	    
	    int area(int a,int b,int c,int d)
	    {
	        return (a-c)*(b-d);
	    }
	};

}

/****************************************************************************************************
                                             Note
overlapping problem
be careful about the define, left bottom to right corner
****************************************************************************************************/