
#include "common.h"

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int height = 0;
        return isBalanced(root, &height);
    }

    bool isBalanced(TreeNode *root, int *p_height) {
        if (root == NULL) {
            *p_height = 0;
            return true;
        }

        int lh = 0, rh = 0;
        if (!isBalanced(root->left, &lh)
            || !isBalanced(root->right, &rh)) {
                return false;
        }
        if (abs(lh-rh) > 1) {
            return false;
        }

        *p_height = max(lh, rh) + 1;
        return true;
    }
};
