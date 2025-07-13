/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。 

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes1(vector<int>& nums) {
        // 两次遍历
        int n = nums.size();
        int left = 0, right = 0;
        while (right < n) {
            if (nums[right]!= 0) {
                nums[left++] = nums[right]; // 非零元素移动到左指针左边
            }
            right++; // 右指针右移
        }   
        while (left < n) {
            nums[left++] = 0; // 将剩余的元素全部置为0 
        }
    }
    void moveZeroes2(vector<int>& nums) {
        // 一次遍历
        int n = nums.size();
        int left = 0, right = 0;
        while (right < n) {
            if (nums[right]!= 0) {
                int temp = nums[right]; // 非零元素暂存
                nums[right] = nums[left]; // 将左指针位置的元素赋值给右指针位置
                nums[left] = temp; // 将非零元素放到左指针位置
                left++; // 左指针左移
            }
            right++; // 右指针右移
        } 
    }
};

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution solution;
    solution.moveZeroes2(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}