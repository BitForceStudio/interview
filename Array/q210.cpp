/****************************************************************************************************
                                      210. Course Schedule II       
-----------------------------------------------------------------------------------------------------
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses 
you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to 
finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the 
correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 
2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is 
[0,1,2,3]. Another correct ordering is[0,2,1,3].
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	        vector<int> rst;
	        if (numCourses==0) return rst;
	        
	        vector<bool> qpath(numCourses,false),qvisited(numCourses,false);
	        vector<set<int> > graph= makeGraph(numCourses,prerequisites);
	        vector<set<int> > rgraph=makeReGraph(numCourses,prerequisites);

	        vector<int> empty;
	        for(int i=0;i<numCourses;i++)
	        {
	            if (!qvisited[i] && dfsSearch(graph,rgraph,qpath,qvisited,rst,i)) return empty;
	        }
	        return rst;
	    }
	    
	    vector<set<int> > makeGraph(int n,vector<pair<int,int> > p)
	    {
	        vector<set<int> > graph(n);
	        for(auto pre:p)
	        {
	            graph[pre.second].insert(pre.first);
	        }
	        return graph;
	    }
	    
	    vector<set<int> > makeReGraph(int n,vector<pair<int,int> > p)
	    {
	        vector<set<int> > rgraph(n);
	        for(auto pre:p)
	        {
	            rgraph[pre.first].insert(pre.second);
	        }
	        return rgraph;
	    }
	    
	    bool dfsSearch(vector<set<int> >& graph, vector<set<int> >& rgraph, vector<bool>& qp, vector<bool>& qv, vector<int>& rst, int node)
	    {
	        if (qv[node]) return false;
	        if (rgraph[node].size()==0) 
	        {
	            rst.push_back(node);
	            qv[node]=true;
	        }
	        else
	        {
	            bool qReq=true;
	            for(int i:rgraph[node])
	                if (!qv[i]) {qReq=false; break;}   
	                    
	            if(qReq)
	            {
	                rst.push_back(node);
	                qv[node]=true;
	            }
	        }
	        qp[node]=true;
	        for(int i:graph[node])
	        {
	            if (qp[i] || dfsSearch(graph,rgraph,qp,qv,rst,i)) return true;
	        }
	        return qp[node]=false;
	    }
	};

}

/****************************************************************************************************
                                             Note
use a require map. but it seems not good enough. Read what's other do. 
****************************************************************************************************/