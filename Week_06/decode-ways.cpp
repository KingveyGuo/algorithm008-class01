// 题目描述
// 91. 解码方法
// 一条包含字母 A-Z 的消息通过以下方式进行了编码：
//	'A' -> 1
//	'B' -> 2
//	...
//	'Z' -> 26
// 给定一个只包含数字的非空字符串，请计算解码方法的总数。

class Solution {
public:
    int numDecodings(string s) {
        int l = s.length();
        if (l == 0 || s[0] == '0') return 0;
        int rstLL = 1, rstL = 1, rst = 1;
        for (int i = 1; i < l; ++i)
        {
            if (s[i] == '0')
            {
                if (s[i - 1] == '1' || s[i - 1] == '2') rst = rstLL;
                else return 0;
            }
            else if (s[i - 1] == '0')
            {
                rst = rstL;
            }
            else if (s[i - 1] == '1')
            {
                rst = rstL + rstLL;
            }
            else if (s[i - 1] == '2')
            {
                if (s[i] > '0' && s[i] < '7') rst = rstL + rstLL;
                else rst = rstL; 
            }
            else
            {
                rst = rstL;
            }
            rstLL = rstL;
            rstL = rst;
        }
        return rst;
    }
};

// 1. 划分子问题：逐一计算0-i段的解码方法数量；
// 2. 状态定义方法：dp(i)表示0-i段的解码方法数量；
// 3. 状态转移方程(dp方程)：当前字符与前一字符是可以组合dp(i) = dp(i - 1) + dp(i - 2)，否则dp(i) = dp(i - 1);当前为0，前一个为1/2，dp(i) = dp(i - 2)，否则无解;
// 边缘处理：第一个是0无解