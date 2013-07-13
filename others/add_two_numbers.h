#ifndef _ADD_TWO_NUMBERS_H_
#define _ADD_TWO_NUMBERS_H_


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (l1 == NULL || l2 == NULL) {
            return NULL;
        }

        ListNode *res = NULL;
        ListNode *last_node = NULL;
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int val = (l1 != NULL ? l1->val : 0)
                    + (l2 != NULL ? l2->val : 0)
                    + carry;
            carry = val / 10;
            val = val % 10;

            ListNode *node = new ListNode(val);
            if (res == NULL) {
                res = last_node = node;
            } else {
                last_node->next = node;
                last_node = node;
            }

            l1 = l1 != NULL ? l1->next : l1;
            l2 = l2 != NULL ? l2->next : l2;
        }

        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            last_node->next = node;
            last_node = node;
        }

        return res;
    }
};

#endif // _ADD_TWO_NUMBERS_H_
