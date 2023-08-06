/*
102. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal
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
    void levelOrder(const TreeNode* root, size_t level, vector<vector<int>>& valuesByLevel) const {
        if (root == nullptr) return;

        if (level >= valuesByLevel.size()) {
            valuesByLevel.push_back({ });
        }

        valuesByLevel[level].push_back(root->val);

        levelOrder(root->left, level + 1, valuesByLevel);
        levelOrder(root->right, level + 1, valuesByLevel);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> valuesByLevel;

        levelOrder(root, 0, valuesByLevel);
        
        return valuesByLevel;
    }
};


int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
