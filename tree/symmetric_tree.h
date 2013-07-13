
#include "common.h"

// iteratively
class Solution1 {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }

        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        vector<TreeNode*> *cur_v = &v1;
        vector<TreeNode*> *last_v = &v2;

        v1.push_back(root->left);
        v1.push_back(root->right);

        while (!cur_v->empty()) {
            last_v->clear();
            if (!isValid(*cur_v))   return false;

            for (size_t i = 0; i < cur_v->size(); i++) {
                last_v->push_back((*cur_v)[i]->left);
                last_v->push_back((*cur_v)[i]->right);
            }
            vector<TreeNode*> *tmp = cur_v;
            cur_v = last_v;
            last_v = tmp;
        }
        return true;
    }

    bool isValid(vector<TreeNode*> &v) {
        if (v.size() % 2 != 0) {
            return false;
        }
        int begin = 0;
        int end = v.size() - 1;
        while (begin < end) {
            if ((v[begin] == NULL && v[end] != NULL)
                || (v[begin] != NULL && v[end] == NULL)) {
                return false;
            }
            if ((v[begin] == NULL && v[end] == NULL)
                || (v[begin]->val == v[end]->val)) {
                begin++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }
};



// recursively
class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }
        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode *t1, TreeNode *t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        } else if (t1 == NULL || t2 == NULL) {
            return false;
        }

        return t1->val == t2->val
                && isSym(t1->left, t2->right)
                && isSym(t1->right, t2->left);
    }
};
