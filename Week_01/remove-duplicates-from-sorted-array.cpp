// 题目描述
// 给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() > 1)
        {
            int i = 0;
            int j = 1;
            while (j < nums.size())
            {
                if (nums[i] == nums[j])
                {
                    j++;
                }
                else
                {
                    nums[++i] = nums[j++];
                }
            }
            int iCount = nums.size() - i - 1;
            while (iCount-- > 0)
            {
                nums.pop_back();
            }
        }
        return nums.size();
    }
};

// 双指针解法
// 1. 开始前指针指向起始数字，后指针指向下一数字
// 2. 如果后指针数字与前指针相同，前指针不动，可以把后指针当前位置设置为0(题目没有要求)，后指针加1；否则，前指针加1，前指针指向位置赋值为后指针数字，后指针加1；
// 3. 后指针搜索到末尾停止；
