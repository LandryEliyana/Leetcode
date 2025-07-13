/*
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast, slow = 0; // 快慢指针
        for (fast = 1; fast < n; fast++) { // 遍历数组
            if (nums[fast] != nums[slow]) { // 如果快指针指向的元素不等于慢指针指向的元素
                slow += 1; // 指针后移
                nums[slow] = nums[fast]; // 复制元素到慢指针指向的位置
            }
        }
        return slow + 1; // 返回新长度
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    int newLength = solution.removeDuplicates(nums);
    
    // 输出新长度和修改后的数组
    cout << "New length: " << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}