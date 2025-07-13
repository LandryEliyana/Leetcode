/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

 

示例 1：

输入：s = "Hello World"
输出：5
解释：最后一个单词是“World”，长度为 5。
示例 2：

输入：s = "   fly me   to   the moon  "
输出：4
解释：最后一个单词是“moon”，长度为 4。
示例 3：

输入：s = "luffy is still joyboy"
输出：6
解释：最后一个单词是长度为 6 的“joyboy”。
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        // 从后遍历
        int len = s.length();
        int j, result = 0;
        if (s[len - 1] == ' ') { // 去掉末尾空格
            for (int i = len - 1; i >= 0; i--) {
                if (s[i] != ' ') {
                    j = i; //找到最后一个单词的最后一个字母
                    break;
                }
            }
            for (j; j >= 0; j--) {
                if (s[j] != ' ') {
                    result++;
                } else {
                    return result;
                }
            }
        } else {
            for (int i = len - 1; i >= 0; i--) {
                if (s[i] != ' ') {
                    result++;
                } else {
                    return result; //遇到从后往前的第一个空格就返回
                }
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a string: ";
    getline(cin, s); // 使用getline以支持包含空格的字符串

    int result = solution.lengthOfLastWord(s);
    cout << "The length of the last word is: " << result << endl;

    return 0;
}