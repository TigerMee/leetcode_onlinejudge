
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m >= n || m < 1) return head;

        ListNode *p = NULL;     // node before begin
        ListNode *b = head;
        ListNode *e = NULL;
        ListNode *en = NULL;    // node after end

        for (int i = 1; i < m; i++) {
            if (b == NULL) return head;
            if (p == NULL) p = b;
            else p = p->next;
            b = b->next;
        }
        e = b;
        for (int i = m; i < n; i++) {
            if (e == NULL) return head;
            e = e->next;
        }
        if (b == NULL || e == NULL) return head;
        en = e->next;

        ListNode *pre = p;
        ListNode *cur = b;    // n-m >= 1
        while (cur != en) {
            ListNode *tmp = cur;
            cur = cur->next;

            tmp->next = pre;

            pre = tmp;
        }

        if (p != NULL) {
            p->next = e;
        } else {
            head = e;
        }
        b->next = en;

        return head;
    }
};
