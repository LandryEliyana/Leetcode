/*
给你一个整数数组 nums 。

如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。

返回好数对的数目。

 

示例 1：

输入：nums = [1,2,3,1,1,3]
输出：4
解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
示例 2：

输入：nums = [1,1,1,1]
输出：6
解释：数组中的每组数字都是好数对
示例 3：

输入：nums = [1,2,3]
输出：0
*/

#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs1(vector<int>& nums) {
        // 方法一：枚举法
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    ans++;
                }
            }
        }
        return ans;
    } 
    int numIdenticalPairs2(vector<int>& nums) {
        // 方法二：组合计数
        unordered_map<int, int> mp; // 哈希表，key=数字，value=该数字已出现次数
        int ans = 0;
        for (int num : nums) { // 遍历数组
            ans += mp[num];    // 关键：累加当前数字已有的频次
            mp[num]++;         // 更新当前数字的频次
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 1, 1, 3};
    vector<int> nums2 = {1, 1, 1, 1};
    vector<int> nums3 = {1, 2, 3};

    cout << "Example 1: " << solution.numIdenticalPairs2(nums1) << endl; // 输出：4
    cout << "Example 2: " << solution.numIdenticalPairs2(nums2) << endl; // 输出：6
    cout << "Example 3: " << solution.numIdenticalPairs2(nums3) << endl; // 输出：0

    return 0;
}