/*
如果数组是单调递增或单调递减的，那么它是 单调 的。

如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i] >= nums[j]，那么数组 nums 是单调递减的。

当给定的数组 nums 是单调数组时返回 true，否则返回 false。

示例 1：

输入：nums = [1,2,2,3]
输出：true
示例 2：

输入：nums = [6,5,4,4]
输出：true
示例 3：

输入：nums = [1,3,2]
输出：false
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        int x = nums[n-1] > nums[0] ? 1 : -1; // 确定单调性质
        for (int i = 0;i < n-1; i++) {
            if (x * (nums[i + 1] - nums[i]) < 0)  {
                return false; 
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {11,11,9,4,3,3,3,1,-1,-1,3,3,3,5,5,5};
    cout << s.isMonotonic(nums) << endl;
    return 0;    
}