// 题目描述
// 221. 最大正方形
// 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rst = 0;
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;
        vector<int> rstRow(col, 0);
        int rstCol = 0;
        for (int rowCur = 0; rowCur < row; rowCur++)
        {
            for (int colCur = 0; colCur < col; colCur++)
            {
                int rstCur = 0;
                if (rowCur != 0 && colCur != 0)
                {
                    if (matrix[rowCur][colCur] != '0')
                    {
                        rstCur = min(rstCol, min(rstRow[colCur - 1], rstRow[colCur])) + 1;
                    }
                }
                else if (matrix[rowCur][colCur] == '1')
                {
                    rstCur = 1;
                }
                rst = max(rst, rstCur);
                if (colCur > 0) rstRow[colCur - 1] = rstCol;
                rstCol = rstCur;
            }
            rstRow[col - 1] = rstCol;
            rstCol = 0;
        }
        return rst * rst;
    }
};

// 1. 划分子问题：逐一计算以当前i,j为正方形右下角的最大正方形边长；
// 2. 状态定义方法：dp(i, j)表示以(i,j)为正方形右下角的最大正方形边长；
// 3. 状态转移方程(dp方程)：当前格数值为0，dp(i, j) = 0;当前格是1，dp(i, j) = min(dp(i - 1, j), dp(i, j - 1)) + 1;
// 边缘处理：第一行、第一列dp(i, j) = matrix(i, j);