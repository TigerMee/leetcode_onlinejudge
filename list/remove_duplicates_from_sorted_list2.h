
#include "common.h"

class Solution {
    public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *root = NULL;
        ListNode **pp_next = &root;
        ListNode *cur = head;

        while (cur != NULL) {
            if (cur->next == NULL || cur->val != cur->next->val) {
                if (*pp_next != cur)
                    *pp_next = cur;
                pp_next = &(cur->next);
                cur = cur->next;
            } else {
                int val = cur->val;
                do {
                    cur = cur->next;
                } while (cur != NULL && cur->val == val);
            }
        }
        *pp_next = NULL;
        return root;
    }
};


class Solution2 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return head;

        ListNode *new_head = NULL;
        ListNode *begin = head, *end = begin->next;
        ListNode *pre = NULL;

        while (end != NULL) {
            if (begin->val == end->val) { // remove 'begin' to 'end'
                if (end->next == NULL
                    || end->val != end->next->val) {
                    if (pre != NULL) {
                        pre->next = end->next;
                    }
                    begin = end->next;
                    end = begin == NULL ? NULL : begin->next;
                } else {
                    end = end->next;
                }
            } else {
                if (new_head == NULL)
                    new_head = begin;
                pre = begin;
                begin = begin->next;
                end = end->next;
            }
        }
        if (new_head == NULL)
            new_head = begin;

        return new_head;
    }
};


class Solution3 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL)
            return head;

        ListNode *new_head = NULL;
        ListNode *pre = NULL, *cur = head;
        bool in_dup = false;

        while (cur->next != NULL) {
            if (cur->val == cur->next->val) {
                if(!in_dup)
                    in_dup = true;
            } else {
                if (in_dup) {   // remove 'pre->next' to 'cur'
                    if (pre != NULL) {
                        pre->next = cur->next;
                    }
                    in_dup = false;
                } else {
                    pre = cur;
                    if (new_head == NULL)
                        new_head = cur;
                }
            }
            cur = cur->next;
        }
        if (in_dup) {
            if (pre != NULL)
                pre->next = NULL;
        } else {
            if (new_head == NULL)
                new_head = cur;
        }

        return new_head;
    }
};


