
#include "common.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n_num = 0;
        ListNode *cur = head;
        while (cur != NULL) {
            n_num++;
            cur = cur->next;
        }
        if (n_num == 0)
            return NULL;
        return buildBST(head, n_num);
    }

    TreeNode *buildBST(ListNode *begin, int num) {
        if (begin == NULL || num == 0)
            return NULL;

        int mid = num / 2 + 1;
        int n = 0;

        TreeNode *left = buildBST(begin, mid-1);

        // root
        for (int i = 1; i < mid; i++) {
            begin = begin->next;
        }
        TreeNode *root = new TreeNode(begin->val);

        // right
        begin = begin->next;
        TreeNode *right = buildBST(begin, num - mid);

        root->left = left;
        root->right = right;

        return root;
    }
};
