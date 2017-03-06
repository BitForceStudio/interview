/****************************************************************************************************
                                 126. Word Ladder II               
-----------------------------------------------------------------------------------------------------
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation 
sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
Note:
Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class DFSSolution  // find all possible solutions 
	{
	public:
	    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	        // BFS
	        vector<vector<string> > rst;
	        if (wordList.size()==0) return rst;
	        
	        set<string> wl;
	        for(string word:wordList) wl.insert(word);
	        vector<string> curr; curr.push_back(beginWord);
	        findWord(beginWord,endWord,wl,curr,rst);
	        return rst;
	    }
	    
	    void findWord(string bgword, string edword, set<string>& dict, vector<string>& curr, vector<vector<string> >& rst)
	    {
	        if (bgword==edword)
	        {
	            rst.push_back(curr);
	            return;
	        }
	        
	        for(int i=0;i<bgword.size();i++)
	        {
	            string tmp=bgword;
	            for(int j=0;j<26;j++)
	            {
	                tmp[i]='a'+j;
	                if (dict.find(tmp)!=dict.end())
	                {
	                    dict.erase(tmp);
	                    curr.push_back(tmp);
	                    findWord(tmp,edword,dict,curr,rst);
	                    curr.pop_back();
	                    dict.insert(tmp);
	                }
	            }
	        }
	    }

	};

	class BFSSolution   // Mem problem
	{
	public:
	    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	        // BFS
	        vector<vector<string> > rst;
	        if (wordList.size()==0) return rst;
	        
	        set<string> wl;
	        for(string word:wordList) wl.insert(word);
	        if (wl.find(beginWord)!=wl.end()) wl.erase(beginWord);
	        
	        set<string> qw;
	        qw.insert(beginWord);
	        
	        map<string,set<string> > graph;

	        while(!qw.empty())
	        {
	            bool qfound=false;
	            set<string> tqw;
	            for(string tmp:qw)
	            {
	                if (tmp==endWord)
	                {
	                    qfound=true;
	                    break;
	                }
	                findWord(tmp,wl,tqw,graph);
	            }
	            if(qfound) break;
	            qw=tqw;
	        }

	        vector<string> curr; curr.push_back(endWord);
	        dfs(endWord, beginWord, graph, curr, rst);
	        return rst;
	    }
	    
	    void findWord(string word , set<string>& dict, set<string>& tqw, map<string,set<string> >& graph)
	    {
	        for(int i=0;i<word.size();i++)
	        {
	            string tmp=word;
	            for(int j=0;j<26;j++)
	            {
	                tmp[i]='a'+j;
	                if ((dict.find(tmp)!=dict.end() || tqw.find(tmp)!=tqw.end()))
	                {
	                    if (graph[tmp].find(word)==graph[tmp].end()) graph[tmp].insert(word);
	                    if (tqw.find(tmp)==tqw.end()) tqw.insert(tmp);
	                    if(dict.find(tmp)!=dict.end()) dict.erase(tmp);
	                }
	            }
	        }
	    }
	    
	    void dfs(string bgword, string edword, map<string, set<string> > graph, vector<string>& curr, vector<vector<string> >& rst)
	    {
	        if (graph.find(bgword)!=graph.end())
	        {
	            set<string> tmp = graph[bgword];
	            for(string word:tmp)
	            {
	                curr.push_back(word);
	                if (word==edword) 
	                {
	                    vector<string> tmp;
	                    for(int i=curr.size()-1;i>=0;i--)
	                        tmp.push_back(curr[i]);
	                    rst.push_back(tmp);
	                }
	                else
	                {
	                    dfs(word,edword,graph,curr,rst);
	                }
	                curr.pop_back();
	            }
	        }
	    }
	};

	class TwoWayBFSSolution {
	public:
	    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	        // BFS
	        vector<vector<string> > rst;
	        if (wordList.size()==0) return rst;
	        vector<string> curr(1, beginWord);
	        
	        unordered_set<string> wl;
	        for(string word:wordList) wl.insert(word);
	        if (wl.find(beginWord)!=wl.end()) wl.erase(beginWord);
	        if (wl.find(endWord)==wl.end()) return rst;

	        unordered_set<string> forward, backward;
	        forward.insert(beginWord);
	        backward.insert(endWord);
	        unordered_map<string, vector<string> > tree;
	        
	        bool reversed = false; //make sure the tree generating direction is consistent, since we have to start from the smaller set to accelerate;
	        if (buildTree(forward, backward, wl, tree, reversed))
	            getPath(beginWord, endWord, tree, curr, rst);
	        return rst;
	        }
	    private:
	        bool buildTree(unordered_set<string> &forward, unordered_set<string> &backward, unordered_set<string> &dict, unordered_map<string, vector<string> > &tree, bool reversed) 
	        {
	            if (forward.empty()) return false;
	            if (forward.size() > backward.size()) 
	                return buildTree(backward, forward, dict, tree, !reversed);
	            for (auto &word: forward) dict.erase(word);
	            for (auto &word: backward) dict.erase(word);
	            unordered_set<string> nextLevel;
	            bool done = false; //in case of invalid further searching;
	            for (auto &it: forward) //traverse each word in the forward -> the current level of the tree;
	            {
	                string word = it;
	                for (auto &c: word) 
	                {
	                    char c0 = c; //store the original;
	                    for (c = 'a'; c <= 'z'; ++c) //try each case;
	                    {
	                        if (c != c0) //avoid futile checking;
	                        {
	                            if (backward.count(word))  //using count is an accelerating method;
	                            {
	                                done = true;
	                                !reversed ? tree[it].push_back(word) : tree[word].push_back(it); //keep the tree generation direction consistent;
	                            }
	                            else if (!done && dict.count(word))
	                            {
	                                nextLevel.insert(word);
	                                !reversed ? tree[it].push_back(word) : tree[word].push_back(it);
	                            }
	                        }
	                    }
	                    c = c0; //restore the word;
	                }
	            }
	            return done || buildTree(nextLevel, backward, dict, tree, reversed);
	        }

	        void getPath(string &beginWord, string &endWord, unordered_map<string, vector<string> > &tree, vector<string> &path, vector<vector<string> > &paths) //using reference can accelerate;
	        {
	            if (beginWord == endWord) paths.push_back(path); //till the end;
	            else
	            {
	                for (auto &it: tree[beginWord]) 
	                {
	                    path.push_back(it);
	                    getPath(it, endWord, tree, path, paths); //DFS retrieving the path;
	                    path.pop_back();
	                }
	            }
	        }
	};

}

/****************************************************************************************************
                                             Note
DFS is very easy to do. 
Optimized BFS can be good but mem limit
Two way BFS is new to me, so it needs more practice. 
****************************************************************************************************/