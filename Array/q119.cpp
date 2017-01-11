/****************************************************************************************************
                                   119. Pascal's Triangle II          
-----------------------------------------------------------------------------------------------------
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
****************************************************************************************************/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> rst;
        if (rowIndex<0) return rst;
        rst.resize(rowIndex+1,0);
        rst[0] = 1; 
        if (rowIndex==0) return rst; 
        for(int i=1;i<=rowIndex;i++)
        {
            for(int j=i;j>0;j--)
            {
                rst[j]=rst[j]+rst[j-1];
            }
        }
        return rst;
    }
};

/****************************************************************************************************
                                             Note
it really clever. remember this. 
****************************************************************************************************/