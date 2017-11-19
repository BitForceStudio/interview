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

	class Solution2 {
	public:
	    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	        int len=wordList.size();
	        if(len==0) return 0;
	        
	        unordered_set<string> dictforward;
	        unordered_set<string> dictbackward;
	        unordered_map<string,int> bwlayer;
	        unordered_map<string,int> fwlayer;
	        
	        for(int i=0;i<len;i++)
	        {
	            dictforward.insert(wordList[i]);
	            dictbackward.insert(wordList[i]);
	        }
	        if(dictbackward.find(endWord)==dictbackward.end()) return 0;
	        
	        dictforward.erase(beginWord);
	        dictbackward.erase(beginWord);
	        
	        dictbackward.erase(endWord);
	        bwlayer[endWord]=1;
	        fwlayer[beginWord]=1;
	        
	        queue<string> qfw,qbw;
	        qfw.push(beginWord); qfw.push("");
	        qbw.push(endWord); qbw.push("");
	        
	        int dfw=1,dbw=1;
	        int rst=len+1;
	        while(!qfw.empty() && !qbw.empty())
	        {
	            if(dfw<=dbw)
	            {
	                string tfw = qfw.front();
	                qfw.pop();
	                if(tfw=="")
	                {
	                    dfw++;
	                    if(qfw.empty() || rst<len+1) break;
	                    qfw.push("");
	                }
	                else
	                {
	                    if(tfw!=beginWord && dictbackward.find(tfw)==dictbackward.end())
	                    {
	                        if(bwlayer.find(tfw)==bwlayer.end()) 
	                        {
	                            rst=0;
	                            break;
	                        }
	                        int tmp=bwlayer[tfw]+fwlayer[tfw]-1;
	                        rst=min(rst,tmp);
	                    }

	                    findword(qfw,dictforward,fwlayer,tfw,dfw);
	                }
	            }
	            else
	            {
	                string tbw = qbw.front();
	                qbw.pop();
	                if(tbw=="")
	                {
	                    dbw++;
	                    if(qbw.empty()) break;
	                    qbw.push("");
	                }
	                else
	                {
	                    findword(qbw,dictbackward,bwlayer,tbw,dbw);
	                }
	            }
	        }
	        return rst==len+1?0:rst;
	    }
	    
	    void findword(queue<string>& qt, unordered_set<string>& dict, unordered_map<string,int>& layer, string word, int nlayer)
	    {
	        for(int i=0;i<word.size();i++)
	        {
	            string tmp = word;
	            for(int j=0;j<26;j++)
	            {
	                tmp[i]='a'+j;
	                if(dict.find(tmp)!=dict.end())
	                {
	                    dict.erase(tmp);
	                    qt.push(tmp);
	                    layer[tmp]=nlayer+1;
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
Solution2 two way BFS
****************************************************************************************************/