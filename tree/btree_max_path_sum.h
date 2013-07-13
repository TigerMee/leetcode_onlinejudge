
#include "common.h"

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return 0;
        }

        int lsp, rsp;
        int mleft = maxPathSum(root->left, lsp);
        int mright = maxPathSum(root->right, rsp);

        // �path֮�ͣ�����֮��ȡ���
        // 1. root->val + max(lsp, 0) + max(rsp, 0);
        // 2. mleft
        // 3. mright
        int mpath = root->val + max(lsp, 0) + max(rsp, 0);
        if (root->left != NULL) {
            mpath = max(mpath, mleft);
        }
        if (root->right != NULL) {
            mpath = max(mpath, mright);
        }

        return mpath;
    }

    int maxPathSum(TreeNode *root, int &max_sp) {
        if (root == NULL) {
            return 0;
        }

        int lsp = 0, rsp = 0;
        int mleft = maxPathSum(root->left, lsp);
        int mright = maxPathSum(root->right, rsp);

        // �����
        max_sp = max(lsp, rsp);
        max_sp = max(max_sp, 0);
        max_sp += root->val;

        // �path֮�ͣ�����֮��ȡ���
        // 1. root->val + max(lsp, 0) + max(rsp, 0);
        // 2. mleft
        // 3. mright
        int mpath = root->val + max(lsp, 0) + max(rsp, 0);
        if (root->left != NULL) {
            mpath = max(mpath, mleft);
        }
        if (root->right != NULL) {
            mpath = max(mpath, mright);
        }

        printf("node[%d]: mpath[%d], mspath[%d].\n",
               root->val, mpath, max_sp);
        return mpath;
    }
};
