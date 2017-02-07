/****************************************************************************************************
                         211. Add and Search Word - Data structure design             
-----------------------------------------------------------------------------------------------------
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or 
.. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class WordDictionary {
	public:
	    /** Initialize your data structure here. */
	    WordDictionary() {
	        m_dict=new DictTreeNode();
	    }
	    
	    /** Adds a word into the data structure. */
	    void addWord(string word) {
	        int len=word.size();
	        DictTreeNode* dict = m_dict;
	        if (len==0) return;
	        for(int i=0;i<len;i++)
	        {
	            if (!(dict->children[word[i]-'a']))
	            {
	                dict->children[word[i]-'a'] = new DictTreeNode();
	            }
	            dict=dict->children[word[i]-'a'];
	        }
	        dict->qEnd=true;
	    }
	    
	    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	    bool search(string word) {
	        int len=word.size();
	        DictTreeNode* dict = m_dict;
	        if (len==0) return true;
	        return findChild(dict,word);
	    }
	private:
	    struct DictTreeNode
	    {
	        bool qEnd;
	        vector<DictTreeNode*> children;
	        DictTreeNode(): qEnd(false),children(26,NULL) {}
	    };
	    
	    DictTreeNode* m_dict;
	    
	    bool findChild(DictTreeNode* root, string curr)
	    {
	        DictTreeNode* currNode=root;
	        for(int i=0;i<curr.size();i++)
	        {
	            if (currNode!=NULL)
	            {
	                if (curr[i]=='.')
	                {
	                    DictTreeNode* tmp=currNode;
	                    for(int j=0;j<26;j++)
	                    {
	                        currNode=tmp->children[j];
	                        if (!currNode) continue;
	                        if (findChild(currNode,curr.substr(i+1,curr.size()-i-1)))
	                            return true;
	                    }
	                }
	                else
	                {
	                    currNode=currNode->children[curr[i]-'a'];
	                }
	            }
	            else
	                break;
	        }
	        return currNode && currNode->qEnd;
	    }
	};

	/**
	 * Your WordDictionary object will be instantiated and called as such:
	 * WordDictionary obj = new WordDictionary();
	 * obj.addWord(word);
	 * bool param_2 = obj.search(word);
	 */

}

/****************************************************************************************************
                                             Note
Samilar idea, but basically from the solution....
****************************************************************************************************/