/*
给你两个整数，n 和 start 。

数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。

请返回 nums 中所有元素按位异或（XOR）后得到的结果。

 

示例 1：

输入：n = 5, start = 0
输出：8
解释：数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
     "^" 为按位异或 XOR 运算符。
示例 2：

输入：n = 4, start = 3
输出：8
解释：数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8.
示例 3：

输入：n = 1, start = 7
输出：7
示例 4：

输入：n = 10, start = 5
输出：2
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        // std::vector<int> nums(n);
        // for (int i = 0; i < n; i++) {
        //     nums[i] = start + 2 * i;
        // }
        // int result = nums[0];
        // for (int i = 1; i < n; i++) {
        //     result = result ^ nums[i];
        // }
        // return result;
        int ans = start; // 初始值
        for (int i = 1; i < n; i++) {
            ans ^= start + 2 * i; // 异或运算
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.xorOperation(5, 0) << endl; // 8
    cout << s.xorOperation(4, 3) << endl; // 8
    cout << s.xorOperation(1, 7) << endl; // 7
    cout << s.xorOperation(10, 5) << endl; // 2
    return 0;
}