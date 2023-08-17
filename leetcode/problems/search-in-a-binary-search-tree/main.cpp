/*
700. Search in a Binary Search Tree
https://leetcode.com/problems/search-in-a-binary-search-tree/
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr && root->val != val) {
            if (root->val > val) root = root->left;
            else root = root->right;
        }

        return root;

        // if (root == nullptr || root->val == val) return root;
        // else if (root->val > val) return searchBST(root->left, val);
        // else return searchBST(root->right, val);
    }
};

int main(void) {
    ios::sync_with_stdio(false);

    return EXIT_SUCCESS;
}
