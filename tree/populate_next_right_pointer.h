
#include "common.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        connect(root, NULL);
    }

    void connect(TreeLinkNode *root, TreeLinkNode *root_right) {
        if (root == NULL) {
            return;
        }

        root->next = root_right;

        connect(root->left, root->right);
        connect(root->right, (root_right != NULL ? root_right->left : NULL));
    }
};
