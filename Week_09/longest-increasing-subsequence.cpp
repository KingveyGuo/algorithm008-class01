// 题目描述
// 300. 最长上升子序列
// 给定一个无序的整数数组，找到其中最长上升子序列的长度。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> dp(nums.size(), 1);
        int rst = 1;
        for (int i =1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            rst = max(rst, dp[i]);
        }
        return rst;
    }
};

// 状态定义 dp[i] 以第i个数结尾的最长上升子序列长度
// 状态转移 dp[i] = nums[i] > nums[j] ? max(dp[i], dp[j] + 1) : dp[i]