// 题目描述
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int iPre = 0;
        while (iPre < nums.size() && nums[iPre] != 0) iPre++;
        int iCur = iPre;
        while (++iCur < nums.size())
        {
            if (nums[iCur] != 0)
            {
                swap(nums[iPre++],nums[iCur]);
            }
        }
    }
};
// 两个游标
// 先找到第一个是0的
// 向后找非零的，找到一个就交换，换一次前一个加一
