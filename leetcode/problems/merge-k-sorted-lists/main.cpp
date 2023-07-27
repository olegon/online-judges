/*
23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists
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

// This is an O(N^2) solution, but the there are up to 10^4 nodes in lists parameter.
// Its O(1) in space complexity.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head;
        ListNode *current;

        head = current = takeOutTheSmallestNode(lists);

        while (current != nullptr) {
            current->next = takeOutTheSmallestNode(lists);
            current = current->next;
        }

        return head;
    }

    ListNode* takeOutTheSmallestNode(vector<ListNode*>& lists) {
        ListNode *smallestNode = nullptr;
        size_t smallestIndex = 0;

        for (size_t i = 0; i< lists.size(); i++) {
            ListNode* node = lists[i];

            if (node != nullptr
                && (smallestNode == nullptr
                    || node->val < smallestNode->val)) {
                smallestNode = node;
                smallestIndex = i;
            }
        }

        if (smallestNode != nullptr) {
            lists[smallestIndex] = smallestNode->next;
        }

        return smallestNode;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
