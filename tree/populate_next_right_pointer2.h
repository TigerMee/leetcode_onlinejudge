

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

        TreeLinkNode *rr_child = NULL;
        while (root_right != NULL) {
            rr_child = root_right->left != NULL ? root_right->left : NULL;
            rr_child = rr_child != NULL ? rr_child : root_right->right;

            if (rr_child != NULL) break;
            root_right = root_right->next;
        }

        printf("node[%d], rr_child[%d]\n", root->val, rr_child != NULL ? rr_child->val : -1);

        connect(root->right, rr_child);
        connect(root->left,
                (root->right != NULL ? root->right : rr_child));

    }
};
