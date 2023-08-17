/*
109. Convert Sorted List to Binary Search Tree
https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;

        vector<int> orderedValues;

        ListNode *node = head;
        while (node != nullptr) {
            orderedValues.push_back(node->val);
            node = node->next;
        }

        return buildTree(orderedValues, 0, orderedValues.size() - 1);
    }

    TreeNode* buildTree(vector<int> &v, int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;

        return new TreeNode(v[mid], buildTree(v, left, mid - 1), buildTree(v, mid + 1, right));
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
