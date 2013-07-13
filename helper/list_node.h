
#ifndef _LIST_NODE_H_
#define _LIST_NODE_H_

// e.g.
// int arr[] = { 1, 2, 3, 4 };
// ListNode *t = build_list_node(arr, sizeof(arr)/sizeof(arr[0]));

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* build_list_node(int *arr, int size) {
    if (size == 0) {
        return NULL;
    }
    ListNode *res = new ListNode(arr[0]);
    ListNode *cur = res;

    for (int i = 1; i < size; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }

    return res;
}

void print_list(ListNode *n) {
    if (n == NULL) return;

    while (n != NULL) {
        cout << n->val << ",";
        n = n->next;
    }
    cout << endl;
    return;
}


#endif // _LIST_NODE_H_
