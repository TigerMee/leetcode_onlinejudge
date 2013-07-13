
#include "common.h"
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return sum(root, 0);
    }

    int sum(TreeNode *root, int parent) {
        if (root == NULL)
            return 0;

        int val = parent * 10 + root->val;
        int left = sum(root->left, val);
        int right = sum(root->right, val);

        if (left == 0 && right == 0)
            return val;

        return left+right;
    }
};
