/*
21. Merge Two Sorted Lists
https://leetcode.com/problems/merge-two-sorted-lists
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* list1Current = list1;
        ListNode* list2Current = list2;
        ListNode* mergedListCurrent = nullptr;
        ListNode* mergedList = nullptr;

        if (list1Current->val < list2Current->val) {
            mergedList = mergedListCurrent = list1Current;
            list1Current = list1Current->next;
        }
        else {
            mergedList = mergedListCurrent = list2Current;
            list2Current = list2Current->next;
        }

        while (list1Current != nullptr && list2Current != nullptr) {
            if (list1Current->val < list2Current->val) {
                mergedListCurrent->next = list1Current;
                list1Current = list1Current->next;
            }
            else {
                mergedListCurrent->next = list2Current;
                list2Current = list2Current->next;
            }

            mergedListCurrent = mergedListCurrent->next;
        }

        while (list1Current != nullptr) {
            mergedListCurrent->next = list1Current;
            list1Current = list1Current->next;
            mergedListCurrent = mergedListCurrent->next;
        }

        while (list2Current != nullptr) {
            mergedListCurrent->next = list2Current;
            list2Current = list2Current->next;
            mergedListCurrent = mergedListCurrent->next;
        }

        return mergedList;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
