/*
给定两个字符串 s 和 t ，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

示例 1：

输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
示例 2：

输入：s = "", t = "y"
输出："y"
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    char findTheDifference1(string s, string t) {
        // 方法一: 计数
        vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch - 'a']++; // 统计 s 中每个字母出现的次数
        }
        for (char ch: t) {
            cnt[ch - 'a']--; // 遍历字符串 t，对其中的每个字符都将计数值减 1
            if (cnt[ch - 'a'] < 0) {
                return ch;
            }
        }
        return ' ';
    }
    char findTheDifference2(string s, string t) {
        // 方法二: 求和
        int as = 0, at = 0;
        for (char ch: s) {
            as += ch;
        }
        for (char ch: t) {
            at += ch;
        }
        return at - as;
    }
};

int main() {
    Solution s;
    string s1 = "abcd";
    string t1 = "abcde";
    cout << s.findTheDifference1(s1, t1) << endl; // e
    string s2 = "";
    string t2 = "y";
    cout << s.findTheDifference2(s2, t2) << endl; // y
    return 0;
}