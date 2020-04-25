// 题目描述
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2)
        {
            return 0;
        }
        int iIndexL = 0;
        int iIndexM = 0;
        int iIndexR = height.size() - 1;
        bool bForward = true;
        int iTotal = 0;
        while (iIndexL < iIndexR - 1)
        {
            if (bForward)
            {
                if (height.at(++iIndexM) >= height.at(iIndexL))
                {
                    for (int iCur = iIndexL + 1; iCur < iIndexM; ++iCur)
                    {
                        iTotal += height.at(iIndexL) - height.at(iCur);
                    }
                    iIndexL = iIndexM;
                }
                if (iIndexM == iIndexR)
                {
                    bForward = false;
                }
            }
            else
            {
                if (height.at(--iIndexM) >= height.at(iIndexR))
                {
                    for (int iCur = iIndexR - 1; iCur > iIndexM; --iCur)
                    {
                        iTotal += height.at(iIndexR) - height.at(iCur);
                    }
                    iIndexR = iIndexM;
                }
                if (iIndexM == iIndexL)
                {
                    bForward = true;
                }
            }
        }
        return iTotal;
    }
};

// 两边向中间找
// 1.从左边开始，向右找到比左边大的，就算一下中间的蓄水量；
// 2.将左指针设置在当前找到的位置，然后从右向左找比右边大的；
// 重复1、2知道左右两边相遇
