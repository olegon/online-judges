/*
129. Sum Root to Leaf Numbers
https://leetcode.com/problems/sum-root-to-leaf-numbers
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
    int sumNumbers(TreeNode* node, int previousValue) {
        if (node == nullptr) return 0;
        
        int currentValue = previousValue * 10 + node->val;

        if (node->left == nullptr && node->right == nullptr) return currentValue;
        return sumNumbers(node->left, currentValue) + sumNumbers(node->right, currentValue);
    }
public:
    int sumNumbers(TreeNode* root) {
        return sumNumbers(root, 0);
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
