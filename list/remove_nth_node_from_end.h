
#include "common.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || n <= 0)
            return head;

        ListNode *before_n = NULL;
        int count = 0;

        for (ListNode *cur = head; cur != NULL; cur = cur->next) {
            if (++count == n + 1) {
                before_n = head;
            } else if (count > n + 1) {
                before_n = before_n->next;
            }
        }
        if (count < n)
            return head;

        ListNode *remove_node = NULL;
        if (before_n == NULL) { // delete head node.
            remove_node = head;
            head = head->next;
        } else {
            remove_node = before_n->next;
            if (before_n->next != NULL) {
                before_n->next = before_n->next->next;
            }
        }
        delete remove_node;
        remove_node = NULL;

        return head;
    }
};
