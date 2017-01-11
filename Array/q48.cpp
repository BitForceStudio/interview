/****************************************************************************************************
                                      48. Rotate Image       
-----------------------------------------------------------------------------------------------------
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
****************************************************************************************************/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        if (len<=1) return;
        int l=0,h=len-1;
        while(l<h)
        {
            for(int i=l;i<h;i++)
            {
                swap(matrix[l][i],matrix[i][h]);
                swap(matrix[l][i],matrix[h][h-(i-l)]);
                swap(matrix[l][i],matrix[h-(i-l)][l]);
            }
            ++l;
            --h;
        }
    }
};

/****************************************************************************************************
                                             Note
swap function

need to draw it. 
****************************************************************************************************/