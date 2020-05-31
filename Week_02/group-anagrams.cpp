// 题目描述
// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> rst;
        if (strs.size() == 0)
        {
            return rst;
        }
        vector<int*> strsCharNum;
        for (string str : strs)
        {
            strsCharNum.push_back(getCharNum(str));
        }
        vector<int> charNumPos;
        rst.push_back(vector<string>());
        rst[0].push_back(strs[0]);
        charNumPos.push_back(0);
        for (int i = 1; i < strs.size(); ++i)
        {
            bool bFind = false;
            int j = 0;
            for (; j < charNumPos.size(); ++j)
            {
                if (compareCharNum(strsCharNum[charNumPos[j]], strsCharNum[i]))
                {
                    bFind = true;
                    break;
                }
            }
            if (bFind)
            {
                rst[j].push_back(strs[i]);
            }
            else
            {
                rst.push_back(vector<string>());
                rst[charNumPos.size()].push_back(strs[i]);
                charNumPos.push_back(i);
            }
        }
        return rst;
    }
    int* getCharNum(string str)
    {
        int* iCount = new int[26]{0};
        for (int i = 0; i < str.length(); ++i)
        {
            iCount[str[i] - 'a'] += 1;
        }
        return iCount;
    }

    bool compareCharNum(int* charNum1, int* charNum2)
    {
        for (int i = 0; i < 26; ++i)
        {
            if (charNum1[i] != charNum2[i])
            {
                return false;
            }
        }
        return true;
    }
};

// 先计算出每个字符串的字母数表，再按字母数表分组
// 效率不如直接对每个字符串排序后再做哈希表查找快，下次优化