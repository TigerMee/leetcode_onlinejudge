

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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::deque<TreeNode*> cur;
        std::deque<TreeNode*> next;
        std::deque<TreeNode*> *p_cur = &cur;
        std::deque<TreeNode*> *p_next = &next;
        bool inorder = true;

        cur.push_back(root);

        vector<vector<int> > res;
        vector<int> v;
        while (!p_cur->empty()) {
            TreeNode *n = p_cur->front();
            p_cur->pop_front();


            if (n != NULL) {
                v.push_back(n->val);

                if (inorder) {
                    p_next->push_front(n->left);
                    p_next->push_front(n->right);
                } else {
                    p_next->push_front(n->right);
                    p_next->push_front(n->left);
                }
            }

            if (p_cur->empty()) {
                if (!v.empty()) {
                    res.push_back(v);
                    v.clear();
                }
                inorder = !inorder;
                std::deque<TreeNode*> *p_tmp = p_cur;
                p_cur = p_next;
                p_next = p_tmp;
            }
        }

        return res;
    }
};
