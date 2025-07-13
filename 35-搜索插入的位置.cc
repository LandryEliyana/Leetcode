/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。

示例 1:

输入: nums = [1,3,5,6], target = 5
输出: 2
示例 2:

输入: nums = [1,3,5,6], target = 2
输出: 1
示例 3:

输入: nums = [1,3,5,6], target = 7
输出: 4
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n; // ans表示将要插入的位置
        while (left <= right) { // 二分查找
            int mid = (right - left) / 2 + left;
            if (target <= nums[mid]) { // 目标值在左半部分
                ans = mid; // 记录插入位置
                right = mid - 1; // 缩小右半部分的范围
            } else { // 目标值在右半部分
                left = mid + 1; // 缩小左半部分的范围
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    Solution solution;
    int ans = solution.searchInsert(nums, target);
    cout << ans << endl;
    return 0;
}