/****************************************************************************************************
                                         54. Spiral Matrix    
-----------------------------------------------------------------------------------------------------
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
****************************************************************************************************/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> rst;
        int lenr = matrix.size();
        if (lenr==0) return rst;
        if (lenr==1) return matrix[0];
        
        int lenc = matrix[0].size();
        int rs=0,re=lenc-1,cs=0,ce=lenr-1;
        while(true)
        {
            if (rs>re || cs>ce) break;
            layer(rs,re,cs,ce,rst,matrix);
            rs++; re--;
            cs++; ce--;
        }
        
        return rst;
    }
    
    void layer(int rs,int re,int cs,int ce,vector<int>& rst,vector<vector<int> >& matrix)
    {
        if (rs==re && cs==ce) 
        {
            rst.push_back(matrix[rs][cs]); 
        }
        else if (rs==re && cs<ce)
        {
            for(int i=cs;i<=ce;i++) rst.push_back(matrix[i][re]);
        }
        else if (rs<re && cs==ce)
        {
            for(int i=rs;i<=re;i++) rst.push_back(matrix[cs][i]);
        }
        else
        {
            for(int i=rs;i<re;i++) rst.push_back(matrix[cs][i]);
            for(int i=cs;i<ce;i++) rst.push_back(matrix[i][re]);
            for(int i=re;i>rs;i--) rst.push_back(matrix[ce][i]);
            for(int i=ce;i>cs;i--) rst.push_back(matrix[i][rs]);
        }
    }
};

/****************************************************************************************************
                                             Note
1: need to consider the speical cases
2: figure it out the definition of row and colume
****************************************************************************************************/