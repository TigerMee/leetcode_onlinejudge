
#include "common.h"

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || k == 0) {
            return head;
        }

        ListNode *new_head = NULL;
        ListNode *tail = NULL;
        ListNode *cur = head;
        ListNode *last = NULL;

        /*
        int count = 0;
        while (cur != NULL) {
            count++;
            cur = cur->next;
        }
        if (k % count != 0) k = k % count;

        cur = head;
        int step = 0;
        while (cur != NULL) {
            if ((++step) >= k) {
                if (new_head == NULL) new_head = head;
                else {
                    tail = new_head;
                    new_head = new_head->next;
                }
            }

            last = cur;
            cur = cur->next;
        }
        */

        for (int i = 1; i <= k || cur != NULL; i++) {
            if (i >= k) {
                if (new_head == NULL) new_head = head;
                else {
                    tail = new_head;
                    new_head = new_head->next;
                }
            }

            last = cur;
            if (cur->next == NULL && i < k)  cur = head;
            else cur = cur->next;
        }

        if (tail == NULL) return head;

        last->next = head;
        tail->next = NULL;

        return new_head;
    }
};
