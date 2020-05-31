// 题目描述
// 647. 回文子串
// 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

class Solution {
public:
    int countSubstrings(string s) {
        if (s.length() == 0) return 0;
        int rst = 0;
        // auto GetMaxPalindrome = [](const string& str, int s, int e) -> int
        // {
        //     int rst = 0;
        //     while (s >= 0 && e < str.length() && str[s--] == str[e++]) rst++;
        //     return rst;
        // };
        // for (int i = 0; i < s.length(); ++i)
        // {
        //     rst += GetMaxPalindrome(s, i, i);
        //     rst += GetMaxPalindrome(s, i, i + 1);
        // }
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for (int i = s.length() - 1; i >= 0; i--)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) dp[i][j] = true, rst++;

            }
        }
        return rst;
    }
};

// 1. 遍历搜索，每一个位置为回文中心时的回文长度；
// 2. 动态规划，当前范围是否回文 = 两端字符相同 && 去掉两端后是回文；