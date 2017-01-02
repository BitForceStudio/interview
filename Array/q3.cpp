/****************************************************************************************************
                      3. Longest Substring Without Repeating Characters      
-----------------------------------------------------------------------------------------------------
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
"pwke" is a subsequence and not a substring.
****************************************************************************************************/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<bool> exist; exist.resize(256,false);
        int curr = 0;
        int maxlen = 0;
        for(int i=0;i<int(s.size());i++)
        {
            while(exist[int(s[i])])
            {
                exist[int(s[curr])] = false;
                curr++;
            }
            exist[int(s[i])] = true;
            maxlen = maxlen<i-curr+1?i-curr+1:maxlen;
        }
        return maxlen;
    }
};

/****************************************************************************************************
                                             Note
Hint: use the so-called hash table. default as false, two pointers, one is faster and one is slower.
if faster find the repeating, slower move to the repeat ones and set all chars before repeat to be 
false.
****************************************************************************************************/