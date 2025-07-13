/*
给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。

 

示例 1：

输入：n = 234
输出：15 
解释：
各位数之积 = 2 * 3 * 4 = 24 
各位数之和 = 2 + 3 + 4 = 9 
结果 = 24 - 9 = 15
示例 2：

输入：n = 4421
输出：21
解释： 
各位数之积 = 4 * 4 * 2 * 1 = 32 
各位数之和 = 4 + 4 + 2 + 1 = 11 
结果 = 32 - 11 = 21
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0, multi = 1;
        int temp = n;
        while (temp / 10 > 0) {
            sum += temp % 10;
            multi *= temp % 10;
            temp = temp / 10;
        }
        sum += temp;
        multi *= temp;
        return multi - sum;
    }
};

int main() {
    Solution s;
    int n = 234;
    cout << s.subtractProductAndSum(n) << endl; // 输出 15
    n = 4421;
    cout << s.subtractProductAndSum(n) << endl; // 输出 21
    return 0;
}