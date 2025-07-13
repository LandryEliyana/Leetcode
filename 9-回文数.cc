/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome1(int x) {
        // 方法一: 不将数字转换为字符串 会遇到整数溢出的问题！
        bool ispalindrome = true;
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            ispalindrome = false;
        }
        if (x > 0) {
            int x1 = x;
            int x2 = 0;
            vector<int> nums;
            while (x1 / 10 != 0) {
                x2 = x2 * 10 + x1 % 10;
                x1 = x1 / 10;
            }
            x2 = x2 * 10 + x1 % 10;
            if (x == x2) {
                ispalindrome = true;
            } else {
                ispalindrome = false;
            }
        }
        return ispalindrome;
    }

    bool isPalindrome2(int x) {
        // 方法二: 将数字转换为字符串 需要额外的空间！
        string str = to_string(x);
        int len = str.length();
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome3(int x) {
        // 方法三: 只判断前一半和后一半数字
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int y = 0;
        int x1 = x;
        while (x > y) {
            y = y * 10 + x1 % 10;
            x1 = x1 / 10;
        }
        if (x == y || x == y / 10) { // 偶数位数的回文数 || 奇数位数的回文数
            // 例如: 12321, y = 123, x1 = 12
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution solution;
    int x;
    cout << "please input a integer: " << endl;
    cin >> x;
    bool result = solution.isPalindrome3(x);
    cout << "Input: x = " << x << endl;
    cout << "Output: " << boolalpha << result << endl;
    return 0;
}