/*
1302. Deepest Leaves Sum
https://leetcode.com/problems/deepest-leaves-sum
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
    size_t maxLevel = 0;
    size_t sum = 0;

    void deepestLeavesSum(const TreeNode* node, size_t level) {
        if (node == nullptr) return;

        if (level == maxLevel) {
            sum += node->val;
        }
        else if (level > maxLevel) {
            maxLevel = level;
            sum = node->val;
        }

        deepestLeavesSum(node->left, level + 1);
        deepestLeavesSum(node->right, level + 1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        deepestLeavesSum(root, 0);

        return sum;
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
