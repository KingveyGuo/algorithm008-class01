// 题目描述
// 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int iCount = nums.size();
        k %= iCount;
        int iNum = 0;
        for (int i = 0; i < iCount; ++i)
        {
            int iCur = i;
            int iNext = (iCur + k) % iCount;
            int iPrev = nums[iNext];
            nums[iNext] = nums[iCur];
            iNum++;
            while (iNext != i)
            {
                iCur = iNext;
                iNext = (iCur + k) % iCount;
                int tmp = nums[iNext];
                nums[iNext] = iPrev;
                iPrev = tmp;
                iNum++;
            }
            if (iNum >= iCount)
            {
                break;
            }
        }
	}
};
// 环状换座位，需要一定的观察分析
// 1. 外层for循环实现环切换
// 2. 第一个交换在while外进行
// 3. 记录交换次数，避免冗余处理

// 这种交换真的很容易把人绕进去，以后得加强练习
