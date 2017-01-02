/****************************************************************************************************
                                   14. Longest Common Prefix          
-----------------------------------------------------------------------------------------------------
Write a function to find the longest common prefix string amongst an array of strings.
It seems that it is not to check between pair of strings but on all the strings in the array.

For example:

{"a","a","b"} should give "" as there is nothing common in all the 3 strings.

{"a", "a"} should give "a" as a is longest common prefix in all the strings.

{"abca", "abc"} as abc

{"ac", "ac", "a", "a"} as a.
****************************************************************************************************/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string rst;
        if (strs.size()==0) return rst;
        if (strs.size()==1) return strs[0];

        int len = strs.size();
        int ic = 0;
        bool qfound = true;
        while(1)
        {
            char cpr = ' ';
            if (ic < strs[0].size())
                cpr = strs[0][ic];
            else
                break;
            for(int i=1;i<len;i++)
            {
                if (ic < strs[i].size())
                {
                    if (strs[i][ic]!=cpr) qfound = false;
                }
                else
                {
                    qfound = false;
                }
            }
            if (!qfound) break;
            rst.push_back(cpr);
            ic++;
        }
        return rst;
    }
};

/****************************************************************************************************
                                             Note
Be carefull about the break range. So, use a bool para to set the right one. 
****************************************************************************************************/