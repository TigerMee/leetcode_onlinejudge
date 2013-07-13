
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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) return;

        TreeNode *left = root->left;
        TreeNode *right = root->right;
        flatten(root->left);
        flatten(root->right);

        root->left = NULL;
        root->right = left;
        TreeNode *cur = root;
        while (cur->right != NULL)
            cur = cur->right;
        cur->right = right;
    }
};
