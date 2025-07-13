/*
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

 

示例 1：

输入：n = 1
输出：true
解释：20 = 1
示例 2：

输入：n = 16
输出：true
解释：24 = 16
示例 3：

输入：n = 3
输出：false
*/

#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo1(int n) {
        // 方法一: 枚举
        for (int i = 0; i < 31; i++) {
            if (n == pow(2, i)) {
                return true;
            }
        }
        return false;
    }
    bool isPowerOfTwo2(int n) {
        // 方法二: 位运算
        /*
        如果一个数是2的n次幂，那么，这个数换算成二进制，一定是最左边是1，其他位是0的形式
        比如4，它的二进制是100，8的二进制是1000
        n-1的二进制，一定是n的每一位取反，也就是1变成0，0变成1
        比如7的二进制是0111，3的二进制是011
        */
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    Solution s;
    int n = 16;
    cout << (s.isPowerOfTwo1(n) ? "true" : "false") << endl; // 输出 true
    n = 3;
    cout << (s.isPowerOfTwo1(n) ? "true" : "false") << endl; // 输出 false
    return 0;
}