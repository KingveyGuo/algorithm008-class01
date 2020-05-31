// 题目描述
// 32. 最长有效括号
// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len < 2) return 0;
        int rst = 0;
        // auto ValidParenthese = [](const string& str, int s, int e) -> bool
        // {
        //     if (e <= s || (e - s) % 2 == 0) return false;
        //     if (str[s] != '(' || str[e] != ')') return false;
        //     int lc = 0;
        //     for (int i = s; i <= e; i++)
        //     {
        //         if (str[i] == '(') lc++;
        //         else lc--;
        //         if (lc < 0 || lc > e - i) break;
        //     }
        //     return lc == 0;
        // };
        // for (int i = 0; i < len - 1; i++)
        // {
        //     for (int j = i + 1 + rst; j < len; j++)
        //     {
        //         if (ValidParenthese(s, i, j))
        //             rst = max(rst, j - i + 1);
        //     }
        // }
        vector<int> dp(len, 0);
        for (int i = 1; i < len; i++)
        {
            if (s[i] == '(') continue;
            if (s[i - 1] == '(')
            {
                dp[i] = 2;
                if (i > 2) dp[i] += dp[i - 2];
            }
            else
            {
                int pos = i - 1 - dp[i - 1];
                if (pos >= 0 && s[pos] == '(')
                {
                    dp[i] = dp[i - 1] + 2;
                    if (pos > 0) dp[i] += dp[pos - 1];
                }
            }
            rst = max(rst, dp[i]);
        }
        return rst;
    }
};

// 动态规划
// 1. 拆分求子字符串里最长有效括号的长度；
// 2. dp[i] 标识以i为结尾最长有效括号的长度；
// 3. (1) i 是'('时dp[i] = 0；
//    (2) i 是')'时：如果前一个是'(',dp[i] = dp[i-2]+2；
//                   如果前一个是')'并且同时满足dp[i-2]>0与位置(i - 1 - dp[i - 1])是'(',则 dp[i] = dp[i-2]+2+dp[i - 1 - dp[i - 1] - 1]；
// 注意判断位置有效性