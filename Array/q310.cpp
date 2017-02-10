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
****************************************************************************************************/