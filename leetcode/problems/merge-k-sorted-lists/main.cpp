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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;

        ListNode *head = lists[0];

        for (size_t i = 1; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }

        return head;
    }

    ListNode *mergeTwoLists(ListNode* a, ListNode *b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;

        ListNode *head;
        ListNode *current;

        if (a->val < b->val) {
            head = current = a;
            a = a->next;
        }
        else {
            head = current = b;
            b = b->next;
        }

        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                current = current->next = a;
                a = a->next;
            }
            else {
                current = current->next = b;
                b = b->next;
            }
        }

        while (a != nullptr) {
            current = current->next = a;
            a = a->next;
        }

        while (b != nullptr) {
            current = current->next = b;
            b = b->next;
        }

        return head;
    }
};

// This is an O(K^2) solution, but the there are up to 10^4 lists.
// Its O(1) in space complexity.
class QuadraticSolution {
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
