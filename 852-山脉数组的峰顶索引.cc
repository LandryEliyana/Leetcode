/*
给定一个长度为 n 的整数 山脉 数组 arr ，其中的值递增到一个 峰值元素 然后递减。

返回峰值元素的下标。

你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。

 

示例 1：

输入：arr = [0,1,0]
输出：1
示例 2：

输入：arr = [0,2,1,0]
输出：1
示例 3：

输入：arr = [0,10,5,2]
输出：1
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray1(vector<int>& arr) {
        // 方法一: 二分查找
        int left = 0, right = arr.size() - 1;
        int mid = (left + right) / 2;
        while (left < right) {
            if (mid >= left && mid <= right && arr[mid - 1] < arr[mid] && arr[mid + 1] < arr[mid]) {
                return mid;
            } 
            if (arr[mid - 1] > arr[mid]) {
                right = mid - 1;
                mid = (left + right) / 2;
            } 
            if (arr[mid + 1] > arr[mid]) {
                left = mid + 1;
                mid = (left + right) / 2;
            }
        }
        return left;
    }
    int peakIndexInMountainArray2(vector<int>& arr) {
        // 方法二: 枚举
        int n = arr.size();
        int ans = -1;
        for (int i = 1; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> arr1 = {0, 1, 0};
    vector<int> arr2 = {0, 2, 1, 0};
    vector<int> arr3 = {0, 5, 5, 10, 2};

    int index1 = solution.peakIndexInMountainArray1(arr1);
    int index2 = solution.peakIndexInMountainArray2(arr2);
    int index3 = solution.peakIndexInMountainArray1(arr3);

    cout << "index1: " << index1 << endl;
    cout << "index2: " << index2 << endl;
    cout << "index3: " << index3 << endl;

    return 0;
}