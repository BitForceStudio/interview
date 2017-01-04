/****************************************************************************************************
                           17. Letter Combinations of a Phone Number                     
-----------------------------------------------------------------------------------------------------
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
****************************************************************************************************/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> rst;
        if (digits.empty()) return rst;
        rst.push_back("");
        static const vector<string> map={" ","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i=0;i<digits.size();i++)
        {
            int dig = digits[i]-'0';
            if(dig<0 || dig>9) continue;
            
            vector<string> tmp;
            for(int j=0;j<map[dig].size();j++)
            {
                for(int k=0;k<rst.size();k++)
                {
                    tmp.push_back(rst[k]+map[dig][j]);
                }
            }
            rst=tmp;
        }
        
        return rst;
    }
};

/****************************************************************************************************
                                             Note
exchange the rst and tmp is the key. 
****************************************************************************************************/