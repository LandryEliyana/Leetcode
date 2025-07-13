/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x

 

示例 1：

输入：n = 27
输出：true
示例 2：

输入：n = 0
输出：false
示例 3：

输入：n = 9
输出：true
示例 4：

输入：n = 45
输出：false
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    // Test cases
    int test1 = 27; // true
    int test2 = 0;  // false
    int test3 = 9;  // true
    int test4 = 45; // false

    std::cout << solution.isPowerOfThree(test1) << std::endl; // Output: 1 (true)
    std::cout << solution.isPowerOfThree(test2) << std::endl; // Output: 0 (false)
    std::cout << solution.isPowerOfThree(test3) << std::endl; // Output: 1 (true)
    std::cout << solution.isPowerOfThree(test4) << std::endl; // Output: 0 (false)

    return 0;
}