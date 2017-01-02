/****************************************************************************************************
                                  6. ZigZag Conversion
-----------------------------------------------------------------------------------------------------

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you 
may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
****************************************************************************************************/


// problem: misunderstand the zigzag direction on second colume...
class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (s.size()<=numRows || numRows==1) return s;

		int nCol = s.size()%(numRows-1)==0?s.size()/(numRows-1):s.size()/(numRows-1)+1;
		int len = s.size();
		string cvt(s.size(),'0');
		
		if (numRows==2)
        {
            int add = len%2!=0;
            for(int i=0;i<len/2+1;i++)
            {
                if (i*2<len)
                    cvt[i] = s[i*2];
                if (i*2+1<len)
                    cvt[len/2+add+i] = s[i*2+1]; 
            }
            return cvt;
        }

		for (int i=0;i<len;i++)
		{
			int dst= 0;

			if(i%(2*numRows-2)==0)
			{
				dst = i/(2*numRows-2);
			}
			else if(i%(2*numRows-2)==(numRows-1))
			{
				dst = len-int(nCol/2)+int(i/(2*numRows-2));
			}
			else
			{
			    if (nCol%2==0)
				    dst = int(nCol/2)+int(i%(numRows-1)-1)*nCol+int(i/(numRows-1));
				else
				{
				    
				}
			}

			if (dst<s.size())
				cvt[dst]=s[i];
		}
        
        return cvt;
    }
};

// change mind... from dest to src
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vs(numRows, "");
        int n = s.length(), i = 0;
        while (i < n) {
            for (int j = 0; j < numRows && i < n; j++)
                vs[j].push_back(s[i++]);
            for (int j = numRows - 2; j >= 1 && i < n; j--)
                vs[j].push_back(s[i++]);
        }
        string zigzag;
        for (string v : vs) zigzag += v;
        return zigzag;
    } 
};