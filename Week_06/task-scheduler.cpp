// 题目描述
// 621. 任务调度器
// 给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
// 然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
// 你需要计算完成所有任务所需要的最短时间。

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskNum = tasks.size();
        if (taskNum < 2) return taskNum;
        vector<int> taskCount(26, 0);
        for (int i =0; i < taskNum; i++)
            taskCount[tasks[i] - 'A'] += 1;
        int rst = 0;
        while (taskNum > 0)
        {
            sort(taskCount.begin(), taskCount.end(), greater<int>());
            int iEnd = 0;
            while (iEnd < taskCount.size() && taskCount[iEnd] > 0) iEnd++;
            if (iEnd < taskCount.size()) taskCount.erase(taskCount.begin() + iEnd, taskCount.end());
            int iStart = 0;
            for (int i = 0; i < n + 1; i++)
            {
                if (iStart == taskCount.size())
                {
                    rst += n + 1 - i;
                    break;
                }
                taskCount[iStart++] -= 1;
                taskNum--;
                rst++;
                if (taskNum == 0) break;
            }
        }
        return rst;
    }
};

// 贪心解法
// 1. 桶排序方式确定26个字母各自个数；
// 2. 对字母按个数从大到小排序；
// 3. 开始任务排序，n + 1个任务为一组，从字母计数里第一个开始取，没有了补0，知道字母全部用完；