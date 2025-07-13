/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram1(string s, string t) {
        // 方法一: 计数
        vector<int> cnt(26, 0);
        for (char ch: s) {
            cnt[ch - 'a']++; // 统计 s 中每个字母出现的次数
        }
        for (char ch: t) {
            cnt[ch - 'a']--; // 遍历字符串 t，对其中的每个字符都将计数值减 1
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0) {
                return false;
            }
        }
        return true;
    }
    bool isAnagram2(string s, string t) {
        // 方法二: 排序
        if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


int main() {
    Solution s;
    string s1 = "anagram";
    string s2 = "nagaram";
    bool res = s.isAnagram1(s1, s2);
    cout << res << endl;
    return 0;
}