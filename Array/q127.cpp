/****************************************************************************************************
                                     127. Word Ladder        
-----------------------------------------------------------------------------------------------------
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest 
transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	        if (wordList.size()==0) return 0;
	        
	        set<string> wl;
	        for (int i=0;i<wordList.size();i++)
	            wl.insert(wordList[i]);
	            
	        queue<string> qw;
	        
	        qw.push(beginWord);
	        qw.push("");
	        int dist = 1;
	        while(!qw.empty())
	        {
	            string tmp = qw.front();
	            qw.pop();
	            if (tmp=="") 
	            {
	                dist++; 
	                if (!qw.empty()) 
	                    qw.push("");
	                continue;
	            }
	            if(tmp==endWord) return dist;
	            findWords(tmp,wl,qw);
	        }
	        return 0;
	    }
	    
	    void findWords(string word, set<string>& dict, queue<string>& qw)
	    {
	        for(int j=0;j<word.size();j++)
	        {
	            string tmp = word;
	            for(int k=0;k<26;k++)
	            {
	                tmp[j]='a'+k;
	                if (dict.find(tmp)!=dict.end())
	                {
	                    qw.push(tmp);
	                    dict.erase(tmp);
	                }
	            }
	        }
	    }

	};

}

/****************************************************************************************************
                                             Note
my originial idea worked, but not that good. this one is better.
However, it needs two way BFS. 
****************************************************************************************************/