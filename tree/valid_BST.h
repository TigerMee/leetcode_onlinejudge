
#include "common.h"

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValid(TreeNode *root, int min, int max) {
        if (root == NULL)
            return true;
        if (root->val <= min || root->val >= max)
            return false;
        return isValid(root->left, min, root->val)
                && isValid(root->right, root->val, max);
    }
};
