
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || k <= 1) return head;

        ListNode *new_head = NULL;
        ListNode *begin = head;
        ListNode *end = head;
        ListNode *last_end = NULL;

        while (end != NULL) {
            cout << "begin=" << begin->val << ", end=" << end->val << endl;
            for (int i = 1; i < k; i++) {
                if (end == NULL) break;
                end = end->next;
            }
            if (end == NULL) break;

            //ListNode *end_next = end->next;
            ListNode *new_b = NULL, *new_e = NULL;
            reverseList(begin, end, &new_b, &new_e);

            if (new_head == NULL) new_head = new_b;
            if (last_end != NULL) last_end->next = new_b;

            last_end = new_e;
            begin = last_end->next;
            end = begin;
        }

        return new_head == NULL ? head : new_head;
    }

    void reverseList(ListNode *head, ListNode *tail,
                ListNode **new_b, ListNode **new_e) {
        if (head == tail) {
            *new_b = *new_e = head;
            return;
        }

        *new_e = head;
        *new_b = tail;
        ListNode *tail_next = tail->next;

        ListNode *cur = head;
        ListNode *next = cur->next;
        while (cur != tail) {
            ListNode *nn = next->next;
            next->next = cur;
            cur = next;
            next = nn;
        }
        head->next = tail_next;
        return;
    }
};
