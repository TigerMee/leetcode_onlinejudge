
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return buildT(inorder, postorder,
                0, inorder.size()-1,
                0, postorder.size()-1);
    }

    // postorder: ---left---, ---right---, root
    // inorder: ---left---, root, ---right---
    // NOTE: You may assume that duplicates do not exist in the tree.
    //
    // begin: begin node in postorder
    // end: end node in postorder
    TreeNode *buildT(vector<int> &inorder, vector<int> &postorder,
                    size_t in_begin, size_t in_end,
                    size_t begin, size_t end) {
        if (begin > end
            || begin < 0
            || end >= postorder.size())
            return NULL;

        if (begin == end)
            return new TreeNode(postorder[begin]);

        int root_val = postorder[end];
        TreeNode *root = new TreeNode(root_val);

        // find left-tree end position in postorder, using inorder vector
        size_t root_in_pos = 0;
        for (size_t i = in_begin; i <= in_end; i++) {
            if (inorder[i] == root_val) {
                root_in_pos = i;
                break;
            }
        }

        TreeNode *left = NULL, *right = NULL;

        if (root_in_pos == in_end) {
            left = buildT(inorder, postorder, in_begin, in_end-1, begin, end-1);
        } else if (root_in_pos == in_begin) {
            right = buildT(inorder, postorder, in_begin+1, in_end, begin, end-1);
        } else {
            /*
            int right_min_val = inorder[root_in_pos+1];
            size_t right_post_begin = 0;
            for (size_t i = begin; i < end; i++) {
                if (postorder[i] == right_min_val) {
                    right_post_begin = i;
                    break;
                }
            }*/

            int right_post_begin = end-1;
            while (right_post_begin >= begin) {
                bool is_right = false;
                for (size_t i = root_in_pos+1; i <= in_end; i++) {
                    if (inorder[i] == postorder[right_post_begin]) {
                        is_right = true;
                        break;
                    }
                }
                if (!is_right)
                    break;
                right_post_begin--;
            }
            right_post_begin++;

            left = buildT(inorder, postorder, in_begin, root_in_pos-1, begin, right_post_begin-1);
            right = buildT(inorder, postorder, root_in_pos+1, in_end, right_post_begin, end-1);
        }

        root->left = left;
        root->right = right;
        return root;
    }
};
