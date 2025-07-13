/*
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

示例 1：

输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
示例 2：

输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.length();
        int len2 = needle.length();
        int j;
        for (int i = 0; i < len1; i++) {
            if (haystack[i] == needle[0]) {
                j = 1;
                for(j = 1; j < len2; j++) {
                    if (haystack[i + j] != needle[j]) {
                        break;
                    }
                }
            }
            if (j == len2) {
                return i;
            }
        }
        return -1;
    }
};

int main() {    
    Solution solution;
    string haystack, needle;
    
    cout << "Enter the haystack string: ";
    cin >> haystack;
    cout << "Enter the needle string: ";
    cin >> needle;

    int result = solution.strStr(haystack, needle);
    cout << "The first occurrence of needle in haystack is at index: " << result << endl;

    return 0;
}