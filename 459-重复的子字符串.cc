/*
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

示例 1:

输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。
示例 2:

输入: s = "aba"
输出: false
示例 3:

输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
*/

#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern1(string s) {
        // 方法一: 枚举子串长度，判断是否能由该子串重复构成
        int n = s.size();
        for (int i = 1; i * 2 <= n; i++) {  // 子字符串长度不能超过一半
            if (n % i == 0) {
                bool match = true;
                for (int j = i; j < n; j++) {
                    if (s[j] != s[j - i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    return true;
                }
            }
        }
        return false;
    }
    bool repeatedSubstringPattern2(string s) {
        // 方法二: 字符串匹配
        /*
            思路: 先将字符串 s 重复一次，得到字符串 s+s。
            然后从s+s的第二个字符开始判断是否有子串s的出现。
            如果不到s的结尾就可以在s+s中匹配到s，则说明s由子串重复构成。
            如果到s的结尾才可以在s+s中匹配到s，则说明s不由子串重复构成。
        */
        return (s + s).find(s, 1) != s.size();
    }
};

int main() {
    Solution solution;
    // 测试用例
    string s1 = "abab";
    string s2 = "aba";
    string s3 = "abcabcabcabc";

    // 输出结果
    bool result1 = solution.repeatedSubstringPattern1(s1);
    bool result2 = solution.repeatedSubstringPattern1(s2);
    bool result3 = solution.repeatedSubstringPattern1(s3);

    return 0;
}