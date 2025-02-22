/****************************************************************************************************
                                      383. Ransom Note            
-----------------------------------------------------------------------------------------------------
Given an arbitrary ransom note string and another string containing letters from all the magazines, 
write a function that will return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    bool canConstruct(string ransomNote, string magazine) {
	        int lenm=magazine.size();
	        int lenr=ransomNote.size();
	        vector<int> map(26,0);
	        
	        for(int i=0;i<lenm;i++)
	        {
	            map[magazine[i]-'a']++;
	        }
	        
	        for(int i=0;i<lenr;i++)
	        {
	            map[ransomNote[i]-'a']--;
	            if (map[ransomNote[i]-'a']<0) return false;
	        }
	        
	        return true;
	    }
	};

}

/****************************************************************************************************
                                             Note
...
****************************************************************************************************/