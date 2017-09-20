/****************************************************************************************************
                                    68. Text Justification           
-----------------------------------------------------------------------------------------------------
Given an array of words and a length L, format the text such that each line has exactly L characters 
and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a 
line do not divide evenly between words, the empty slots on the left will be assigned more spaces 
than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.


****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    vector<string> fullJustify(vector<string>& words, int maxWidth) {
	        vector<string> rst;
	        int iw=0;
	        if (words.size()==0 || maxWidth==0) {rst.push_back(""); return rst;}
	        while(iw<words.size())
	        {
	            vector<string> curr;
	            int len=-1;
	            int lenw = 0;
	            while(len<=maxWidth && iw<words.size())
	            {
	                len+=words[iw].size()+1;
	                lenw+=words[iw].size();
	                curr.push_back(words[iw]);
	                iw++;
	            }
	            
	            int ns = curr.size();
	            
	            if (len>maxWidth) 
	            {
	                lenw-=curr.back().size();
	                curr.pop_back();
	                ns--;
	                iw--;
	            }
	            
	            if (iw==words.size())  // ***
	            {
	                string line=curr[0];
	                int lenw=curr[0].size();
	                for(int i=1;i<curr.size();i++)
	                {
	                    line+=" ";
	                    line+=curr[i];
	                    lenw+=curr[i].size()+1;
	                }
	                for(int i=lenw;i<maxWidth;i++) line+=" ";
	                rst.push_back(line);
	                break;
	            }
	            
	            if (curr.size()==1)  // ***
	            {
	                string line=curr[0];
	                int lenw=curr[0].size();
	                for(int i=lenw;i<maxWidth;i++) line+=" ";
	                rst.push_back(line);
	                continue;
	            }
	            
	            int nspace = (maxWidth-lenw)/(ns==1?1:(ns-1));
	            int naddone = maxWidth-lenw-nspace*(ns==1?1:(ns-1))+1;
	            
	            string line=curr[0];
	            for(int i=1;i<naddone;i++)
	            {
	                // add space
	                for(int isp=0;isp<=nspace;isp++)
	                {
	                    line+=" ";
	                }
	                line+=curr[i];
	            }
	            
	            for(int i=naddone;i<curr.size();i++)
	            {
	                for(int isp=0;isp<nspace;isp++)
	                {
	                    line+=" ";
	                }
	                line+=curr[i];
	            }
	            rst.push_back(line);
	        }
	        return rst;
	    }
	};
     

    class Solution2 {
	public:
	    vector<string> fullJustify(vector<string>& words, int maxWidth) {
	        int len=words.size();
	        vector<string> rst;
	        
	        int i=0;
	        while(i<len)
	        {
	            vector<string> curr;
	            int sum=words[i].size();
	            curr.push_back(words[i]);
	            int icurr=i+1;
	            bool qend =false;
	            while(icurr<len && sum+1+words[icurr].size()<=maxWidth)
	            {
	                sum+=1+words[icurr].size();
	                curr.push_back(words[icurr]);
	                icurr++;
	            }
	            if (icurr>=len && sum<=maxWidth) qend=true;
	            i=icurr;
	            vector<int> spaces(curr.size()-1,1);
	            int nspace=1;
	            int leftspace=0;
	            if (!qend && curr.size()-1>0)
	            {
	                int gap=maxWidth-sum;
	                nspace += gap/(curr.size()-1);  // 1 ****
	                leftspace = gap - int(gap/(curr.size()-1))*(curr.size()-1);
	            }
	            string strcurr="";
	            for(int j=0;j<curr.size()-1;j++)
	            {
	                strcurr+=curr[j];
	                strcurr+=string(nspace,' ');
	                if (j<leftspace) strcurr+=' ';
	            }
	            strcurr+=curr.back();
	            strcurr+=string(maxWidth-strcurr.size(),' ');  // 2 ***
	            rst.push_back(strcurr);
	        }
	        return rst;
	    }
	};
}

/****************************************************************************************************
                                             Note
*** corner cases, if one word and last string
solution 2:

1: divided by zero
2: add more spaces if one word.
****************************************************************************************************/