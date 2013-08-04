
#include "common.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return head;
        }

        ListNode *new_head = NULL;
        ListNode *less = NULL;
        ListNode *cur = head;

        if (cur->val < x) {
            less = cur;
            new_head = less;
        }

        while (cur->next != NULL) {
            if (cur->next->val < x) {
                ListNode *next = cur->next->next;
                if (less == NULL) {
                    less = cur->next;
                    less->next = head;
                    new_head = less;
                    cur->next = next;
                } else {
                    if (less != cur) {
                        cur->next->next = less->next;
                        less->next = cur->next;
                        less = less->next;
                        cur->next = next;
                    } else {
                        less = less->next;
                        cur = cur->next;
                    }
                }
            } else {
                cur = cur->next;
            }
        }

        return new_head == NULL ? head : new_head;
    }
};
