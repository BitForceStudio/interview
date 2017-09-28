/****************************************************************************************************
                                   310. Minimum Height Trees              
-----------------------------------------------------------------------------------------------------
For a undirected graph with tree characteristics, we can choose any node as the root. The result 
graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called 
minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a 
list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a 
list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] 
is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]

Hint:

How many MHTs can a graph have at most?
Note:

(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any 
two vertices are connected by exactly one path. In other words, any connected graph without simple 
cycles is a tree.”

(2) The height of a rooted tree is the number of edges on the longest downward path between the root 
and a leaf.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	        int len=edges.size();
	        vector<int> rst;
	        if (n==0 && len==0) return rst;
	        if (n==1)
	        {
	            rst.push_back(0);
	            return rst;
	        }
	        if (n==2)
	        {
	            rst.push_back(edges[0].first);
	            rst.push_back(edges[0].second);
	            return rst;
	        }
	        
	        map<int,int> store;
	        map<int,set<int> > direct;
	        for(int i=0;i<len;i++)
	        {
	            store[edges[i].first]++;
	            store[edges[i].second]++;
	            direct[edges[i].first].insert(edges[i].second);
	            direct[edges[i].second].insert(edges[i].first);
	        }

	        while(true)
	        {
	            map<int,int> tmp=store;
	            
	            if (store.size()>2)
	            {
	                for(map<int,int>::iterator it=store.begin();it!=store.end();it++)
	                {
	                    if (it->second==1)
	                    {
	                        set<int> prt = direct[it->first];
	                        tmp[*prt.begin()]--;
	                        direct[*prt.begin()].erase(it->first);
	                        tmp.erase(it->first);
	                    }
	                }
	            }
	            else
	            {
	                for(map<int,int>::iterator it=store.begin();it!=store.end();it++)
	                {
	                    rst.push_back(it->first);
	                }
	                break;
	            }

	            store=tmp;
	        }
	        return rst;
	    }
	};

	class Solution2 {
	public:
	    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
	        vector<int> rst;
	        if (n<=0) return rst;
	        if (n<=2)
	        {
	            for(int i=0;i<n;i++) rst.push_back(i);
	            return rst;
	        }
	        
	        vector<vector<int> > graph(n);
	        for(int i=0;i<edges.size();i++)
	        {
	            graph[edges[i].first].push_back(edges[i].second);
	            graph[edges[i].second].push_back(edges[i].first);
	        }

	        vector<int> path;
	        vector<int> maxpath;
	        path.push_back(-1);
	        path.push_back(0);
	        
	        int depth=1;
	        int maxdepth=1;
	        helper(graph,path, maxpath,depth,maxdepth);
	        path.resize(2);
	        path[0]=-1;
	        path[1]=maxpath[maxpath.size()-1];
	        maxpath = path;
	        depth=1;
	        maxdepth=1;
	        helper(graph,path, maxpath,depth,maxdepth);
	        maxpath.erase(maxpath.begin());
	        int len=maxpath.size();

	        rst.push_back(maxpath[len/2]);
	        if (len%2==0)
	        {
	            rst.push_back(maxpath[len/2-1]);
	        }
	        
	        return rst;
	    }
	    
	    void helper(vector<vector<int> >& graph, vector<int>& path, vector<int>& maxpath, int depth, int& maxdepth)
	    {
	        int curr = path.back();    
	        int pre = path[path.size()-2];
	        if (graph[curr].size()<=1 && pre!=-1)
	        {
	            if(depth>maxdepth)
	            {
	                maxdepth = depth;
	                maxpath = path;
	            }
	            return;
	        }
	        path.push_back(-1);
	        for(int i=0;i<graph[curr].size();i++)
	        {
	            if (graph[curr][i]!=pre)
	            {
	                path[depth+1]=graph[curr][i];
	                helper(graph,path,maxpath,depth+1,maxdepth);
	                
	            }
	        }
	        path.erase(path.begin()+path.size()-1);
	    }
	};

}

/****************************************************************************************************
                                             Note
Remove leaves layer by layer
Here is the better solution:

 public:
  vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    // Initialize the undirected graph
    vector<unordered_set<int>> adj(n);
    for (pair<int, int> p : edges) {
      adj[p.first].insert(p.second);
      adj[p.second].insert(p.first);
    }
    // Corner case
    vector<int> current;
    if (n == 1) {
      current.push_back(0);
      return current;
    }
    // Create first leaf layer
    for (int i = 0; i < adj.size(); ++i) {
      if (adj[i].size() == 1) {
        current.push_back(i);
      }
    }
    // BFS the graph
    while (true) {
      vector<int> next;
      for (int node : current) {
        for (int neighbor : adj[node]) {
          adj[neighbor].erase(node);
          if (adj[neighbor].size() == 1) next.push_back(neighbor);
        }
      }
      if (next.empty()) return current;
      current = next;
    }
  }
};

solution 2:
recursive solution. 
1: find the max depth from the random node
2: from this node, find the max, 
3: get the middle from the longest path.

****************************************************************************************************/