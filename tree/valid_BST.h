
#include "common.h"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isValid(root, NULL, NULL);
    }

    bool isValid(TreeNode *root, int *min, int *max) {
        if (root == NULL) {
            return true;
        }
        if (min != NULL && root->val <= *min) return false;
        if (max != NULL && root->val >= *max) return false;

        if (!isValid(root->left, min, &(root->val))) return false;
        if (!isValid(root->right, &root->val, max)) return false;

        return true;
    }
};
