/*
101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        else return isSymmetric(root->right, root->left);
    }

    bool isSymmetric(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr) return false;
        else if (q == nullptr) return false;
        else return p->val == q->val && isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
