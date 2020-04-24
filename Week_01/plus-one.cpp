// 题目描述
// 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool bNeedInsert = false;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
                bNeedInsert = i == 0;
            }
            else
            {
                digits[i] += 1;
                break;
            }
        }
        if (bNeedInsert)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

// 从最后一位开始加，不是9就直接加1，是9就设0进一位，如果进位的是第一个数，就在最前面插入一个1
