/*
给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。

矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：matrix = [[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> transposed(col, vector<int>(row));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                transposed[j][i] = matrix[i][j];
            }
        }
        return transposed;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6}};
    vector<vector<int>> result = s.transpose(matrix);
    for (auto row : result) {
        for (auto num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}