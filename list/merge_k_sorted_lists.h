
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.size() == 0) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }

        ListNode *l1 = lists.back();
        lists.pop_back();
        ListNode *l2 = lists.back();
        lists.pop_back();

        if (l1 == NULL && l2 == NULL) {
            return mergeKLists(lists);;
        } else if (l1 == NULL) {
            lists.push_back(l2);
            return mergeKLists(lists);;
        } else if (l2 == NULL) {
            lists.push_back(l1);
            return mergeKLists(lists);;
        }

        // merge sort;
        ListNode *cur1 = l1->val <= l2->val ? l1 : l2;
        ListNode *cur2 = cur1 == l1 ? l2 : l1;
        ListNode *res = cur1;

        while (cur1->next != NULL && cur2 != NULL) {
            if (cur1->next->val >= cur2->val) {
                ListNode *tmp = cur2->next;
                cur2->next = cur1->next;
                cur1->next = cur2;
                cur1 = cur1->next;
                cur2 = tmp;
            } else {
                cur1 = cur1->next;
            }
        }
        if (cur2 != NULL) {
            cur1->next = cur2;
        }

        lists.push_back(res);
        return mergeKLists(lists);
    }
};
