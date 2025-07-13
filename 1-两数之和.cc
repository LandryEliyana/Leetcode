/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution { // 假设每种输入只会对应一个答案
public: 
    vector<int> twoSum1(vector<int>& nums, int target) {
        // 方法1：暴力法
        int n  = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // 必须要有一个返回值，否则编译会报错
    }  
    vector<int> twoSum2(vector<int>& nums, int target) {
        // 方法2：哈希表
        int n = nums.size();
        unordered_map<int, int> hashmap;
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (hashmap.find(complement) != hashmap.end()) { // 找到了(必须检查)
                return {hashmap[complement], i};
            }
            hashmap[nums[i]] = i; // 没找到则存入哈希表
        }
        return {}; // 必须要有一个返回值，否则编译会报错
    }   
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result1 = solution.twoSum1(nums, target);
    vector<int> result2 = solution.twoSum2(nums, target);
    cout << "Input: nums = {2, 7, 11, 15}, target = 9" << endl;
    cout << "brute_solution: The two numbers are: " << nums[result1[0]] << " and " << nums[result1[1]] <<endl;
    cout << "hash_table_solution: The two numbers are: " << nums[result2[0]] << " and " << nums[result2[1]] <<endl;
    return 0;
}