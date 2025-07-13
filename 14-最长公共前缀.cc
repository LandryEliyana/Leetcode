/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
 

提示：

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] 如果非空，则仅由小写英文字母组成
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        int n = strs.size();
        
        // 如果输入字符串数组为空，直接返回空字符串
        if (n == 0) {
            return s;
        }

        // 如果只有一个字符串，返回该字符串本身
        if (n == 1) {
            return strs[0];
        }

        // 遍历第一个字符串的每个字符
        for (int i = 0; i < strs[0].length(); i++) {
            char currentChar = strs[0][i];
            // 从第二个字符串开始比较
            for(int j = 1; j < n; j++) {
                // 如果当前索引超过某个字符串的长度，或者字符不匹配，则返回当前公共前缀
                if (i >= strs[j].length() || strs[j][i] != currentChar) {
                    return s;
                }
            }
            // 如果所有字符串在当前位置字符相同，则加入公共前缀
            s += currentChar;
        }
        return s;
    }    
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Input: strs = [";
    for (int i = 0; i < strs.size(); i++) {
        cout << "\"" << strs[i] << "\", ";
    }
    cout << "]" << endl;
    cout << solution.longestCommonPrefix(strs) << endl;
    return 0;
}