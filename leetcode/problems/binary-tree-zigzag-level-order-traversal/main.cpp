/*
103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
*/

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void zigzagLevelOrder(const TreeNode* node, size_t level, vector<vector<int>> &valuesByLevel) const {
        if (node == nullptr) return;

        if (level == valuesByLevel.size()) {
            valuesByLevel.push_back({});
        }

        zigzagLevelOrder(node->left, level + 1, valuesByLevel);
        valuesByLevel[level].push_back(node->val);
        zigzagLevelOrder(node->right, level + 1, valuesByLevel);
    }

    void reverse(vector<int> &v) const {
        size_t size = v.size();
        size_t halfSize = size / 2;

        for (size_t i = 0; i < halfSize; i++) {
            auto aux = v[i];
            v[i] = v[size - i - 1];
            v[size - i - 1] = aux;
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> valuesByLevel;

        zigzagLevelOrder(root, 0, valuesByLevel);

        for (size_t i = 1; i < valuesByLevel.size(); i += 2) {
            reverse(valuesByLevel[i]);
        }

        return valuesByLevel;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
