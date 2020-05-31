// 题目描述
// 64. 最小路径和
// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        for (int rowCur = 0; rowCur < row; ++rowCur)
        {
            for (int colCur = 0; colCur < col; ++colCur)
            {
                if (rowCur == 0 && colCur == 0) continue;
                if (rowCur == 0) grid[rowCur][colCur] += grid[rowCur][colCur - 1];
                else if (colCur == 0) grid[rowCur][colCur] += grid[rowCur - 1][colCur];
                else grid[rowCur][colCur] += min(grid[rowCur - 1][colCur], grid[rowCur][colCur - 1]);
            }
        }
        return grid[row - 1][col - 1];
    }
};

// 1. 划分子问题：逐一计算以0,0为左上i,j为右下的网格的最小路径；
// 2. 状态定义方法：dp(i, j)表示以0,0为左上i,j为右下的网格的最小路径；
// 3. 状态转移方程(dp方程)：dp(i, j) = min(dp(i - 1, j), dp(i, j - 1)) + grid(i, j);
// 边缘处理：第一行 dp(0, j) = grid(0, j - 1) + grid(0, j);第一列 dp(i, 0) = grid(i - 1, 0) + grid(i, 0);