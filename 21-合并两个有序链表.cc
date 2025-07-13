/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例 1：
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
*/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        // 方法一: 递归合并两个链表
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        } else if (list1->val < list2->val) {
            list1 -> next = mergeTwoLists1(list1 -> next, list2);
            return list1;
        } else {
            list2 -> next = mergeTwoLists1(list1, list2 -> next);
            return list2;
        }
    }
    ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
        // 方法二: 迭代合并两个链表
        ListNode* preHead = new ListNode(-1);
        ListNode* prev = preHead;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;

        return preHead->next;
    }
};

int main() {
    Solution solution;
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* mergedList = solution.mergeTwoLists1(l1, l2);
    while (mergedList != nullptr) { // 打印合并后的链表
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;
    return 0;
}