// 题目描述
// 给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int im = m - 1;
        int in = n - 1;
        int iInsert = m + n - 1;
        while (in >= 0 && im >=0)
        {
            if (nums2[in] > nums1[im])
            {
                nums1[iInsert--] = nums2[in--];
            }
            else
            {
                nums1[iInsert--] = nums1[im--];
            }
        }
        if (im < 0)
        {
            for (; in >= 0; in--)
            {
                nums1[in] = nums2[in];
            }
        }
    }
};

// 从两个数组末尾开始判断，把大的放最后，知道遍历完为止
