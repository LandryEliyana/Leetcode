/*
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement1(vector<int>& nums, int val) {
        // 方法一：依次删除等于val的元素
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) { // 注意数组长度在变化，所以不能用for循环的范围
            if (nums[i] == val) {
                nums.erase(nums.begin() + i); // 使用erase函数删除等于val的元素
                i -= 1; // 注意要减去1，因为删除元素后数组长度减少了
            }
        }
        return nums.size();
    }
    int removeElement2(vector<int>& nums, int val) {
        // 方法二：左右指针
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int left = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] != val) {
                nums[left++] = nums[right]; // 左指针右移
            }
        }
        return left;
    }
    int removeElement3(vector<int>& nums, int val) {
        // 方法三：左右指针优化
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right]; // 左指针右移
                right--; // 右指针左移
            } else {
                left++; // 左指针右移
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int result = solution.removeElement1(nums, val);
    cout << "Input: nums = [";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "], val = " << val << endl;
}