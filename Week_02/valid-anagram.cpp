// 题目描述
// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        {
            return false;
        }
        int iCount[26] = {0};
        for (int i = 0; i < s.length(); ++i)
        {
            iCount[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < t.length(); ++i)
        {
            iCount[t[i] - 'a'] -= 1;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (iCount[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

// 创建一个26位的数组，直接记录第一个字符串的字母个数，再同第二个字符串做减法，数组最后全为0则返回true
