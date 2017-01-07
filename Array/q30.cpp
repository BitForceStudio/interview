/****************************************************************************************************
                            30. Substring with Concatenation of All Words              
-----------------------------------------------------------------------------------------------------
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
****************************************************************************************************/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> rst;
        int lensrc = s.size();
        if (words.size()==0) return rst; 
        int lenrfc = words.size()*words[0].size();
        int lenwd = words[0].size();
        if (lenrfc==0) return rst;
        
        map<string,int> wordmap;   // <"words",index> if wordmap[key] != curry index, set to index, if == index, break;
        for(int i=0;i<words.size();i++) wordmap[words[i]] += 1;
        
        for(int i=0;i<lensrc-lenrfc+1;i++)
        {
            bool qfound = true;
            map<string,int> swordmap;
            for(int j=i;j<i+lenrfc;j+=lenwd)
            {
                string tmp = s.substr(j,lenwd);
                // not found
                if (wordmap.find(tmp)==wordmap.end()) 
                {
                    qfound=false;
                    break;
                }
                // found on this time
                swordmap[tmp]+=1;
                
                // more duplicate
                if (wordmap[tmp]<swordmap[tmp])
                {
                    qfound=false;
                    break;
                }
            }
            
            if (qfound) 
            {
                map<string,int>::iterator itw=wordmap.begin();
                for(;itw != wordmap.end();itw++)
                {
                    if (swordmap[itw->first]!=itw->second)
                    {
                        qfound =false;
                        break;
                    }
                }
            }
            
            if (qfound) rst.push_back(i);
            
        }
        
        return rst;
    }
};

/****************************************************************************************************
                                             Note
Remember to consider there could be duplications in words. and how to iterator the map.

map<*,*>::iterator it=map.begin();
it++;
it!=map.end();
****************************************************************************************************/