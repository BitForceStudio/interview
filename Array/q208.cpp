/****************************************************************************************************
                                 208. Implement Trie (Prefix Tree)            
-----------------------------------------------------------------------------------------------------
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.                                            
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Trie {
	public:
	    /** Initialize your data structure here. */
	    Trie() {
	        m_dict=new TrieTree('0',false); // root is 0
	    }
	    
	    /** Inserts a word into the trie. */
	    void insert(string word) {
	        int len=word.size();
	        if (len==0) return;
	        TrieTree* cd = m_dict;
	        for(int i=0;i<len;i++)
	        {
	            TrieTree* curr = findChild(cd,word[i],i==len-1,false);
	            if (curr==NULL)
	            {
	                TrieTree* nNode = new TrieTree(word[i],i==len-1);
	                cd->children.push_back(nNode);
	                cd=nNode;
	            }
	            else
	            {
	                cd = curr;
	            }
	        }
	    }
	    
	    /** Returns if the word is in the trie. */
	    bool search(string word) {
	        int len=word.size();
	        if (len==0) return true;
	        TrieTree* cd=m_dict;
	        
	        for(int i=0;i<len;i++)
	        {
	            TrieTree* curr = findChild(cd,word[i],i==len-1,false);
	            if (curr==NULL) return false;
	            cd=curr;
	        }
	        
	        return true;
	    }
	    
	    /** Returns if there is any word in the trie that starts with the given prefix. */
	    bool startsWith(string prefix) {
	        int len=prefix.size();
	        if (len==0) return true;
	        TrieTree* cd=m_dict;
	        
	        for(int i=0;i<len;i++)
	        {
	            TrieTree* curr = findChild(cd,prefix[i],i==len-1,true);
	            if (curr==NULL) return false;
	            cd=curr;
	        }
	        return true;
	    }
	    
	private:
	    struct TrieTree
	    {
	        char c;
	        bool qEnd;
	        vector<TrieTree*> children;
	        TrieTree(char input, bool qe) : c(input), qEnd(qe), children() {}
	    };
	    TrieTree* m_dict;
	    
	    TrieTree* findChild(TrieTree* curr, char c, bool qEnd, bool qPre)
	    {
	        int len=curr->children.size();
	        if (len==0) return NULL;
	        if(!qPre)
	        {
	            for(int i=0;i<len;i++)
	            {
	                if (curr->children[i]->c==c && curr->children[i]->qEnd==qEnd)
	                {
	                    return curr->children[i];
	                }
	            }
	        }
	        else
	        {
	            for(int i=0;i<len;i++)
	            {
	                if (!qEnd)
	                {
	                    if (curr->children[i]->c==c && curr->children[i]->qEnd==qEnd)
	                    {
	                        return curr->children[i];
	                    }
	                }
	                else
	                {
	                    if (curr->children[i]->c==c)
	                    {
	                        return curr->children[i];
	                    }
	                }
	            }
	        }
	        return NULL;
	    }
	};

	/**
	 * Your Trie object will be instantiated and called as such:
	 * Trie obj = new Trie();
	 * obj.insert(word);
	 * bool param_2 = obj.search(word);
	 * bool param_3 = obj.startsWith(prefix);
	 */

}

/****************************************************************************************************
                                             Note
Improvement: change the find method, maybe use map <char,TrieTree*> qEnd = true means it could act as
word end.
****************************************************************************************************/