/****************************************************************************************************
                                   8. String to Integer (atoi)
-----------------------------------------------------------------------------------------------------
Implement atoi to convert a string to an integer.
****************************************************************************************************/

class Solution {
public:
  int maxnum = 214748364; // maxnum integer : -2147483647 -- 2147483647
  int myAtoi(string str) {
    if (str.size() == 0) return 0;
    int i = 0;
    while (true)
    {
      if (str[i] == '\0' || str[i] == '+' || str[i] == '-' || (int(str[i]) >= int('0') && int(str[i]) <= int('9')))
        break;
      if (str[i] != ' ') return 0;
      i++;
    }
    if (str[i] == '\0') return 0;
    int sign = str[i] == '-' ? -1 : 1;
    if (str[i] == '+' || str[i] == '-') i++;

    int result = 0;
    while (str[i] != '\0' && int(str[i]) >= int('0') && int(str[i]) <= int('9'))
    {
      if (result > maxnum) return sign>0 ? 2147483647 : -2147483648;
      if (result == maxnum)
      {
        if (sign>0 && int(str[i])>int('7')) return 2147483647;
        if (sign<0 && int(str[i])>int('8')) return -2147483648;
      }

      if (int(str[i]) >= int('0') && int(str[i]) <= int('9'))
      {
        result = result * 10 + int(str[i]) - int('0');
      }
      else
      {
        return sign*result;
      }
      i++;
    }

    return sign*result;

  }
};

/****************************************************************************************************
                                             Note
1: overflow problem, -2147483648 ~ 2147483647
2: skip all the space, but if the first non-space element is not number or sign, then return 0
****************************************************************************************************/