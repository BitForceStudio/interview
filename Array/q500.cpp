/****************************************************************************************************
                                500. Keyboard Row             
-----------------------------------------------------------------------------------------------------
Given a List of words, return the words that can be typed using letters of alphabet on only one row's 
of American keyboard like the image below.


American keyboard


Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> findWords(vector<string>& words) {
	        int len=words.size();
	        vector<string> rst;
	        if (len==0) return rst;
	        
	        vector<set<char> > kb(3);
	        kb[0].insert('Q'); kb[0].insert('W'); kb[0].insert('E'); kb[0].insert('R'); kb[0].insert('T');
	        kb[0].insert('q'); kb[0].insert('w'); kb[0].insert('e'); kb[0].insert('r'); kb[0].insert('t');
	        kb[0].insert('Y'); kb[0].insert('U'); kb[0].insert('I'); kb[0].insert('O'); kb[0].insert('P');
	        kb[0].insert('y'); kb[0].insert('u'); kb[0].insert('i'); kb[0].insert('o'); kb[0].insert('p');
	        
	        kb[1].insert('A'); kb[1].insert('S'); kb[1].insert('D'); kb[1].insert('F'); kb[1].insert('G'); 
	        kb[1].insert('a'); kb[1].insert('s'); kb[1].insert('d'); kb[1].insert('f'); kb[1].insert('g');
	        kb[1].insert('H'); kb[1].insert('J'); kb[1].insert('K'); kb[1].insert('L'); 
	        kb[1].insert('h'); kb[1].insert('j'); kb[1].insert('k'); kb[1].insert('l'); 
	        
	        kb[2].insert('Z'); kb[2].insert('X'); kb[2].insert('C'); kb[2].insert('V');
	        kb[2].insert('z'); kb[2].insert('x'); kb[2].insert('c'); kb[2].insert('v'); 
	        kb[2].insert('B'); kb[2].insert('N'); kb[2].insert('M'); 
	        kb[2].insert('b'); kb[2].insert('n'); kb[2].insert('m'); 
	        
	        for(int i=0;i<len;i++)
	        {
	            int curr=0;
	            for(int j=0;j<3;j++) 
	            {
	                if (kb[j].find(words[i][0])!=kb[j].end())
	                {
	                    curr=j;
	                    break;
	                }
	            }
	            
	            bool qfound=true;
	            for(int j=1;j<words[i].size();j++)
	            {
	                if (kb[curr].find(words[i][j])==kb[curr].end())
	                {
	                    qfound=false;
	                    break;
	                }
	            }
	            if (qfound) rst.push_back(words[i]);
	        }
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Easy...
****************************************************************************************************/