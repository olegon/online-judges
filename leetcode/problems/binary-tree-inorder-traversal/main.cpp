/*
94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal
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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> elements;

        inorderTraversal(root, elements);

        return elements;
    }

    void inorderTraversal(TreeNode* root, vector<int> &elements) {
        if (root == nullptr) return;

        inorderTraversal(root->left, elements);
        elements.push_back(root->val);
        inorderTraversal(root->right, elements);
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
