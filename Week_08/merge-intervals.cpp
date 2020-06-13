// 题目描述
// 56. 合并区间
// 给出一个区间的集合，请合并所有重叠的区间。

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end(), 
        [](const vector<int>& left, const vector<int>& right) -> bool 
        {
            return left[0] < right[0];
        });
        int index = 1;
        vector<vector<int>> rst;
        rst.push_back(vector<int>(intervals[0]));
        while (index < intervals.size())
        {
            int endIndex = rst.size() - 1;
            if (rst[endIndex][1] < intervals[index][0]) rst.push_back(vector<int>(intervals[index++]));
            else if (rst[endIndex][1] < intervals[index][1]) rst[endIndex][1] = intervals[index++][1];
            else index++;
        }
        return rst;
    }
};

// 先给所有区间排序，再从头遍历一遍进行合并