/****************************************************************************************************
                                        118. Pascal's Triangle     
-----------------------------------------------------------------------------------------------------
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
****************************************************************************************************/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > rst; 
        if (numRows==0) return rst;
        vector<int> feed; feed.push_back(1);
        rst.push_back(feed);
        if (numRows==1) return rst;
        
        for(int i=1;i<numRows;i++)
        {
            vector<int> curr; curr.resize(i+1,1);
            for(int j=1;j<i;j++)
            {
                curr[j] = feed[j-1]+feed[j];
            }
            feed=curr;
            rst.push_back(feed);
        }
        return rst;
    }
};

/****************************************************************************************************
                                             Note
...
****************************************************************************************************/