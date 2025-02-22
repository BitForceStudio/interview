/****************************************************************************************************
                                             
-----------------------------------------------------------------------------------------------------

****************************************************************************************************/
#include "problems\problems\Header.h"

namespace std
{

	class Solution {
	public:
	    string minWindow(string s, string t) {
	    	unordered_map<char, int> m;
	    	// Statistic for count of char in t
	    	for (auto c : t) m[c]++;
	    	// counter represents the number of chars of t to be found in s.
	    	size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
	    	size_t size = s.size();
	    	
	    	// Move end to find a valid window.
	    	while (end < size) {
	    		// If char in s exists in t, decrease counter
	    		if (m[s[end]] > 0)
	    			counter--;
	    		// Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
	    		m[s[end]]--;
	    		end++;
	    		// When we found a valid window, move start to find smaller window.
	    		while (counter == 0) {
	    			if (end - start < minLen) {
	    				minStart = start;
	    				minLen = end - start;
	    			}
	    			m[s[start]]++;
	    			// When char exists in t, increase counter.
	    			if (m[s[start]] > 0)
	    				counter++;
	    			start++;
	    		}
	    	}
	    	if (minLen != INT_MAX)
	    		return s.substr(minStart, minLen);
	    	return "";
	    }
	};

	class Solution2 {
	public:
	    string minWindow(string s, string t) {
	        int lens = s.size();
	        int lent = t.size();
	        if(lens<lent || lent==0) return "";
	        
	        string rst=s;
	        vector<int> mapt(128,0);
	        for(int i=0;i<lent;i++) mapt[t[i]]++;
	        
	        vector<int> maps(128,0);
	        int st=0,ed=0,nf=0;
	        bool qfound=false;
	        while(ed<lens)
	        {
	            if(mapt[s[ed]]>0)
	            {
	                maps[s[ed]]++;
	                bool qf=true;
	                if(!qfound)
	                {
	                    for(int i=0;i<128;i++)
	                    {
	                        if(maps[i]<mapt[i])
	                        {
	                            qf=false;
	                            break;
	                        }
	                    }
	                }
	                
	                if(qf)
	                {
	                    // update s
	                    while(st<ed)
	                    {
	                        if (mapt[s[st]]>0 && maps[s[st]]==mapt[s[st]])
	                        {
	                            break;
	                        }
	                        else if (mapt[s[st]]>0)
	                        {
	                            maps[s[st]]--;
	                        }
	                        st++;
	                    }
	                    
	                    if(rst.size()>(ed-st))
	                    {
	                        rst=s.substr(st,(ed-st+1));
	                    }
	                    qfound=true;
	                }
	            }
	            ed++;
	        }
	        
	        if (!qfound) return "";
	        return rst;
	    }
	};

}

/****************************************************************************************************
                                             Note
Thanks zjh08177 for this great idea. Let me explain this algorithm.

1. Use two pointers: start and end to represent a window.
2. Move end to find a valid window.
3. When a valid window is found, move start to find a smaller window.
To check if a window is valid, we use a map to store (char, count) for chars in t. And use counter 
for the number of chars of t to be found in s. The key part is m[s[end]]--;. We decrease count for 
each char in s. If it does not exist in t, the count will be negative.

To really understand this algorithm, please see my code which is much clearer, because there is no 
code like if(map[s[end++]]++>0) counter++;.

string minWindow(string s, string t) {
	unordered_map<char, int> m;
	// Statistic for count of char in t
	for (auto c : t) m[c]++;
	// counter represents the number of chars of t to be found in s.
	size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
	size_t size = s.size();
	
	// Move end to find a valid window.
	while (end < size) {
		// If char in s exists in t, decrease counter
		if (m[s[end]] > 0)
			counter--;
		// Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
		m[s[end]]--;
		end++;
		// When we found a valid window, move start to find smaller window.
		while (counter == 0) {
			if (end - start < minLen) {
				minStart = start;
				minLen = end - start;
			}
			m[s[start]]++;
			// When char exists in t, increase counter.
			if (m[s[start]] > 0)
				counter++;
			start++;
		}
	}
	if (minLen != INT_MAX)
		return s.substr(minStart, minLen);
	return "";
}
The code above costs 76ms. If we change the first line 
unordered_map<char, int> m; to vector<int> m(128, 0);, it costs 12ms.

Template:
Here comes the template.

For most substring problem, we are given a string and need to find a substring of it which satisfy 
some restrictions. A general way is to use a hashmap assisted with two pointers. The template is 
given below.
****************************************************************************************************/
int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
  }
//  One thing needs to be mentioned is that when asked to find maximum substring, we should update 
//  maximum after the inner while loop to guarantee that the substring is valid. On the other hand, 
//  when asked to find minimum substring, we should update minimum inside the inner while loop.

//  The code of solving Longest Substring with At Most Two Distinct Characters is below:

int lengthOfLongestSubstringTwoDistinct(string s) {
        vector<int> map(128, 0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++==0) counter++;
            while(counter>2) if(map[s[begin++]]--==1) counter--;
            d=max(d, end-begin);
        }
        return d;
    }
//The code of solving Longest Substring Without Repeating Characters is below:

//Update 01.04.2016, thanks @weiyi3 for advise.

int lengthOfLongestSubstring(string s) {
        vector<int> map(128,0);
        int counter=0, begin=0, end=0, d=0; 
        while(end<s.size()){
            if(map[s[end++]]++>0) counter++; 
            while(counter>0) if(map[s[begin++]]-->1) counter--;
            d=max(d, end-begin); //while valid, update d
        }
        return d;
    }
//I think this post deserves some upvotes! : )
