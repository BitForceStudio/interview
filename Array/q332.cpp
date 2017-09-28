/****************************************************************************************************
                                 332. Reconstruct Itinerary            
-----------------------------------------------------------------------------------------------------
Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], 
reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, 
the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical 
order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical 
order than ["JFK", "LGB"].

All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> findItinerary(vector<pair<string, string>> tickets) {
	        int len = tickets.size();
	        vector<string> rst;
	        if (len<1) return rst;
	        
	        map<string, vector<string> > table;
	        for(int i=0;i<len;i++)
	        {
	            table[tickets[i].first].push_back(tickets[i].second);
	        }
	        
	        for(map<string,vector<string> >::iterator it=table.begin();it!=table.end();++it)
	        {
	            sort((it->second).begin(),(it->second).end());
	        }
	        
	        dfs("JFK",table,rst);
	        reverse(rst.begin(),rst.end());
	        return rst;
	    }
	    
	    void dfs(string curr, map<string, vector<string> >& table, vector<string>& rst)
	    {
	        while(table.find(curr)!=table.end() && table[curr].size()>0)
	        {
	            string next = table[curr][0];
	            table[curr].erase(table[curr].begin());
	            dfs(next,table,rst);
	        }
	        rst.push_back(curr);
	    }
	};

}

/****************************************************************************************************
                                             Note
1: it is Fleury algorithm.
2: need to order the ticket
****************************************************************************************************/