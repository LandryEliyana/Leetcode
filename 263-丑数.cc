/*
丑数 就是只包含质因数 2、3 和 5 的 正 整数。

给你一个整数 n ，请你判断 n 是否为 丑数 。如果是，返回 true ；否则，返回 false 。

 

示例 1：

输入：n = 6
输出：true
解释：6 = 2 × 3
示例 2：

输入：n = 1
输出：true
解释：1 没有质因数。
示例 3：

输入：n = 14
输出：false
解释：14 不是丑数，因为它包含了另外一个质因数 7 。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        // 当n>0时，若n是丑数，则 n 可以写成 n=2^a * 3^b * 5^c 的形式，其中 a、b、c 都是非负整数。
        if (n <= 0) {
            return false;
        }
        vector<int> factors = {2, 3, 5};
        for (int factor : factors) {
            while (n %factor == 0) {
                n /= factor;
            }
        }
        return n == 1;
    }
};

int main() {
    Solution solution;
    int n = 6;
    bool result = solution.isUgly(n);
    cout << result << endl;
    return 0;
}