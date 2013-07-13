
#include "common.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *h = head;
        ListNode *n1 = h->next;
        ListNode *n2 = n1->next;

        n1->next = h;
        h->next = swapPairs(n2);

        return n1;
    }
};
