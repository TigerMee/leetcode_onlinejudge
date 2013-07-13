
#include "common.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *head = NULL;
        ListNode **pp_next = &head;

        ListNode *p_small = NULL;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                p_small = l1;
                l1 = l1->next;
            } else {
                p_small = l2;
                l2 = l2->next;
            }

            *pp_next = p_small;
            pp_next = &(p_small->next);
        }
        *pp_next = l1 == NULL ? l2 : l1;

        return head;
    }
};
