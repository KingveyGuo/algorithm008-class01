// 题目描述
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapIndex;
        vector<int> rst;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto itr = mapIndex.find(nums[i]);
            if (itr != mapIndex.end())
            {
                rst.push_back(itr->second);
                rst.push_back(i);
                break;
            }
            mapIndex[target - nums[i]] = i;
        }
        return rst;
    }
};

// 一次遍历，遍历过的元素加入map中方便查找，用无序map降低插入耗时
